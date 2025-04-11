//정수형 실수형 linked list
#include "list.h"
#include <stdio.h>


void printInt(const void *pData)
{
    printf("%d",*(int *)pData);

}


void printDouble(const void *pData)
{
    printf("%f",*(double *)pData);

}

int main(void)
{
    List list, list2;
    initlist(&list,sizeof(int));
    initlist(&list2,sizeof(double));

    int i = 4;
    insertFirstNode(&list,&i);   //[4]
    printList(&list);
    i = 3;
    insertFirstNode(&list,&i);   //[3,4]
    printList(&list);
    i = 1;
    insertFirstNode(&list,&i);   //[1,3,4]
    printList(&list);
    int j =1;
    i = 2;
    insertNode(&list,&j,&i);      //[1,2,3,4]
    printList(&list);
    i = 3;
    deleteNode(&list,&i);        //[1,2,4]
    printList(&list);
    printList(&list,printInt);

    double d = 4.4;
    insertFirstNode(&list2,&d);   //[4.4]
    printList(&list2);
    d = 3.3;
    insertFirstNode(&list2,&d);   //[3.3,4.4]
    printList(&list2);
    d = 1.1;
    insertFirstNode(&list2,&d);   //[1.1,3.3,4.4]
    printList(&list2);
    double f =1.1;
    d = 2.2;
    insertNode(&list2,&f,&d);      //[1.1,2.2,3.3,4.4]
    printList(&list2);
    d = 3.3;
    deleteNode(&list2,&d);        //[1.1,2.2,4.4]
    printList(&list2);
    printList(&list2,printDouble);


    cleanuplist(&list);
    cleanuplist(&list2);
    
    return 0;
}