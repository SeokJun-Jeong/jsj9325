#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <wait.h>


void timeoutCallback(int sig);
int main()
{
    pid_t pid = fork();

    if (pid==0) //자식
    {
        puts("나는 자식");    
    }
    else //부모
    {
        printf("자식 프로세스 ID : %d \n", pid);
        sleep(30);
    }
    if (pid==0)
    {
        puts("End child 프로세스\n");
    }
    else
    {
        puts("End parent 프로세스\n"); 
    }

    return 0;
}