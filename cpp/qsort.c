//랜덤 한 수 20개 프린트
//정렬 후 프린트
//qsort

#include<stdio.h>
#include<stdlib.h> 
#include<time.h>

int compare(const void *a, const void *b) //const(불변)  *는 주소값
{
    return (*(int *)a -*(int *)b);
}

int main(void)
{
    int nums[20] = {0};

    srand(time(NULL));
    for (int i = 0; i < 20; ++i)
    {
        nums[i] = rand() % 101 ;
    }
    for (int i = 0; i < 20; ++i)
    {
        printf("%d ",nums[i]);
    }
    printf("\n");

    //q sorting
    qsort(nums,20, sizeof(nums[0]),compare);
    
    
    for (int i = 0; i < 20; ++i)
    {
        printf("%d ",nums[i]);
    }
    printf("\n");
    return 0;
}