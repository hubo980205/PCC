#include "PCC/psignal.h"
#include "PCC/type.h"
#include <stdio.h>



CALLBACK  g_callback;

void readmsgcallback(int sig)
{
    if(g_callback != NULL )
        (*g_callback)();
}

int init_signal()
{
    signal(SIG_MSG_SEND, readmsgcallback);
}
int send_signal(pcc_obj obj)
{
    //todo 找到对象是进程还是线程
    /*线程*/
    {}
    /*进程*/
    {
        //todo 判断线程是否存在
        int res = kill(obj.pid,SIG_MSG_SEND);
        if(res != 0)
        {
            printf("进程%d  不存在\n",obj.pid);
            return  -1;
        }
    }
    return 1;
}
int register_callback(CALLBACK callback)
{
    if(callback != NULL)
    {
        g_callback = callback;
        return 1;
    }
    return -1;
}

