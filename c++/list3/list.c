#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <assert.h>

// int *p 변수 강조
// int* p  인수 강조
// int * p  둘다

static Node* createNode(int data, Node *next)
{
    Node *p = malloc(sizeof(Node));
    assert(p !=NULL);
    p->data = data;
    p->next = next;

    return p;
}

void initlist(List *pList)
{
    // pList->ptr = malloc(sizeof(Node));  //dummy node
    // pList->ptr->data = ???;
    // pList->ptr->next = NULL;
    pList->ptr = createNode(-1,NULL);
}

void cleanuplist(List *pList)
{
    Node *p = pList->ptr;
    while (p != NULL)
    {
        Node *tmp = p;
        p = p->next;
        free(tmp);
    }
    
}

void insertFirstNode(List *pList,int data)
{
    // Node *p = malloc(sizeof(Node));
    // p->data = data;
    // p->next = pList->ptr->next;
    // pList->ptr->next = p;
    pList->ptr->next = createNode(data, pList->ptr->next);
}

void insertNode(List *pList, int prevData, int data)
{
    Node *p = pList->ptr->next;
    while (p != NULL)
    {
        if (p->data == prevData)
        {
            break;
        }
        p = p->next;
    }
    if (p != NULL)
    {
        // Node *tmp = malloc(sizeof(Node));
        // tmp->data = data;
        // tmp->next = p->next;
        // p->next = tmp;
        p->next = createNode(data, p->next);
    }
    // else
    // {
    //     //아무것도 안함
    // }
    
}

void deleteNode(List *pList, int data)
{
    Node *p = pList->ptr->next;
    Node *p2 = pList->ptr;
    while (p != NULL)
    {
        if (p->data == data)
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

void printList(const List *pList)
{
    Node *p = pList->ptr->next;
    printf("[");
    while (p != NULL)
    {
        printf("%d", p->data);
        printf( (p->next) ? ", " : "");
        p = p->next;
    }
    printf("]\n");
}
