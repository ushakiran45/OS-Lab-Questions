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
        printf("Child Process - Odd Numbers:\n");

        for (int i = 1; i <= 19; i += 2)
        {
            printf("%d ", i);
        }
        printf("\n");
    }
    else
    {
        printf("Parent Process - Even Numbers:\n");

        for (int i = 2; i <= 20; i += 2)
        {
            printf("%d ", i);
        }
        printf("\n");
    }

    return 0;
}