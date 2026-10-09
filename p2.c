#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
    }
    else if (pid == 0)
    {
        printf("Child Process\n");
        printf("PID = %d\n", (int)getpid());
        printf("PPID = %d\n", (int)getppid());
    }
    else
    {
        printf("Parent Process\n");
        printf("PID = %d\n", (int)getpid());
        printf("PPID = %d\n", (int)getppid());
    }

    return 0;
}