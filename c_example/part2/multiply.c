#include<stdio.h>

int main(void)
{
    for(int i = 1; i <=9; ++i)  //단수 1단 ~ 9단 i
    {
        printf("-------%d단-------\n\n",i);
        for(int j =1; j <=9;++j) //1부터 9 까지 j
        {
            printf("%d X %d = %d\n", i, j, i*j);
        }
    }
    
    return 0 ;
}