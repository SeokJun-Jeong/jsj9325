//at25160.h를 이용해 LCD판에 글자 작성  (SPI)  (EEPROM사용)
#include <avr/io.h>
#include <avr/delay.h>
#include "lcd.h"
#include "at25160.h"

#define ARRA_SIZE(array) (sizeof(array))/ sizeof(array[0])

uint8_t msg1[] = "welcome";
uint8_t msg2[] = "atmega128-wolrd";
uint8_t msg3[] = "SPI-Flash Example";

int main(void)
{
    uint8_t i = 0;
    uint8_t buf1[20] = {0};
    uint8_t buf2[20] = {0};
    uint8_t buf3[20] = {0};
    SPI_Init(); //PB0 1 2 3         SPI
   lcdInit();   //PC4 5 6 7 PG2     TCLD
   
   at25160_Write_Arry(0x0100, msg1, ARRA_SIZE(msg1));
   at25160_Write_Arry(0x0200, msg2, ARRA_SIZE(msg2));
   at25160_Write_Arry(0x0300, msg3, ARRA_SIZE(msg3));
   
   at25160_Read_Arry(0x0100, buf1, ARRA_SIZE(buf1));
   at25160_Read_Arry(0x0200, buf2, ARRA_SIZE(buf2));
   at25160_Read_Arry(0x0300, buf3, ARRA_SIZE(buf3));

   
   
   while (1)
    {
        lcdGotoXY(0,0);
        for (i=0; i < ARRA_SIZE(msg1) - 1; i++)
        {
            lcdDataWrite(buf1[i]);
            _delay_ms(100);
        }
        i = 0;
        lcdGotoXY(0,1);
        while (msg2[i])
        {
            lcdDataWrite(buf2[i]);
            ++i;            
            _delay_ms(100);
        }
        lcdGotoXY(0,0);
        lcdPrint(buf3);
        _delay_ms(2000);
        lcdClear();
    }


   
    return 0;
}


-----------------------------------------------------
//EEPROM에 저장되 있어서 그대로 나옴
#include <avr/io.h>
#include <avr/delay.h>
#include "lcd.h"
#include "at25160.h"

#define ARRA_SIZE(array) (sizeof(array))/ sizeof(array[0])



int main(void)
{
    uint8_t i = 0;
    uint8_t buf1[20] = {0};
    uint8_t buf2[20] = {0};
    uint8_t buf3[20] = {0};
    SPI_Init(); //PB0 1 2 3         SPI
   lcdInit();   //PC4 5 6 7 PG2     TCLD
   

   at25160_Read_Arry(0x0100, buf1, ARRA_SIZE(buf1));
   at25160_Read_Arry(0x0200, buf2, ARRA_SIZE(buf2));
   at25160_Read_Arry(0x0300, buf3, ARRA_SIZE(buf3));

   
   
   while (1)
    {
        lcdGotoXY(0,0);
        for (i=0; i < 10 - 1; i++)
        {
            lcdDataWrite(buf1[i]);
            _delay_ms(100);
        }
        i = 0;
        lcdGotoXY(0,1);
        while (buf2[i])
        {
            lcdDataWrite(buf2[i]);
            ++i;            
            _delay_ms(100);
        }
        lcdGotoXY(0,0);
        lcdPrint(buf3);
        _delay_ms(2000);
        lcdClear();
    }


   
    return 0;
}