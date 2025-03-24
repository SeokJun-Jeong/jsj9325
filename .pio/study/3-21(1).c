
#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t ledData = 0x00;
volatile uint8_t timer1Cnt = 0;
ISR(TIMER1_OVF_vect);

int main(void)
{
    DDRC = 0x0F; //1,2,3,4출력
    TCCR1A = 0x00; 
    TCCR1B = 0x01;

    TIMSK = 0x04;
    
    sei();  //전역 인터럽트 허용
    while (1)
    {
        if (timer1Cnt == 244)
        {
            ledData++;
            if (ledData > 0x0F)
                {
                ledData = 0;
                }
            timer1Cnt = 0;
        }
        
        PORTC = ledData;
    }
    

    return 0;
}

ISR(TIMER1_OVF_vect)
{
    cli();
    timer1Cnt++;
}