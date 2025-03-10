// 두 난수를 발생시켜서 비교하기
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

int main(void)
{
    int a, b,i;
    double rand1, rand2;
    while (true)
    {
       
    
    i++;
    srand((unsigned int)time(NULL)); //랜덤 세팅
    rand1 = rand()/(double)RAND_MAX*100;

    srand((unsigned int)time(NULL)+i+10000); //랜덤 세팅
    rand2 = rand()/(double)RAND_MAX*100;

    a= rand1;
    b= rand2;

    printf("1~100사이의 랜덤한 숫자 : %f\n",rand1) ;
    printf("1~100사이의 랜덤한 숫자 : %f\n",rand2) ;
    printf("%d>%d:%s\n",a,b,a>b ? "true" : "false");
    printf("%d<%d:%s\n",a,b,a<b ? "true" : "false");
    printf("%d==%d:%s\n",a,b,a==b ? "true" : "false");
    printf("%d!=%d:%s\n",a,b,a!=b ? "true" : "false");
        if(a==b)
        break;
    }
    return 0 ;
}

