//SHT 5초마다 한번씩 온습도 측정 - timer0 활용
//SHT에서 측정 실패시 ERROR 성공시 EEPROM에 저장
//INT4번 써서(스위치 누르면) EEPROM에 데이터를 읽어 UART로 출력
//외부EEPROM의 주소는 0100 > 온도, 0200 >습도


#include "SHT2x.h"
#include "at25160.h"
#include "uart0.h"
#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t readFlag = 1, txFlag = 0;   //5초마다 한번씩 읽기, 한번씩 전송
uint16_t timerCount = 0;   //5초를 맞추기위한 타이머/카운트
uint16_t temperatureC, humidityRH;   //온도와 습도


// unsigned char switchFlag = 0;
// PORTE = 0x01; // 풀업 설정
// void printf_2dot1(uint8_t sense, uint16_t sense_temp);
// ISR(TIMER0_OVF_vect);
// uint8_t msg1[];
// uint8_t msg2[];

int main(void)
{
    
    SPI_Init(); //at25160.h
    SHT2x_Init();
    uart0Init();
    Init_TWI();

    DDRE = _BV(PE1); //0x02;  UART통신

    //interrupt 4번 설정
    EICRB = 0x03 // int 4 상승엣지
    EIMSK = 0x10;  //4번 비트

    TCCR0 = 0x07;   //1024분주비 (5초)
    TCNT0 = 112;    //144세기 16m/1024/? = 0.1sec
    TIMSK = 0x01;   //timer0_ovf enable
    sei();

    while (1)
    {
        if (readFlag)
        {
            //i2c temp read > spi eeprom write
            SHT2x_MeasureHM(TEMP, (nt16 *)&temperatureC);
            SHT2x_MeasureHM(HUMIDITY, (nt16 *) &humidityRH);
            temperatureC = SHT2x_CalcTemperatureC(temperatureC);
            humidityRH = SHT2x_CalcRH(humidityRH);
            at25160_Write_Arry(0x0100, (uint8_t*)&temperatureC, 2);   //주소 100에 온도
            at25160_Write_Arry(0x0200, (uint8_t*)&humidityRH, 2);     //주소 200에 습도
            readFlag = 0;
        }
        if (txFlag)
        {
            //eeprom read > uart printf();
            at25160_Read_Arry(0x0100,(uint8_t *)&temperatureC,2);
            at25160_Read_Arry(0x0100,(uint8_t *)&humidityRH,2);
            uart0PrintString("\n\rTemp: ");
            printf("%u,%u",temperatureC / 10, temperatureC % 10);         //소수점포함    
            uart0PrintString("\n\rHumi: ");
            printf("%u,%u",humidityRH / 10, humidityRH % 10);         //소수점포함    
            txFlag = 0;
        }
        
    }
    return 0;
    
}    


ISR(TIMER0_OVF_vect)
{
    timerCount++;
    if (timerCount >= 500) //5초 확인시 
    {
        timerCount = 0;
        readFlag = 1;    //읽기 확인
    }
    TCNT0 = 112;
}
ISR(INT4_vect)