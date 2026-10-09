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
        printf("Child process terminating...\n");
        exit(0);
    }
    else
    {
        printf("Parent process is running.\n");
        printf("Parent PID: %d\n", (int)getpid());
        printf("Child PID: %d\n", (int)pid);

        sleep(20);

        printf("Parent process is now terminating.\n");
    }

    return 0;
}