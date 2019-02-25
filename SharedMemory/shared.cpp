/*
 * @Description: 父子进程通过匿名映射实现共享内存
 * @Author: lamborghini1993
 * @Date: 2019-02-25 10:33:36
 * @UpdateDate: 2019-02-25 15:23:27
 */

#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct
{
    char name[4];
    int age;
} people;

int main(int argc, char **argv)
{
    int fd, i, num = 12;
    people *p;
    char temp;
    char n[4];
    cout << sizeof(n) << endl;
    p = (people *)mmap(NULL, sizeof(people) * 10, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    if (fork() == 0)
    {
        printf("子进程中，fork返回0\n");
        sleep(2);
        for (i = 0; i < num; i++)
        {
            printf("child read the %d people's age:%d name:%s\n", i, (*(p + i)).age, (*(p + i)).name);
        }
        (*(p + i)).age = 100;
        munmap(p, sizeof(people) * 10);
        exit(0);
    }

    printf("父进程中，fork返回新创建子进程的进程ID\n");
    temp = 'a';
    for (i = 0; i < num; i++)
    {
        memcpy((*(p + i)).name, &temp, 4);
        (*(p + i)).age = i;
        temp += 1;
    }
    printf("initialize over\n");
    sleep(5);
    printf("umap...\n");
    munmap(p, sizeof(people) * 10);
    printf("umap ok\n");

    return 0;
}