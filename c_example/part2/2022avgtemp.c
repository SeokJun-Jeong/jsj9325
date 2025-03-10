#include<stdio.h>

int main(void)
{
    double temp[12]= {0};
    for (int i = 0; i < 12; ++i)
    {
        scanf("%lf", & temp[i]);
    }
    
    double sum = 0.0;
    for (int i = 0; i < 12; ++i)
    {
        sum += temp[i];
    }
    
    double average = 0.0;
    average = sum/12.0;
    printf("2022년 평균 온도는 %.2lf이다.\n",average);
    
    return 0 ;

}