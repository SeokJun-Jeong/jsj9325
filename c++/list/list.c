//linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;


int main(void)
{
    //definition(정의)
    Node *ptr;
    ptr = malloc(sizeof(Node));
    ptr->data = 1;
    ptr->next = malloc(sizeof(Node));
    ptr->next->data = 3;
    ptr->next->next = malloc(sizeof(Node));
    ptr->next->next->data = 4;
    ptr->next->next->next = NULL;   //끝을 나타냄

    //insert2(삽입)
    {
        Node *p = malloc(sizeof(Node));
        p->data = 2;
        p->next = ptr->next;
        ptr->next = p;
    }

    //delete3(삭제)
    {
        Node *p = ptr->next->next;
        ptr->next->next = p->next;   //ptr->next->next = ptr->next->next->next
        free(p);
    }


    //traversal(순회)
    {
        Node *p = ptr;
        printf("[");
        while (p != NULL)
        {
            printf("%d",p->data);
            printf((p->next)? ", " : "");
            // if (p->next != NULL)
            // {
            //     printf(", ");
            // }
            
            p = p->next;
        }
        printf("]\n");
    }

    //free(데이터삭제)
    {
        Node *p = ptr;
        while (p )
        {
            Node *tmp = p;
            p = p->next;
            free(tmp);
        }
        
    }
    return 0;
}