
#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t ledData = 0x00;
uint8_t timer0Cnt = 0;
ISR(TIMER0_OVF_vect);

int main(void)
{
    DDRC = 0x0F;

    TCCR0 = _BV(CS02) | _BV(CS01) |_BV(CS00) ;   //0x07;
    // TCNT0 = 112; 10ms
    TIMSK = 0x01; //timer interrupt en
    // TIFR |= _BV(TOV0); //없어도 됨

    sei();
    while (1)
    {
    if (timer0Cnt == 100)
    {
        ledData++;
        if (ledData > 0x0F)
        {
            ledData = 0;
        }
        timer0Cnt = 0;
    }    
        PORTC = ledData;
    }
    
}

ISR(TIMER0_OVF_vect)
{
    cli();
    TCNT0 = 112; // 113, 114, ... 255 .. 144 -> 0.0025초
    timer0Cnt++;
    sei();
}