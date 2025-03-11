#include<stdio.h>
#include<string.h>

int main(void)
{
    const char *str1 = "hello, wolrd";
    char str2[] = "stack char array";
    int str1len = strlen(str1);  //<-null을 제외한 함수이므로 char에 -1이나온다.
    int str2len = strlen(str2);
    printf("str1len : %d str2len : %d\n",str1len,str2len);

    char str3[30];
    strcpy(str3, str1);
    str3[0] = 'H';
    printf("%s\n",str3);

    if (strcmp(str1,str3) == 0)
    {
        printf("두 문자열 str1, str2는 같다\n");
    }
    else
    {
        printf("두 문자열은 다르다, %d\n",strcmp(str1,str3));
    }

    strcat(str3, str2);
    printf("%s\n",str3);
    return 0;
}