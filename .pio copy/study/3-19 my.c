//인터럽트로 FND를 점멸
//INT5  phase 1 > phase 2 or phase 2 > phase 1
//phase 1: FND가 빠르게 상승하는 코드 delay 100
//phase 2: FND를 순간 멈추게 함

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint8_t shiftFlag =1; //인터럽트에서 쓸 변수 
uint8_t buttonState =1;
uint8_t lastButtonstate = 1;

void phase_change()
{uint8_t reading = PINE & _BV(PE0);

            //실제 버튼 상태 업데이트
            if (reading != buttonState)
            {
                buttonState =reading;

                 // 버튼이 눌렸을 때 동작 수행 (버튼이 눌리면 shiftFlag 변경)
        if (buttonState == 0 && lastButtonstate == 1) 
        { // 버튼 눌림 상태에서만
            _delay_ms(100);  // 버튼 상태 안정화 대기

            // 버튼 눌림 상태에 따라 shiftFlag를 변경
            if (shiftFlag == 1) {
                shiftFlag = 2;  // shiftFlag를 2로 변경
            } else {
                shiftFlag = 1;  // shiftFlag를 1로 변경
            }
        }
            }
}



int main()
{
    uint8_t ledData = 0x01;
   
    DDRC = 0x0F; //하위비트 4개 출력
    EIMSK = 0xA0; // 0b10100000   INT 5, INT 7
    EICRB = 0xC8; //인터럽트 5는 하강, 인터럽트 7은 상승
    // EICRB = _BV(ISC71) | _BV(ISC70) | _BV(ISC51);
    EIFR = 0xA0; //플래그 클리어
    sei();

    while (1)
    {
        PORTC = ledData;
        if (shiftFlag == 1)
        {
            if (ledData == 0x08)
            {
                ledData = 0x01;
            }
            else
            {
                ledData <<= 1;
            }
            
        }
        else if (shiftFlag ==2)
        {
            if (ledData == 0x01)
            {
                ledData = 0x08;
            }
            else
            {
                ledData >>= 1;
            }
        }
        _delay_ms(100);
    }

    return 0;
}


ISR(INT5_vect)
{
    cli();  //sei()와 반대 설정 SREG -> I unset -> 0
    shiftFlag = 1;
    sei();
}

ISR(INT7_vect)
{
    cli();
    shiftFlag = 2;
    sei();
}

