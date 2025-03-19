// 채터링 error유발


#include <avr/io.h>
#include <util/delay.h>

int main()
{
    unsigned char switchFlag= 0;
    DDRC = 0x0F;
    PORTE = _BV(2) ; //풀업 설정

    while (1)
    {
        // if (PINE)
        // {
        //     switchFlag = PINE >> 2;
        // }
        // if (!(switchFlag & ))
        // {
        //     PORTC ^=0x01; // 1번 비트 반전
            
        // }
        PORTC ^= 0x01;
        _delay_ms(500);
        lcdGotoXY(0,0);
        lcdBuffer
    }
    
    return 0;
}