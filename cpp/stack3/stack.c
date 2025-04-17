#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void initStack(Stack *ps)
{
    ps->tos = 0;
}

void push(Stack *ps, int data)
{
    // When full
    if (ps->tos == STACKSIZE)
    {
        fprintf(stderr, "Stack is full.\n");
        exit(1); // 프로그램 비정상 종료
    }
	//stack[tos] = data;
	//++tos;		불가능
	
	//s.array[s.tos] = data;
	//++s.tos;		불가능
	
	//(*ps).array[(*ps).tos] = data;
	//++(*ps).tos;			가능
	
	ps->array[ps->tos] = data;
	++ps->tos;
}

int pop(Stack *ps)
{
    // When empty
    if (ps->tos == 0)
    {
        fprintf(stderr, "Stack is empty\n");
        exit(2);
    }
    
	//--tos;
	//return stack[tos];	불가능
	
	//--s.tos;
	//return s.array[s.tos];	불가능
	
	//--(*ps).tos;
	//return (*ps).array[(*ps).tos];   가능
	
	--ps->tos;
	return ps->array[ps->tos];
}