#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>

int main()
{
    pid_t pid = fork();
    int status;

    if (pid==0) //자식
    {
        return 3; 
    }
    else 
    {
        pid = fork();

        if (pid==0) //자식2
        {
            exit(7); 
        }
        else //부모
        {
        printf("자식 프로세스 ID : %d \n", pid);
        wait(&status);  //자식 프로세스가 끝날 때 까지 블럭된다
        if (WIFEXITED(status))
        {
            printf("자식이 보낸 메세지 : %d\n", WEXITSTATUS(status));
        }
        wait(&status);  //자식 프로세스가 끝날 때 까지 블럭된다
        if (WIFEXITED(status))
        {
            printf("자식2가 보낸 메세지 : %d\n", WEXITSTATUS(status));    
        }
        
        sleep(30);
        
        }
    }

    return 0;
}