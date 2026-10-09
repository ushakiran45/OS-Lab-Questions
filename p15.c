#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int sum = 0, flag = 0;
    int fd[2];

    pipe(fd);

    pid_t pid = fork();

    if (pid == 0)
    {
        close(fd[1]);

        read(fd[0], &sum, sizeof(sum));
        close(fd[0]);

        printf("Child: Received sum = %d\n", sum);

        if (sum <= 1)
            flag = 1;
        else
        {
            for (int i = 2; i < sum; i++)
            {
                if (sum % i == 0)
                {
                    flag = 1;
                    break;
                }
            }
        }

        if (flag == 0)
            printf("Sum is Prime\n");
        else
            printf("Sum is Not Prime\n");
    }
    else if (pid > 0)
    {
        close(fd[0]);

        for (int i = 0; i < 5; i++)
            sum = sum + a[i];

        printf("Parent: Sum = %d\n", sum);

        write(fd[1], &sum, sizeof(sum));
        close(fd[1]);

        wait(NULL);
    }
    else
    {
        printf("Fork failed\n");
    }

    return 0;
}