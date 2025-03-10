// 10개의 랜덤한 0~100 배열을 만들고 가장 높은 값을 프린트 하세요.
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main(void)
{
    int max;
    int rn[10];
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 10; ++i)
    {
        rn[i] =rand() % 101;
        printf("%d , ",rn[i]);
    }
    printf("\n");
    max=rn[0];
    for (int i = 0; i < 10; ++i)
    {
        if(max < rn[i]) 
        max = rn[i];

    }
    printf("높은 값 : %d\n",max);
    return 0 ;
}