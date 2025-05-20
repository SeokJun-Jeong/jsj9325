//up counter
#define F_CPU 16000000L //16megahz
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

volatile unsigned long milliseconds =0;

ISR(TIMER0_OVF_vect)
{
    ++milliseconds;
}


void timer0_init(void)
{
    TCCR0 = _BV(CS02) | _BV(CS01) | _BV(CS00);
    //TCNT0 = 6;
    TIMSK |= _BV(TOIE0);
    sei();
}

int main(void)
{
    timer0_init();
    uint8_t numbers[]
    ={0x3F, 0x06,0x5B,0x4F,0x66,0x6D,0x7d,0x27,0x7F,0x67};
    int count = 0;  //현재 표시할 숫자
    DDRA = 0xFF;    //제어 핀 8개를 출력으로 설정

    while (1)
    {
        if(milliseconds >= 62)
        {
        milliseconds = 0;
        count = (count + 1) % 10;   //다음에 표시할 숫자
        PORTA = numbers[count];     //숫자 데이터 출력
 
        }    
        
    }
    return 0;
}