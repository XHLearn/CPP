/*
 * @Description: 两个进程通过映射普通文件实现共享内存通信
 * @Author: lamborghini1993
 * @Date: 2019-02-22 20:32:35
 * @UpdateDate: 2019-02-25 10:34:13
 */

#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

typedef struct shared1
{
    char name[4];
    int age;
} people;

int main(int argc, char **argv)
{
    int fd, i;
    people *p;

    fd = open(argv[1], O_CREAT | O_RDWR, 00777);

    p = (people *)mmap(NULL, sizeof(people) * 10, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    for (i = 0; i < 10; i++)
    {
        printf("name:%s age:%d\n", (*(p + i)).name, (*(p + i)).age);
    }
    munmap(p, sizeof(people) * 10);

    return 0;
}