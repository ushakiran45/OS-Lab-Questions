#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
    }
    else if (pid == 0)
    {
        printf("Child Process:\n");

        for (int i = 1; i <= 5; i++)
        {
            printf("%d ", i);
        }

        printf("\n");
    }
    else
    {
        wait(NULL);
        printf("Parent: Child has finished execution\n");
    }

    return 0;
}