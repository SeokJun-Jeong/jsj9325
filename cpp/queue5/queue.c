#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include <assert.h>
#include <string.h>
void initQueue(Queue *pq,int size, int elesize)   //초기화
{
    pq->elesize = elesize;
    pq->pArr = malloc(sizeof(int) * size);
    //pq->pArr != NULL;
    pq->size = size;
    pq->rear = 0;
    pq->front = 0;
}

void cleanupQueue(Queue *pq)
{
    free(pq->pArr);
}

void push(Queue *pq, const void *pData)
{
    assert(pq->rear != pq->size);   
    
    //pq->pArr[pq->rear] = data;
    //memcpy(&pq->pArr[pq->rear], pData, pq->elesize);
    memcpy((unsigned char*)pq->pArr + pq->rear * pq->elesize,pData, pq->elesize);
	++pq->rear;
}

void pop(Queue *pq,void *pData)
{
    
    assert(pq->rear != pq->front);

    int i = pq->front;
	++pq->front;

	//return pq->pArr[i];
    //memcpy(pData,&pq->pArr[i],pq->elesize);
    memcpy(pData, (unsigned char *)pq->pArr + i * pq->elesize, pq->elesize);
}