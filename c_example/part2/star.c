// 별표를 5줄 하나씩 늘어나는 모양을 출력하세요.
//1.* > ** > *** > **** > *****(5줄)
//2.별표를 피라미드 모양으로 출력하세요.

#include<stdio.h>

int main(void)
{
    // char *star;
    // for (int i = 0; i < 5; ++i)
    // {
    //     star = "*";
    //     printf("%s  %d",star,i+1);
    
    // }
    // return 0 ;

    
     //1   
            for (int i = 1; i <= 5; ++i)
            {
                for (int j = 1; j <= i; ++j)
                {
                    printf("*");
                }
                printf("\n");
            }
        
    
    // return 0 ;

    //2
    for (int i = 1; i <= 5; ++i)
    {
        for (int j = 1; j <= 5 -i; ++j)
        {
            printf(" ");  //<- 
        }
        for (int j = 1; j <= 2*i-1; ++j)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0 ;
}