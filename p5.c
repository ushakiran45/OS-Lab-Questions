#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int n, num;
    long long fact = 1;
    int a = 0, b = 1, c;

    printf("Enter the number of Fibonacci terms: ");
    scanf("%d", &n);

    printf("Enter the number for factorial: ");
    scanf("%d", &num);

    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
    }
    else if (pid == 0)
    {
        printf("Child Process - Fibonacci Series:\n");

        for (int i = 1; i <= n; i++)
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

        for (int i = 1; i <= num; i++)
        {
            fact = fact * i;
        }

        printf("Parent Process - Factorial of %d = %lld\n",
               num, fact);
    }

    return 0;
}