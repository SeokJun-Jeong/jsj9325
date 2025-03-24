//DC모터 PWM제어
#include <avr/io.h>
#include <avr/delay.h>
#include "lcd.h"

int main(void)
{
    uint8_t pwmDuty = 60, cntDir = 0;
   DDRD = _BV(PD4) | _BV(PD5);  //출력 설정
   DDRB = _BV(PB5) ;            //M1 enable핀
    
   TCCR1A = _BV(COM1A1) | _BV(WGM11);
   TCCR1B = _BV(CS11) | _BV (WGM12) | _BV (WGM13);  //fast pwm분주비 8 > 16MHz/ 8 = 2MHz


   ICR1 = 800;          // 2MHz :1초 == 800Hz : 1초 ... 2500Hz
   OCR1A = 8* pwmDuty;  // 800까지 카운터를 하는데 560번까지는 5v(70%)

   lcdInit();
   lcdGotoXY(0,0);
   lcdPrintData(" Duty: ", 7);

   PORTD |= _BV(PD4);      // M1 정회전  
   PORTB |= _BV(PB5);      // M1 회전 가능
   
   while (1)
   {
       if (cntDir)
       {
            pwmDuty = pwmDuty - 5;
            if (pwmDuty < 10)
            {
                cntDir = 0;
            }
            
       }
       else
       {
            pwmDuty =pwmDuty + 5; 
            if (pwmDuty > 99)
            {
                cntDir = 1;
            }
            
       }

       OCR1A = 8 * pwmDuty;    // 0~100
       pwmDuty++;
       lcdGotoXY(7,0);
       lcdDataWrite((pwmDuty/10)%10+'0');
       lcdDataWrite((pwmDuty)%10+'0');
       lcdDataWrite('%');
       // _delay_ms(500);
        // PORTD &= ~_BV(PD4);     //0bXXX1XXXX  -> & (0b 11101111)
        // PORTD |= _BV(PD5);      // M1 역회전 - 속도 영향 
        // PORTB |= _BV(PB5);      // M1 회전 가능
        // _delay_ms(500);
   }
   
    return 0;
}