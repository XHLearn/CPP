/*
 * @Description: 两个进程通过映射普通文件实现共享内存通信
 * @Author: lamborghini1993
 * @Date: 2019-02-22 20:29:50
 * @UpdateDate: 2019-02-25 10:34:18
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
    char temp;

    fd = open(argv[1], O_CREAT | O_RDWR | O_TRUNC, 00777);
    lseek(fd, sizeof(people) * 5 - 1, SEEK_SET);
    write(fd, "", 1);

    p = (people *)mmap(NULL, sizeof(people) * 10, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);

    temp = 'a';
    for (i = 0; i < 10; i++)
    {
        temp += 1;
        memcpy((*(p + i)).name, &temp, 2);
        (*(p + i)).age = 20 + i;
    }
    printf("initialize over \n ");
    sleep(10);
    munmap(p, sizeof(people) * 10);
    printf("umap ok\n");

    return 0;
}