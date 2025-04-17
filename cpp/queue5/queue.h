#ifndef QUEUE_H
#define QUEUE_H
// #define QUEU
typedef struct queue
{
   //int *pArr;
   void *pArr;
   int elesize;
   int size;
   int front;
   int rear;
}Queue;

void initQueue(Queue *pq,int size,int elesize);
void cleanupQueue(Queue *pq);

void push(Queue *pq, const void *pData);
void pop(Queue *pq,void *pData);

#endif