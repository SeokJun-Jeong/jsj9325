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

        printf("자식 프로세스 ID : %d \n", pid);
        while (!waitpid(-1,&status,WNOHANG))
        {
            puts("sleep 3초");
            sleep(3);
        }
        if (WIFEXITED(status))
        {
            printf("자식이 보낸 메세지 : %d\n", WEXITSTATUS(status));
        }
        sleep(30);
        
        
    
    }

    return 0;
}