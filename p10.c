#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

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
        printf("Child PID: %d\n", (int)getpid());
        printf("Parent PID before termination: %d\n", (int)getppid());

        sleep(5);

        printf("Parent PID after termination: %d\n", (int)getppid());
        printf("Child continues execution as an orphan.\n");
    }
    else
    {
        printf("Parent Process\n");
        printf("Parent PID: %d\n", (int)getpid());

        sleep(2);
        printf("Parent terminating...\n");
        exit(0);
    }

    return 0;
}