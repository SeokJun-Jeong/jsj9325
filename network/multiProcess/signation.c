#include <stdio.h>
#include <unistd.h>
#include <signal.h>


void timeoutCallback(int sig);
// void keycontrolCallback(int sig);

int main()
{
    // signal(SIGALRM, timeoutCallback);   
    struct sigaction act;
    act.sa_handler = timeoutCallback;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(SIGALRM, &act, 0);

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
    }
    alarm(2);
    
}

