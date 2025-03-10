//숫자 3개를 만드시오[랜덤] (서로 다른 숫자)
//숫자 3개를 입력 받으세요
//위치의 숫자가 같으면 스트라이크 +1
//위치가 다르지만 숫자가 같으면 볼 +1
//모든 숫자의 위치와 숫자가 동일하면 성공
//시도 횟수를 출력하는 프로그램
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>



int main()
{
    srand(time(NULL));
    int com;
    int num_input[3];
    int answer[3];
  
    num_input[0] = rand() % 10 ;

    do
    {
        num_input[1] = rand() % 10;
    } while (num_input[0] == num_input [1]);
    
    do
    {
        num_input[2] = rand() % 10;
    } while (num_input[0] == num_input[2] || num_input[1] == num_input [2]); 
    printf("%d %d %d \n",num_input[0],num_input[1],num_input[2]);
    
    int count = 0;
    while (true)
    {
        printf("숫자 3개를 입력해 주세요 : \n");
        for (int i = 0; i < 3; ++i)
        {
            scanf("%d", &answer[i]);
        }
        
        //비교
        int strike = 0;
        int ball = 0;
        
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (num_input[i] == answer [j])
                {
                    if (i == j)
                    {
                        ++strike;
                    }
                    else
                    {
                        ++ball;
                    }
                    
                }
                
            }
            
        }

        printf("strike : %d \t ball : %d\n", strike, ball);
        ++count;

        if (strike ==3)
        {
            break;
        }
        
        
    }
    printf("축하합니다, 당신의 시도 횟수는 %d회입니다,", count);

    return 0 ;
}