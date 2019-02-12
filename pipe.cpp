#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main()
{
    int fd[2];
    int ret = pipe(fd);
    if (ret == -1)
    {
        printf("pipe error\n");
        return 1;
    }
    pid_t id = fork();
    if (id == 0)
    {
        printf("id=0\n");
        close(fd[0]);
        char child[] = "I am child!";
        for (int i = 0; i < 5; i++)
        {
            printf("ready write %d nums\n", i);
            write(fd[1], child, strlen(child) + 1);
            sleep(2);
        }
    }
    else if (id > 0)
    {
        printf("id=%d\n", id);
        close(fd[1]);
        char msg[100];
        for (int i = 0; i < 5; i++)
        {
            memset(msg, '\0', sizeof(msg));
            printf("ready read %d nums\n", i);
            ssize_t s = read(fd[0], msg, sizeof(msg));
            if (s > 0)
            {
                msg[s - 1] = '\0';
            }
            printf("%s\n", msg);
        }
    }
    else
    {
        perror("fork error\n");
        return 2;
    }
    return 0;
}