#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>
#include <pthread.h>
#define MY_SIG_READMSG      61 
#define MY_SIG_QUIT         62
#define MY_SIG_CONN         63

void signal_handler(int sig)
{
    if(sig == MY_SIG_CONN)
    {
        printf("信号触发");
    }
    else
    {
       
    }
}

//初始化函数  注册信号
void init()
{
    signal(MY_SIG_CONN,signal_handler);
}

int main(int argc,char ** argv)
{
    init();
    int pid = atoi(argv[1]);
    if(pid == -1)
    {
        printf("等待消息\n");
        while (1)
        {
            sleep(1);
        }
    }
    else 
    {
        int res = kill(pid, MY_SIG_CONN);
        printf("res = %d\n",res);
    }   
    return 0;
}