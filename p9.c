#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
    }
    else if (pid == 0)
    {
        printf("Child process terminating with status 10\n");
        exit(10);
    }
    else
    {
        wait(&status);

        if (WIFEXITED(status))
        {
            printf("Child exited normally\n");
            printf("Exit status = %d\n", WEXITSTATUS(status));
        }
    }

    return 0;
}