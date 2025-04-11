#ifndef STACK_H
#define STACK_H

struct Stack
{
   int *pArr;
   int size;
   int tos;

   // void initStack(int size);  stack 변환
   Stack(int size);  //constructor

   // void cleanupStack();  ~stack 변환
   ~Stack();         //destructor

   void push(int data);  
   int pop();
};


#endif