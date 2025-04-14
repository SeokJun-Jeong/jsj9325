#ifndef STACK_H
#define STACK_H

class Stack
{
   private:  //implementation(내부구현)
   int *pArr;
   int size;
   int tos;

   public:           //내부구현 접근
   // void initStack(int size);  stack 변환
   Stack(int size);  //constructor

   // void cleanupStack();  ~stack 변환
   ~Stack();         //destructor

   void push(int data);  
   int pop();
};


#endif