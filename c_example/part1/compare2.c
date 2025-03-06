// 1과 9사이의 숫자인지 확인해서 맞으면 1 틀리면 0을 프린트 하세요.

#include<stdio.h>

int main(void)
{
    int num;
    printf("숫자를 입력하세요 : ");
    scanf("%d" , &num);




    printf("1<= %d <= 9 : %d\n",num, 1<= num && num<= 9 );
    return 0 ;
}