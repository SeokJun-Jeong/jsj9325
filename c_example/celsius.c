/*
this program is calculation demo program like int and float */



#include <stdio.h>

int main()
{
    int celsius;
    celsius = 14;
    printf("celsius temp: %d \n", celsius);

    double fahr;
    fahr = celsius * 9 /5 + 32;
    printf("fahr temp : %f \n",fahr);

    return 0;
}