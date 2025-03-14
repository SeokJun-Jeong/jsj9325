#include <stdio.h>

enum season
{
    SPRING =1, //int -> 0
    SUMMER =2, //int -> 1
    FALL=4,   //int -> 2
    WINTER=8  //int -> 3
};  //열거형 선언 =
// #define SPRING 0
// #define SUMMER 1
// #define FALL   2
// #define WINTER 3

// ss = SPRING | SUMMER; 2진법사용

int main(void)
{
    enum season ss;
    char *pc = NULL;

    ss = FALL;
    switch (ss)  //int
    {
    case SPRING: //가시성을 위해
        pc = "inline";
        break;

    case SUMMER:
        pc = "swimming";
         break;
    case FALL:
        pc = "trip";
        break;
    case WINTER:
        pc = "skiing";
        break;
    }
    printf("나의 레저 활동 => %s\n", pc);

    return 0;
}