// 10개 배열을 랜덤으로 0~100 만들어서 int를 하나 scanf로 받는다
// 같은 원소가 있는지 index가 몇 번째인지 출력하시오
#include<stdio.h>
#include<stdlib.h>
#include<time.h>



int main(void)
{
    
    int rn[10];
    int value;
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 10; ++i)
    {
         rn[i] =rand() % 101 ;
         printf("%d ,",rn[i]);

    }
    
    printf("\n찾을 숫자를 입력하세요 : ");
    scanf("%d",&value);
    int i;
    for ( i = 0; i < 10; ++i)
    {
        if(value == rn[i])
            break;

    }
    if(i < 10)
    {
        printf("%d 숫자를 찾았다. 인덱스는 %d이다. \n",value,i+1);

    }
    else
    {
        printf("입력한 숫자에 %d를 찾지 못했다\n",value);
    }    

    return 0 ;
}