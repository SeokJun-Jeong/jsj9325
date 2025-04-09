#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void initStack(Stack *ps, int size)
{
	ps->pArr = malloc(sizeof(int) *size);
	//ps->pArr == NULL
	assert(ps->pArr != NULL);	   //NULL = 0
	
	ps->size = size;
    ps->tos = 0;
}

void cleanupStack(Stack *ps)
{
	free(ps->pArr);
}

void push(Stack *ps, int data)
{
    // When full
    //if (ps->tos == STACKSIZE) 대신
	// if(ps->tos == ps->size)
    // {
    //     fprintf(stderr, "Stack is full.\n");
    //     exit(1); // 프로그램 비정상 종료
    // }
	assert(ps->tos != ps->size);
	//ps->array[ps->tos] = data; 대신
	ps->pArr[ps->tos] = data;   // = *(ps->pArr + ps->tos) = data;
	++ps->tos;
}

int pop(Stack *ps)
{
    // When empty
    // if (ps->tos == 0)
    // {
    //     fprintf(stderr, "Stack is empty\n");
    //     exit(2);
    // }
    assert(ps->tos != 0);


	
	--ps->tos;
	//return ps->array[ps->tos];
	return ps->pArr[ps->tos];
}