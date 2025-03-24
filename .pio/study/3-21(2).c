// 불빛이 숫자순서가 2진수대로 나옴
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>
volatile uint8_t ledData = 0x00;
volatile uint8_t timer1Cnt = 0;
ISR(TIMER1_OVF_vect);

int main(void)
{
    DDRC = 0x0F; //1,2,3,4출력
    TCNT1 = 49910;
    TCCR1A = 0x00; 
    TCCR1B = _BV(CS10) | _BV(CS12);   //분주비 1 16Mhz 16000000/ 65536 = 244.144Hz
    //분주비 1024 16Mhz

    TIMSK = _BV(TOIE1);
    
    sei();  //전역 인터럽트 허용
    while (1)
    {
        _delay_ms(200);
    }
    

    return 0;
}

ISR(TIMER1_OVF_vect)
{
    cli();
    TCNT1 = 49910;
    PORTC = ledData;
    ledData++;
    if (ledData > 0x0F)
    {
        ledData = 0;
    }
    sei();
}