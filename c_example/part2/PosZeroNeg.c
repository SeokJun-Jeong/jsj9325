// 숫자를 입력 받아서 양수, 제로, 음수를 출력하는 프로그램
// if else구문으로 만들세요.
// printf는 한번만 사용

#include<stdio.h>

int main(void)
{
    char *PZN;
    int num;
     scanf("%d", &num);

    if (num > 0)
    {
      PZN = "양수";
    }
    else if(num == 0)
    {
         PZN = "제로";
    
    }
    else
    {
         PZN = "음수";
  
    }
    printf("%d의 숫자는%s입니다\n.",num,PZN);
    

    // printf("%d의 숫자는%s입니다\n.",num,num>0 ? "양수": num < 0 ? "음수":"제로" ); <-num과scan만을 사용하여 값을 나타내기
    return 0 ;

}