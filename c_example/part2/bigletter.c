// 임이의 char를 scanf로 받아서 대문자인지 소문자인지 출력하시오

#include<stdio.h>

int main()
{
    char *letter;
    printf("문자를 입력하시오 : ");
    scanf("%s", letter);

    if ((int)letter < 91)
    {
        printf("대문자\n");
    }
    if ((int)letter > 96)
    {
        printf("소문자\n");
    }
    
 
    // if ('A' <= letter && letter <= 'Z')
    // {
    //     printf("%s는 대문자\n",letter);
    // }
    // if ('a' <= letter && letter <= 'z')
    // {
    //     printf("%s는 소문자\n",letter);
    // }
    // else
    // {
    //     printf("%s는영 문자가 아닙니다.\n",letter);
    // }
return 0 ;

}