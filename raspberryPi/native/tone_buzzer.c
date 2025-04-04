//도레미 piezo로 음 내기
#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>
#include <softTone.h>


#define BUZZER_PIN 12

int doReMi[8] = {523,587,659,698,783,880,987,1046};

int main(void)
{
    wiringPiSetupGpio(); //BCM기준 gpio핀번호
    pinMode(BUZZER_PIN,OUTPUT);
 
    //set PWM
    softToneCreate(BUZZER_PIN);
    while(1)
    {   
        for (int i = 0; i < 8; ++i)
        {
            softToneWrite(BUZZER_PIN, doReMi[i]);
            delay(100);
        }   
    }
    return 0;
}