#include<stdio.h>
#include<stdbool.h>

// 1~10까지 while로 출력하기


int main(void)
{
    int i = 0;
    do
   
    {
        
        printf("%d 번 출력입니다.\n",i+1);
        ++i;
        
        
    }while(i<10);
    
    return 0 ;
}