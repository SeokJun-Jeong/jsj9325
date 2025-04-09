//  -/ds/stack$ gedit stack.c

#include <stdio.h>
int stack[100];
int tos;    //top of stack


void push(int data)
{
   stack[tos] = data;
   ++tos;
}

int pop(void)  //re가 int기 때문에
{
   --tos;
   return stack[tos];
}


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






