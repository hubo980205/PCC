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
    init_signal();      //注册信号
    CALLBACK func;
    func = callback;
    register_callback(func);//设置回调
    struct pcc_obj obj;
    obj.pid = getpid();
    
    while(1)
    {
        sleep(1);
        int res = send_signal(obj);//发送信号
        printf("%d\n",res);
    }

}