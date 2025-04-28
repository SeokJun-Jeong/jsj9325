
// ps aux
#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>

#define SHM_NAME "/myshm"
#define SEM_NAME "/mysem"
#define SHM_SIZE 128
#define COUNT 1000000

int main()
{
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, SHM_SIZE);
    int *shm = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    sem_t *sem = sem_open(SEM_NAME, O_CREAT, 0666, 1);

    *shm = 0;
    printf("초기 카운터 값 : %d\n", *shm);
    pid_t pid = fork();
    if (pid == 0)
    {
        // sem_wait(sem);
        printf("자식");
        for (int i = 0; i < COUNT; i++)
        {
            (*shm)++;
        }
        
        // printf("Child read : %s\n", shm);
        // sem_post(sem);

        munmap(shm,SHM_SIZE);
        // sem_close(sem);
        exit(0);
    }
    else
    {
        // sem_wait(sem);
        printf("부모");
        for (int i = 0; i < COUNT; i++)
        {
            (*shm)++;
        }
        
        // strcpy(shm,"Hello from Parent!");
        // printf("Parent wrote : %s\n",shm);
        // sem_post(sem);

        wait(NULL);

        printf("최종 카운터 값 : %d\n", *shm);
        printf("예상 최종값 : %d\n", COUNT*2);
        printf("손실 된 증가 값 : %d\n",(COUNT * 2)- *shm);
        munmap(shm, SHM_SIZE); // 메모리 해제
        close(shm_fd);
        shm_unlink(SHM_NAME); // 언링크
    
        // sem_close(sem); // 세마포어 해제
        // sem_unlink(SEM_NAME);
    }
    


    return 0;
}