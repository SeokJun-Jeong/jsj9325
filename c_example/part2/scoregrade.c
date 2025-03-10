//A~F까지 점수를 받아서 출력
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>


int main(void)
{   
    char grades[]= {'f', 'f', 'f', 'f', 'f','f','d','c','b','a','a','\0'};
    // char grades[]="FFFFFFDCBAA";
    int score;
    char grade = 'f';
    // printf("%s",grades);
    while (true)
    {
        printf("점수를 넣으세요 : ");
        scanf("%d", &score);
        grade = 'f';

        if(score >= 0 && score <= 100)
        {
            grade = grades[score/10];
        }
        printf("점수는 : %d --- %c\n", score, grade);
    }
     return 0;
}