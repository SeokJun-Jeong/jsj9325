#include<stdio.h>

int main()
{
    char *name;
    char namei[20];
    name = namei;
    *name = 'h';
    *(name + 1) = 'E';
    *(name + 2) = 'l';
    *(name + 3) = 'l';
    *(name + 4) = 'o';
    *(name + 5) = 'w';
    *(name + 6) = '\0';  //<-null이므로 뒤에 문자는 모두 삭제
    *(name + 7) = 'l';
    *(name + 8) = 'o';
    *(name + 9) = 'w'; 

    printf("%s\n", name);
    return 0;
}