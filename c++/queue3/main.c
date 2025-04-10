#include <stdio.h>
#include "queue.h"

int main(void)
{
   Queue q1,q2; 

   // q1.front = q1. rear = 0;  //지역변수 초기화 
   // q2.front = q2. rear = 0;

   initQueue(&q1);   //초기화
   initQueue(&q2);
   

   push(&q1,100);    
   push(&q1,200);
   push(&q1,300);
   
   printf("q1 1st pop(): %d\n",pop(&q1));
   printf("q1 2st pop(): %d\n",pop(&q1));
   printf("q1 3st pop(): %d\n",pop(&q1));

   push(&q2,900);
   push(&q2,800);
   push(&q2,700);

   printf("q2 1st pop(): %d\n",pop(&q2));
   printf("q2 2st pop(): %d\n",pop(&q2));
   printf("q2 3st pop(): %d\n",pop(&q2));

   
   return 0;
}