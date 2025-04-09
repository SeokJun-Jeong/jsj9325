#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void initStack(Stack *ps, int size, int eleSize)
{
	//ps->pArr = malloc(sizeof(int) *size);
	ps->pArr = malloc(eleSize * size);
	assert(ps->pArr /*!= NULL*/);	   //NULL = 0
	ps->eleSize = eleSize;
	ps->size = size;
    ps->tos = 0;
}

void cleanupStack(Stack *ps)
{
	free(ps->pArr);
}

void push(Stack *ps, const void *pData)
{

	assert(ps->tos != ps->size);
	
    //memcpy(&ps->pArr[ps->tos],pData, ps->eleSize);   //역참조가 되지 않기에 x 
    memcpy((unsigned char *)ps->pArr + ps->tos * ps->eleSize,pData, ps->eleSize);
	++ps->tos;
}

void pop(Stack *ps,void *pData)
{

    assert(ps->tos != 0);
    
	--ps->tos;
	
    // memcpy(pData,&ps->pArr[ps->tos],ps->eleSize);
    memcpy(pData, (unsigned char *)ps->pArr + ps->tos * ps->eleSize, ps->eleSize);
}

