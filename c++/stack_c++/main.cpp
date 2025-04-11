#include <stdio.h>
#include "stack.h"

int main()  //void 안 적어도 됨
{
   Stack s1,s2; 
   s1.initStack(10);  //object oriented형태
   s2.initStack(100);
   
   s1.push(100);    
   s1.push(200);
   s1.push(300);
   
   printf("s1 1st pop(): %d\n",s1.pop());
   printf("s1 2st pop(): %d\n",s1.pop());
   printf("s1 3st pop(): %d\n",s1.pop());
   
   
   s2.push(900);
   s2.push(800);
   s2.push(700);

   printf("s2 1st pop(): %d\n",s2.pop());
   printf("s2 2st pop(): %d\n",s2.pop());
   printf("s2 3st pop(): %d\n",s2.pop());
   

   s1.cleanupStack();
   s2.cleanupStack();
   return 0;
}

