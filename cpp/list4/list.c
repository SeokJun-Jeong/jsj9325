#include "list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>  //generic strcpy, strmem strset 때문에

void initList(List *pList, int eleSize) // 초기화
{
    pList->ptr = malloc(sizeof(Node) /*+ eleSize*/);
    // pList->ptr->data =
    pList->ptr->next = NULL;
    pList->eleSize = eleSize;
}

void cleanupList(List *pList) // malloc free
{
    Node *p = pList->ptr;
    while (p)
    {
        Node *tmp = p;
        p = p->next;
        free(tmp);
    }
}

void insertFirstNode(List *pList,const void *pData)
{
    Node *p = malloc(sizeof(Node)+pList->eleSize);
    // p->data = data;

    // memcpy((unsigned char *)p + sizeof(Node), pData, pList->eleSize);
    memcpy(p + 1, pData, pList->eleSize);
    
    p->next = pList->ptr->next;
    pList->ptr->next = p;
}

void insertNode(List *pList, const void *pPrevData, const void  *pData)
{
    Node *p = pList->ptr->next;
    while (p != NULL)
    {
        // if (p->data == prevData)
        if(memcmp(p+1, pPrevData, pList->eleSize) == 0)
        {
            break;
        }
        p = p->next;
    }
    if (p != NULL)
    {
        // Node *tmp = malloc(sizeof(Node));
        Node *tmp = malloc(sizeof(Node) + pList->eleSize);
        // tmp->data = data;
        memcpy(tmp + 1, pData, pList->eleSize);
        tmp->next = p->next;
        p->next = tmp;
    }
    // else
    // {
    //     //아무것도 안함
    // }
    
}

void deleteNode(List *pList, const void *pData)
{
    Node *p = pList->ptr->next;
    Node *p2 = pList->ptr;
    while (p != NULL)
    {
        // if (p->data == data)
        if(memcmp(p+1,pData,pList->eleSize) == 0)
        {
            break;
        }
        
        p = p->next;
        p2 = p2->next;
    }
    if (p != NULL)
    {
        p2->next = p->next;
        free(p);
    }
    // else
    // {
    //         //아무것도 안함
    // }
    
}

void printList(const List *pList, void(*print)(const void *))
{
    Node *p = pList->ptr->next;
    printf("[");
    while (p != NULL)
    {
        // printf("%d", p->data);
        print(p+1);

        printf( (p->next) ? ", " : "");
        p = p->next;
    }
    printf("]\n");
}