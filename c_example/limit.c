#include <stdio.h>
#include <limits.h>

void printhello();

int main(void) 
{
    int re = printhello();
    printf("char_bit : %d\n",CHAR_BIT);
    printf("char_max : %d\n",CHAR_MAX);
    return 0;   
}

void printhello()
{
    printf("hello, world\n") ;
    return 0;
}