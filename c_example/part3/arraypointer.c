#include<stdio.h>

int main(void)
{
    int nums[] = {1,2,3,4,5};
    int *p;

    p=nums; //nums = 상수인 &nums[0](대체가능) = p(대체불가능)
    for (int i = 0; i < 5; ++i)
    {
        printf("%d번째 원소는 : %d\n", i+1,nums[i]);
        printf("%d번째 원소는 : %d\n", i+1,p[i]);
        printf("%d번째 원소는 : %d\n", i+1,*(p+i));
        
    }
    return 0;
}