//LED를 0.3초 간격으로 좌우로 움직이세요
//timer3을 써서 인터럽트로 구현하세요. 
//인터럽트가 0.3초 마다 일어나게 하세요.
//분주비는 256으로 쓰세요.
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>


volatile uint8_t ledData = 0x01;
volatile uint8_t direction =1;


int main(void)
{

    DDRC = 0x0F;            //1,2,3,4출력
    TCCR3A = 0x00;
    TCCR3B =  _BV(CS32);    //16,000,000/256 = 62500Hz 65536(초기값) - 62500 = 7036
    ETIMSK = _BV(TOIE3);    //TIMSK와 헷갈림 주의
    TCNT3 = 46786;          //시작 카운트 숫자
    sei();                  //전역 인터럽트 허용
    while (1)
    {
        PORTC = ledData; 
    }
    return 0;
}

ISR(TIMER3_OVF_vect)
{
    cli();
    TCNT3 = 46786;         
    if (ledData > 0x04)
        direction = 0;
    if (ledData == 1)
    {
        direction = 1;
        ledData = 1;
    }

    if (direction)
    {
        ledData <<= 1;
    }
    else
    {
        ledData >>= 1;
    }
    PORTC = ledData;
    sei();
}