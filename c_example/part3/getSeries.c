#include <stdio.h>

int main()
{
    char ch;
    char str[100];

    printf("문자를 입력하세요: ");
    ch = getc(stdin);
    printf("입력한 문자를 %c입니다\n",ch);

    ch = getchar();
    printf("입력한 문자는 %c입니다\n", ch);
    scanf("%s",str);
    printf("입력한 문자열은 %s입니다\n",str);
}