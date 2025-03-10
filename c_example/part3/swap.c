#include<stdio.h>

int main(void)
{
    int a, b, swap ;
    a=10;
    b=20;

    //swap
    swap = a;
    a=b;
    b=swap;
    
    printf("a=%d, b=%d",a,b);
    return 0 ;
}