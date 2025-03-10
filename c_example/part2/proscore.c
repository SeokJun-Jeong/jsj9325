//  n(MAX)개의 숫자를 배열로 만들어서[래넘] 평균을 소수점 2자리까지 출력

//VLA(variable length array)
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 5
#define MAXC 100

int main(void)
{
    srand((unsigned int)time(NULL));
    int scores[MAX];
    int sum = 0;
    double average;
    for (int i = 0; i < MAX; ++i)
    {
        scores[i] = rand() %(MAXC+1);
        printf("%d ",scores[i]);
        sum += scores[i];
    }
    printf("\n");
    average = (double)sum/MAX;
    printf("합은 %d 평균은 %.2f\n", sum,average);

    
    return 0 ;
}