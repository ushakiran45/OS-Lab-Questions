#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int n, a = 0, b = 1, c;

    printf("Enter an integer n: ");
    scanf("%d", &n);

    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
    }
    else if (pid == 0)
    {
        printf("Child: Fibonacci numbers up to %d:\n", n);

        while (a <= n)
        {
            printf("%d ", a);
            c = a + b;
            a = b;
            b = c;
        }

        printf("\n");
    }
    else
    {
        wait(NULL);

        printf("Parent: Armstrong numbers from 1 to %d:\n", n);

        for (int num = 1; num <= n; num++)
        {
            int temp = num, digit, sum = 0;

            while (temp > 0)
            {
                digit = temp % 10;
                sum = sum + digit * digit * digit;
                temp = temp / 10;
            }

            if (sum == num)
                printf("%d ", num);
        }

        printf("\n");
    }

    return 0;
}