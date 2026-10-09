#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int n, a[100], sum = 0, flag = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
    }
    else if (pid == 0)
    {
        for (int i = 0; i < n; i++)
        {
            sum = sum + a[i];
        }

        printf("Child: Sum of array = %d\n", sum);

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
            printf("Sum is prime\n");
        else
            printf("Sum is not prime\n");
    }
    else
    {
        wait(NULL);
        printf("Parent: Child process completed\n");
    }

    return 0;
}