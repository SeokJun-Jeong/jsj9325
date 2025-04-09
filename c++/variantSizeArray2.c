#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int size;
    scanf("%d", &size);

    //int array[size];   //C99
    int *pArr = malloc(sizeof(int) *size);    //malloc(동적할당함수)에는 free함수 필수  malloc앞에 (int*)적어도 됨
    //pArr == NULL
    
    for (int i = 0; i < size; ++i)
    {
        //*(pArr + i) = i +1;
        pArr[i] = i+1;
    }
    for (int i = 0; i < size; ++i)
    {
        //printf("%d", *(pArr + i));
        printf("%d", pArr[i]);
    }
    
    free(pArr);
    printf("\n");
    return 0;
}