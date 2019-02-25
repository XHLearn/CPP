/*
 * @Description: 系统V共享内存-read
 *  地址： https://www.ibm.com/developerworks/cn/linux/l-ipc/part5/index2.html?ca=drs-
 * @Author: lamborghini1993
 * @Date: 2019-02-25 14:55:52
 * @UpdateDate: 2019-02-25 16:25:16
 */

#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <cstring>
#include <unistd.h>
using namespace std;

typedef struct
{
    char name[4];
    int age;
} people;

int main(int argc, char **argv)
{
    int shm_id, i, num = 10;
    key_t key;
    char temp;
    people *p;
    char const *name = "love.xh";   // 为什么要加上const，因为char字符串字面值是不允许修改的
    key = ftok(name, 0);
    if (key == -1)
        perror("ftok error");
    shm_id = shmget(key, 4096, IPC_CREAT); //shmget用来获得共享内存区域的ID
    if (shm_id == -1)
    {
        perror("shmget error");
        return -1;
    }
    p = (people *)shmat(shm_id, NULL, 0); // shmat()把共享内存区域映射到调用进程的地址空间中去，这样，进程就可以方便地对共享区域进行访问操作。
    temp = 'a';
    for (i = 0; i < num; i++)
    {
        printf("name:%s age:%d\n", (*(p + i)).name, (*(p + i)).age);
    }
    if (shmdt(p) == -1) //shmdt()调用用来解除进程对共享内存区域的映射
        perror("detach error");

    return 0;
}
