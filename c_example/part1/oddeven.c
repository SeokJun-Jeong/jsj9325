//짝수 홀수 구별하기 짝수면 0 홀수면 1
#include <stdio.h>

int main(void)
{
    int num;
    printf("숫자를 넣으세요 : ");
    scanf("%d",&num);

    int isodd;
    isodd = (num % 2 == 1);

    printf("num %d \t isodd : %d\n", num, isodd);
    return 0 ;

}