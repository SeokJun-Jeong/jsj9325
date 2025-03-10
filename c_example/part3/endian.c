//BigEndian   LittleEndian
#include<stdio.h>

int main(void)
{
    int a = 0x12345678;
    char *pA;
    pA = (char *)&a;
    printf("*pA : 0x%x\n", *pA);
    //78이 나오면 BigEndian 12가 나오면 LittleEndian
    return 0 ;
}