#ifndef STACK_H
#define STACK_H
//#define STACKSIZE 100

typedef struct stack
{
   //int array[STACKSIZE]; //=8,9번라인
   int *pArr;
   int size;
   int tos;
}Stack;//대문자s로 재정의

void initStack(Stack *ps, int size);
void cleanupStack(Stack *ps);

void push(Stack *ps, int data);
int pop(Stack *ps);

#endif