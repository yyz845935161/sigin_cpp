#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
    while (1)
    {
        printf("hellow : pid:%d, ppid:%d  \n",getpid(),getppid());
        /* code */
        sleep(1);
    }
    
}