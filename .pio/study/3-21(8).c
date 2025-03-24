//PWM설정 fast PWM, tiemr3, COM3A1 이용
//FND설정
//버저를 이용한 프로그램 
//버튼 인터럽트로 활성화 PE4, 5, 6, 7
//버튼에 맞는 소리를 2초간 출력, 2초간 무음
//FND에 버튼이 눌린 번호를 출력
//미완
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

uint16_t abcd[4] = {523, 587, 659, 698};
uint8_t piano = 0;
volatile uint8_t intData ='0';
volatile uint8_t numbers[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x27,0x7F,0x67};
volatile uint16_t rxData;
int i=0;
#define PWM_SETUP _BV(COM3A1) | _BV(COM3B1);


int main (void)
{
DDRE = 0x00;
DDRA = 0xFF;//FND설정
PORTA = numbers[0];

// Fast PWM 모드, 타이머3 사용, COM3A1 모드 설정
// 타이머3에서 Fast PWM 모드 활성화, TOP 값 0xFF
TCCR3A |= (1 << COM3A1) | (1 << WGM31);
TCCR3B |= (1 << WGM32) | (1 << WGM33) | (1 << CS30);  // Prescaler 1
ICR3 = 255;  // TOP값 설정 (PWM 주파수 결정)

// 인터럽트 활성화
EIMSK = 0xF0;
EICRB = 0xFF;
sei();



    if (condition)
    {
  
        ICR3 = 14745600 / abcd[piano]; // 주파수 만큼 duty cycle을 설정 하겠다.
        OCR3C = ICR3 / 2;                // 절반을 on 시키겠다.
        piano++;
        if (piano > 3)
            piano = 0;
        _delay_ms(2000);
    }
    return 0;
}



ISR(INT4_vect)
{
    i = 1;
    PORTA = numbers[i];
    _delay_ms(2000);
}

ISR(INT5_vect)
{
    i = 2;
    PORTA = numbers[i];
    _delay_ms(2000);
}

ISR(INT6_vect)
{
    i = 3;
    PORTA = numbers[i];
    _delay_ms(2000);   
}

ISR(INT7_vect)
{
    i = 4;
    PORTA = numbers[i];
    _delay_ms(2000);
}



