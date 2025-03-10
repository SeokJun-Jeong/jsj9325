#include <stdio.h>
#include<stdlib.h>
//60점 이상시 합격을 출력

int main(int argc, char*argv[])
{
    if(argc<2)
    {
    
    
    printf("인자를 하나 넣어서 실행세요.\n");
        return 0 ;
    }
    // printf("%s\n",argv[1]);
    // printf("%s\n",argv);
    
    printf("score : %s --- %s\n", argv[1],atoi(argv[1]) >=60 ? "합격" : "실패") ;

    return 0;
}