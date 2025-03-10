#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int sumArray(int pArray[], int size);

int main(void)
{
    int nums[20] = {0};
    srand(time(NULL));
    for (int i = 0; i < 20; ++i)
    {
        nums[i] = rand() % 101;
        printf("%d ", nums[i]);
    }
    printf("\n");

    int sum = sumArray(nums, sizeof(nums)/sizeof(int)); //<-사이즈(전체사이즈 80/ int사이즈4) = 20  20으로 쓰기에는 함수가 아닌 상수값을 넘기는 것이므로 사용 불가
    printf("sum : %d\n",sum);
    return 0;
}

int sumArray(int pArray[], int size)
{  
    //배열을 넘길때 반드시 주소와 사이즈를 같이 넘겨야 한다
    int sum = 0;
    for (int i = 0; i < size; ++i)
    {
        sum += pArray[i];
    }
    return sum;
}