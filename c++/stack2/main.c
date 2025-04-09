//gcc -o testStack stack.c <testStack파일 생성
#include <stdio.h>
#include "stack.h"	//전처리 지시자


int main(void)
{	
   push(100);
   push(200);
   push(300);
   
   int re = pop();  
   printf("1st pop(): %d\n",re);
   re = pop();
   printf("2st pop(): %d\n",re);
   re = pop();
   printf("3st pop(): %d\n",re);
   
   return 0;
}






