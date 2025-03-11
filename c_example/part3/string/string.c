int my_strlen(const char *s)
{
    // int i;
    // for (int i = 0; i < char(*s; ++i)
    // {
    //     i += 1;
    // }
    // printf("%d",i);
    // return 0;

    int i = -1;
    do
    {
        ++i;
    } while (s[i] != '\0');
    return i; //<- null을 방지하기 위해
}

void my_strcpy(char *des, const char *src)
{
    // int des;
    // int src;
    // int temp;
    // des = src;
    // temp = src;

    int i = 0;
    while (src[i] != '\0')
    {
        des[i] = src[i];
        ++i;
    } //<- null을 방지하기 위해
    des[i] = '\0';
}

int my_strcmp(const char *s1,const char *s2)
{
    // int s1;
    // int s2;
    // if (s1 == s2)
    // {
    //     my_strcmp ==0;
    // }
    // else
    // {
    //     my_strcmp == 1;
    // }
    // return 0;
    
    int result = 0;
    for (int  i = 0; i < 1000; ++i)
    {
        if (s1[i] == '\0')
        {
            break;
        }
        if (s1[i] != s2[i])
        {
            result += 1;
        }
        
    }
    return result;
    
}

void my_strcat(char *des,const char *src)
{
    // des의 끝 인덱스 얻기
    int start = 0;
    while (des[start] != '\0')
    {
        ++start;
    }
    //des의 끝에서 하나씩 src char 붙이기
    int i =0;
    while (src[i] != '\0')
    {
        des[start +i] = src[i];
        ++i;
    }
    //변경된 des의 마지막에 null문자 추가
    des[start+i] = '\0';
    
}