//lcd판에 문자데이터 전송
#include "uart0.h"
#include <avr/interrupt.h>
#include <stdio.h>
#include <avr/io.h>
#include "lcd.h"



volatile uint8_t intData ='0';
uint8_t cursor = 0;

int main()
{
    lcdInit();
    uart0Init();
    stdin = &INPUT;
    stdout = &OUTPUT;

    DDRE = 0x02; //Rx(입력), Tx(출력)1, SW0~3입력
    
    EICRB = 0xFF; //4567상승 엣지에서 동작
    EIMSK = 0xF0; //4567허용
    EIFR = 0xF0;  //4567클리어

    sei(); //전역 인터럽트 허용
    char cData;


    printf("Hi, I'm Atmega128");

    while (1)
    {
         //rxData = uart0Receive();
        if (intData != '0')
        {
            printf("\n\r Input Switch : %c", intData);
            intData = '0';
        }
        cData = fgetc(stdin);
        lcdDataWrite(cData);
        cursor++ ;
        if (cursor == 16)
        {
            lcdGotoXY(0,1);
        }
        else if (cursor == 32)
        {
            cursor = 0;
            lcdGotoXY(0,0);   //초기화를 함 (안써도 됨)
        }
        
    }
    return 0;
}

ISR(INT4_vect)
{
    cli();
    intData = '1';
    sei();
}

ISR(INT5_vect)
{
    cli();
    intData = '2';
    sei();
}

ISR(INT6_vect)
{
    cli();
    intData = '3';
    sei();
}

ISR(INT7_vect)
{
    cli();
    intData = '4';
    sei();
}
