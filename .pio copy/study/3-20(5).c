// 불빛의 세기에 따라 불빛의 on/off를 다르게 하고 lcd와 serial moniotr에 세기 출력
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdio.h>
#include <string.h>
#include <util/delay.h>
#include "uart0.h"
#include "lcd.h"


volatile uint16_t adcResult = 0;

int main()
{
    lcdInit();
    uart0Init();

    stdin = &INPUT;
    stdout = &OUTPUT;

    DDRC = 0x0F; // 1,2,3,4출력 설정
    

    ADMUX = 0x40; //ADC0 single mode, 0번 채널, 3.3V 외부 기준 전압 (AREF)
    ADCSR = 0xAF;  // 10101111 ADC허가, free running mode, Intterupt en, 128분 주비

    ADCSRA |= 0x40; //ADC개시
    sei(); //전역 인터럽트 허용
    printf("Hi, I'm Atmega128");

    lcdGotoXY(0,0);
    lcdPrintData("Light Sensor",12);
    char buf[16];
    uint8_t onTime, offTime;
    while (1)
    {
        lcdGotoXY(0,1);
        sprintf(buf,"L: %u",adcResult); //LCD판에 출력
        lcdPrintData(buf,strlen(buf));
        printf("Light Level: %u\r\n",adcResult); //serial monitor에 출력
        //시간 연산
        onTime = (adcResult-100)/35;
        if (onTime < 0)
        {
            onTime = 0;
        }
        if (onTime > 20)
        {
            onTime = 20;
        }
        offTime = 20 - onTime;
        PORTC = 0x0F;
        //켜지는 시간 딜레이
        for (int i = 0; i < onTime; ++i)
        {
            _delay_ms(100);
        }
        PORTC  =0x00;
        //꺼지는 시간 딜레이
        for (int i = 0; i < offTime; ++i)
        {
            _delay_ms(100);
        }
        

        
    }
    return 0;
}

ISR(ADC_vect)
{
    cli();
    adcResult = ADC;   //2^16 0~1023
    sei();
}

