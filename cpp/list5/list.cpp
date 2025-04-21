#include <stdlib.h>
#include "list.h"
#include <cassert>

// int *p 변수 강조
// int* p  인수 강조
// int * p  둘다

// void list::printList(const List *pList)

std::ostream& operator<<(std::ostream& out, const list& rhs)
{
    Node *p = rhs.ptr->next;
    out << "[";
    while (p != NULL)
    {
        out << p->data;
        out << ((p->next ) ? ", " : "");
        p = p->next;
    }
    out << "]";

    return out;
}

// static Node* createNode(int data, Node *next)
// {
//     Node *p = malloc(sizeof(Node));
//     assert(p !=NULL);
//     p->data = data;
//     p->next = next;

//     return p;
// }

// void initlist(list *pList)
// {
//     // pList->ptr = malloc(sizeof(Node));  //dummy node
//     // pList->ptr->data = ???;
//     // pList->ptr->next = NULL;
//     pList->ptr = createNode(-1,NULL);
// }

// void list::cleanuplist()
// {
//     Node *p = pList->ptr;
//     while (p != NULL)
//     {
//         Node *tmp = p;
//         p = p->next;
//         free(tmp);
//     }
    
// }

void list::insertFirstNode(int data)
{
    // Node *p = malloc(sizeof(Node));
    // p->data = data;
    // p->next = pList->ptr->next;
    // pList->ptr->next = p;
    pList->ptr->next = createNode(data, pList->ptr->next);
}

void list::insertNode(int prevData, int data)
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

void list::deleteNode(int data)
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


