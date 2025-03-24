//FND판에 카운트
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>

uint8_t numbers[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67};
volatile uint8_t timeS = 0x01;
volatile uint8_t findFlag = 0, edgeFlag = 0;

int main()
{

    DDRA = 0xFF;               //FND LED출력
    DDRE = 0x00;

    TCCR1A = 0x00;          
    TCCR1B = 0x05;             //분주비 1024

    OCR1A = 14400;             //1초
    TIMSK = 0x10;      //compare 인터럽트 enable
    // ETIFR |= _BV(ICF3);
    sei();                     //전역 인터럽트 허용
    PORTA = numbers[0];
    while (1)
    {
        PORTA = numbers[timeS];    
        if (timeS > 10)
        {
            timeS = 0;
        }
        
    }
    return 0;
}

ISR(TIMER1_COMPA_vect)
{
    cli();
    OCR1A += 14400;    //주석처리시 느려지고 잠깐 꺼지는 시간이 생김
    timeS++;
    sei();
}