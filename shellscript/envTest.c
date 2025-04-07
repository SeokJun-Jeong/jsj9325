// cc -o envTest envTest.c
#include <dotenv.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("age : %s\n",getenv("age"));
    printf("name : %s\n",getenv("name"));
    return 0;
}