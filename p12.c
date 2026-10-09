#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int n, flag = 0;
    long long fact = 1;

    printf("Enter an integer: ");
    scanf("%d", &n);

    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
    }
    else if (pid == 0)
    {
        if (n <= 1)
        {
            flag = 1;
        }
        else
        {
            for (int i = 2; i < n; i++)
            {
                if (n % i == 0)
                {
                    flag = 1;
                    break;
                }
            }
        }

        if (flag == 0)
            printf("Child: %d is a prime number\n", n);
        else
            printf("Child: %d is not a prime number\n", n);
    }
    else
    {
        wait(NULL);

        if (n < 0)
        {
            printf("Parent: Factorial is not defined for negative integers\n");
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                fact = fact * i;
            }

            printf("Parent: Factorial of %d = %lld\n", n, fact);
        }
    }

    return 0;
}