//랜덤 한 수 20개 프린트
//정렬 후 프린트

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


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

    //bubble sorting
    for (int i = 19; i >= 1; --i)
    {//i는 각 스텝에 비교 횟수
        for (int j = 0; j < i; ++j)
        {
            if(nums[j]>nums[j+1])
            {
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp ;
            }
        }
        
        
    }
    
    
    for (int i = 0; i < 20; ++i)
    {
        printf("%d ",nums[i]);
    }
    printf("\n");
    return 0;
}