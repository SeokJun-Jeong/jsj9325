#include<stdio.h>
#include<stdbool.h>
int main(void)
{
    int year;
        
    while (true)
    {
        printf("년도를 넣으세요 : ");
        scanf("%d",&year);
        // if (year % 4 == 0)
        // {
        // printf("%d년도는 윤년입니다.\n",year);  // <-true 값
        // }
        // else
        // {
        // printf("%d 년도는 평년입니다.\n",year);  // <-false 값
        // }   
        printf("%d년도는 %s입니다.\n",year,year%4 ? "평년" : "윤년");   //<-나머지가 있으면 0값이 아니므로 true가 나온다.
        if(!year)
            break;
        
    }
    

    return 0 ;
}