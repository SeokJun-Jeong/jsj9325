
#include "uart0.h"
#include <avr/interrupt.h>
#include <avr/io.h>



int main()
{
    uart0Init();
    stdin = &INPUT;
    stdout = &OUTPUT;

    unsigned char rxData;
    uint8_t numbers[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67};
    DDRA = 0xFF;

    printf("Hi, I'm Atmega128");
    fflush(stdin);
    while (1)
    {
        scanf("%c", &rxData);
        //rxData = uart0Receive();

        if ((rxData >= 0x30) && (rxData <= 0x39))
        {
            PORTA = numbers[rxData - 0x30];
        }
    }
    return 0;
}