//int stack[100];
//int tos;

//int stack2[100]
//int tos2;

//int stack3[100]
//int tos3;    


//void push(int data)
//{

//}

//int pop(void)
//{

//}

//void push2(int data)
//{

//}

//int pop2(void)
//{

//}

//void push3(int data)
//{

//}

//int pop3(void)
//{

//}  간단하게 사용하기 위해 구조체 사용
#include <stdio.h>
#include "stack.h"


int main(void)
{
   Stack s1,s2; 
   //struct stack stacks[10];

   //s1.tos = 0;
   //s2.tos = 0;

   initStack(&s1);
   initStack(&s2);
   
   push(&s1,100);    //구조체 자료는 인자를 줄이기 위해 오버헤드 사용
   push(&s1,200);
   push(&s1,300);
   
   printf("s1 1st pop(): %d\n",pop(&s1));
   printf("s1 2st pop(): %d\n",pop(&s1));
   printf("s1 3st pop(): %d\n",pop(&s1));
   
   push(&s2,900);
   push(&s2,800);
   push(&s2,700);

   printf("s2 1st pop(): %d\n",pop(&s2));
   printf("s2 2st pop(): %d\n",pop(&s2));
   printf("s2 3st pop(): %d\n",pop(&s2));
   
   pop(&s1);

   
   return 0;
}

