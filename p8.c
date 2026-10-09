#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    for (int i = 1; i <= 3; i++)
    {
        pid = fork();

        if (pid < 0)
        {
            printf("Fork failed\n");
            return 1;
        }
        else if (pid == 0)
        {
            printf("Child Number: %d\n", i);
            printf("PID: %d\n", (int)getpid());
            printf("PPID: %d\n\n", (int)getppid());
            return 0;
        }
    }

    for (int i = 1; i <= 3; i++)
    {
        wait(NULL);
    }

    printf("Parent: All child processes have terminated.\n");

    return 0;
}