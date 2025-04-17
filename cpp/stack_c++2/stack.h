#ifndef STACK_H
#define STACK_H

extern const int STACK_SIZE;

class Stack
{
private:  //implementation(내부구현)
   static const int STACK_SIZE;

   int *pArr_;
   int size_;
   int tos_;

   Stack::Stack(const Stack&); //not used
   Stack& operator=(const Stack&);  //not used
      
public:           //내부구현 접근
  
   //Stack(const Stack& ) { */memberwise copy */ }
   //~Stack() {}
   //Stack& operator=(const Stack& ) { /* memberwise copty */ return this;}
   //Stack *operator&() {return this;}
   // const Stack *operator&() const { return this;}

   // static int getDefaultStackSize();
   //Stack() {}
   explicit Stack(int size =100);  
   ~Stack();         

   Stack(const int *pArr, int size);
   Stack(const Stack& rhs);

   // Stack& operator=(const Stack& rhs);
   
   // bool operator==(const Stack& rhs) const;

   // int& operator[](int index);
   // const int& operator[](int index) const;

   int size() const;
   int remain() const;

   bool isEmpty() const;
   bool isFull() const;
   
   void push(int data);  
   int pop();
};


#endif