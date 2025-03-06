//1~127 아스키 코드를 출력하세요 -char ch = 0  ->printf("%c, ch");
// 이중for문으로 만드세요
// 0 2 3 ~ 16
//8줄 출력

#include<stdio.h>

int main(void)
{
    char ascii;
    printf("문자를 입력하세요 : ");

    for (int j = 0; j <= 7; ++j)
    {
        printf("\n");
        for (int i = 0; i <= 15; ++i)
        {
            ascii = i + 16 * j;
            printf("%d:%c   ", ascii, ascii);
        }
        
    }
    
return 0 ;
}
