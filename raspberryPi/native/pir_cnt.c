// 스위치 1,2,3 을 이용해서
// 1-> R 색 변화
// 2-> G 색 변화
// 3-> B 색 변화
// 스위치를 오래 누르면(0 ~ 1 초)-> (0~4095) 높은 값으로 변화 할 수 있게 만들기

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

#define PIR_PIN 7
#define LED1_PIN 23



// void SW_ISR1(void);


int main(void)
{
    wiringPiSetupGpio(); //BCM기준 gpio핀번호
    // wiringPiISR(PIR_PIN, INT_EDGE_SETUP,SW_ISR1);
    
    pinMode(LED1_PIN,OUTPUT);
    pinMode(PIR_PIN, INPUT);
    while (1)   
    {
        if(digitalRead(PIR_PIN) == HIGH)
        {
            printf("PIR 감지\n");
        }
        delay(100);
    }


    return 0;
}


// void SW_ISR1R(void)
// {
//     printf("PIR ON\n");
//     digitalWrite(LED1_PIN,HIGH);
//     delay(300);
//     digitalWrite(LED1_PIN,LOW);
    
// }
