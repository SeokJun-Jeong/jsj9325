#include <stdio.h>

int sumArray(const int *pArr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; ++i)
    {
        sum +=pArr[i];
    }
    return sum;
}

int sumArray2(int arr[])
// int sumArray2(int arr[10])
{
    int sum = 0;
    for (int i = 0; i < sizeof(arr)/ sizeof(arr[0]); ++i)
    {
        sum += *arr++;       //arr is a pointer
    }
    return sum;
}


int main(void)
{
    int nums[] = {1,2,3,4,5,6,7,8,9,10};

    // int sum = sumArray(nums,10);    //sum: 55  1~10 sum
    // int sum = sumArray(nums + 5,5);    //sum : 40
    int sum = sumArray2(nums);
    printf("sum : %d\n",sum);
    return 0;

}