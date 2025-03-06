#include<stdio.h>

int main(void)
{
    int a,b;
    printf("Input a, b : ");
    scanf("%d %d", &a, &b);

    printf("plus %d + %d = %d\n", a, b, a+b);
    printf("minus %d - %d = %d\n", a, b, a-b);
    printf("multiply %d * %d = %d\n", a, b, a*b);
    printf("division %d / %d = %d\n", a, b, a/b);
    printf("나머지 %d + %d = %d\n", a, b, a%b);
  
    return 0;
}