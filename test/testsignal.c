#include "PCC/psignal.h"
#include <stdio.h>
#include <unistd.h>
int  callback()
{
    printf("测试程序1的callback");
}

int main()
{
    printf("开始\n");
    init_signal();
    CALLBACK func;
    func = callback;
    register_callback(func);
    struct pcc_obj obj;
    obj.pid = getpid();
    
    while(1)
    {
        sleep(1);
        int res = send_signal(obj);
        printf("%d\n",res);
    }

}