// 배열을 int로 만들어서 랜덤(0~100) 합을 구해서 프린트하기

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
    int rd[10];
    int sum = 0;
    srand(time(NULL));
    for (int i = 0; i < 10; ++i)
    {
        rd[i] =rand() % 101;

    }
    printf("\n");

    for (int i = 0; i < 10; ++i)
    {
        sum += rd[i];
        printf("%d ",rd[i]);
    }
    printf("10개의 배열의 총합은 %d이다.\n",sum);

    return 0 ;
    
}