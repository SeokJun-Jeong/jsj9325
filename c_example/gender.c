#include<stdio.h>

int main(void)
{
    int man, woman;
    double sum, manRate, womanRate ;
    printf("enter man's number : ");
    scanf("%d", &man);
    printf("enter woman's number : ");
    scanf("%d", &woman);
    
    sum = man + woman;    // <-sum = (double)man + (double)woman; 이면 남자와 여자가 double(실수)로 받아들여진다.
    manRate = man/sum*100;   
    womanRate = woman/sum*100;

    printf("남자의 수는 %d명이고 여자의 수는 %d명이다.\n",man, woman);
    printf("총 수는 %.0f명\n남자의비율은 %.2f%%\n남자의 비율은 %.2f%%\n",sum, manRate,womanRate);
    return 0 ;
}