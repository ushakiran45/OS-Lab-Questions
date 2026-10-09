#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int n, a = 0, b = 1, c;
    long long fact = 1;
    int sum = 0;

    printf("Enter an integer n: ");
    scanf("%d", &n);

    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
    }
    else if (pid == 0)
    {
        printf("Child Process:\n");

        printf("Fibonacci Series: ");
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", a);
            c = a + b;
            a = b;
            b = c;
        }

        printf("\n");

        for (int i = 1; i <= n; i++)
        {
            fact = fact * i;
        }

        printf("Factorial of %d = %lld\n", n, fact);
    }
    else
    {
        wait(NULL);

        for (int i = 1; i <= n; i++)
        {
            sum = sum + i;
        }

        printf("Parent Process:\n");
        printf("Sum of first %d natural numbers = %d\n", n, sum);
    }

    return 0;
}