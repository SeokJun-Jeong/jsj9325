#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void timeoutCallback(int sig);
void keycontrolCallback(int sig);

int main()
{
    signal(SIGALRM, timeoutCallback);  //시그널 발생시 바로 다음 루프
    signal(SIGINT, keycontrolCallback);
    alarm(2);

    for (int i = 0; i < 10; ++i)
    {
        puts("wait...");
        sleep(100);
    }
    
    return 0;
}

void timeoutCallback(int sig)
{
    if (sig==SIGALRM)
    {
        puts("Time out");
        alarm(2);
    }
    
}
void keycontrolCallback(int sig)
{
    if (sig==SIGINT)
    {
        puts("ctrl+c pressed");
        alarm(2);
    }
    
}
