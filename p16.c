#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    FILE *fp;
    char name[50], roll[20], class[30];
    char ch;

    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
    }
    else if (pid > 0)
    {
        fp = fopen("input.txt", "w");

        printf("Enter name: ");
        scanf("%49s", name);

        printf("Enter university roll number: ");
        scanf("%19s", roll);

        printf("Enter class: ");
        scanf("%29s", class);

        fprintf(fp, "Name: %s\nRoll Number: %s\nClass: %s\n",
                name, roll, class);

        fclose(fp);

        wait(NULL);
    }
    else
    {
        sleep(1);

        fp = fopen("input.txt", "r");

        if (fp == NULL)
        {
            printf("File not found\n");
            return 1;
        }

        printf("\nChild: File contents\n");

        while ((ch = fgetc(fp)) != EOF)
        {
            putchar(ch);
        }

        fclose(fp);
    }

    return 0;
}