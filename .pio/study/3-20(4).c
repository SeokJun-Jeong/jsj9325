//cds에 불빛의 세기를 LCD판에 입력
//uart를 이용해서 시리얼 통신으로 센서 값을 0.1초 간격으로 출력 가능 추가하세요.
// --> CDS ADC_data : xxxx (20일 2번 참조 하면 될듯)
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

    ADMUX = 0x40; //ADC0 single mode, 0번 채널, 3.3V 외부 기준 전압 (AREF)
    ADCSR = 0xAF;  // 10101111 ADC허가, free running mode, Intterupt en, 128분 주비

    ADCSRA |= 0x40; //ADC개시
    sei(); //전역 인터럽트 허용
    printf("Hi, I'm Atmega128");

    lcdGotoXY(0,0);
    lcdPrintData("Light Sensor",12);
    char buf[16];
    while (1)
    {
        lcdGotoXY(0,1);
        sprintf(buf,"L: %u",adcResult); //LCD판에 출력
        lcdPrintData(buf,strlen(buf));
        printf("Light Level: %u\n",adcResult); //serial monitor에 출력
        _delay_ms(200);
    }
    return 0;
}

ISR(ADC_vect)
{
    cli();
    adcResult = ADC;   //2^16 0~1023
    sei();
}

