//문자열을 쓰는  두가지 방법
#include <stdio.h>

int main(void)
{
    char *str1 = "hellow"; //변화를 줄 수 없다.
    char str2[] = "hellow"; //변화를 줄 수 있다.
    char str3[] = {'h', 'e', 'l', 'l', 'o' ,'w', '\0','l','o','w' };
    char str4 = 'h';
    printf("%s\n", str1);
    printf("%s\n", str2);
    printf("%s\n", str3);
    printf("%c\n", str4);
    printf("%p\n", &str1);
    printf("%p\n", &str2);
    printf("%p\n", &str3);
    printf("%p\n", &str4);
    
    //str1[0] = 'H'; 컴파일 에러
    str3[0] = 'H';
    printf("%s\n", str3);
    return 0;

}