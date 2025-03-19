//up counter
#define F_CPU 16000000L //16megahz
#include <avr/io.h>
#include <util/delay.h>

int count_TR(uint8_t flag);



int main(void)
{

    uint8_t numbers[] = {0x3F, 0x06,0x5B,0x4F,0x66,0x6D,0x7d,0x27,0x7F,0x67};

    int count = 0;  //현재 표시할 숫자

    uint8_t switch_flag =0;

    DDRA = 0xFF;    //제어 핀 8개를 출력으로 설정
    DDRE = 0x00;

    while (1)
    {
        switch_flag = PINE >>4;
        
        //스위치가 눌릴 때 까지 대기
        while (PINE >> 4 !=0x00)
            ;
        
            if (switch_flag != 0)
            {
                count += count_TR(switch_flag);
            }
            
            if (count < 0)
            {
                count = 0;
            }
            else if (count >10)
            {
                count = 10;
            }

            PORTA = numbers [count];
            _delay_ms(100);
        
    }
    return 0;
}

int count_TR(uint8_t flag)
{
    int count = 0;
    switch (flag)
    {
    case 0x01:
        count = 1;
        break;
    case 0x02:
        count = 2;
        break;
    case 0x04:
        count = -1;
        break;
    case 0x08:
        count = -2;
        break;
    }
    return count;
}