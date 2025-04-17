#ifndef STACK_H
#define STACK_H
//#define STACKSIZE 100

typedef struct stack
{
   // int *pArr;
   void *pArr;   //시작주소
   int eleSize;  //bytesize구하기위해
   int size;
   int tos;
}Stack;//대문자s로 재정의

void initStack(Stack *ps, int size, int eleSize);
void cleanupStack(Stack *ps);

void push(Stack *ps, const void *pData);
void pop(Stack *ps,void *pData);

#endif