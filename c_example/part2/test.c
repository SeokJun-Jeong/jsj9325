#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>


int main(void)
{
srand((unsigned int)time(NULL));
int num;
num = (rand() % 9) +1 ;
printf("%d",num) ;
return 0 ;
}
