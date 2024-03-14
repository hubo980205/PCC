#ifndef _PCC_TYPE_H_
#define _PCC_TYPE_H_
#include <sys/signal.h>
#define SIG_MSG_SEND 60

#define PCC_MEM_KEY 90910

#define MSG_MAX_LEN 1024
#define MSG_MAX_COUNT 128

/// @brief 消息内存中数据的类型 和如何解析消息相关
enum msg_value_type
{
    t_string,
    t_i8,
    t_i16,
    t_i32,
    t_ui8,
    t_ui16,
    t_ui32,
    t_float,
};
typedef msg_value_type msgt;

struct pcc_obj
{
    int pid;
    int tid;
    
};

//消息结构体,每条消息都以这种结构存储
struct msgst
{
    int sendtime;
    msgt type;
    int msglen;
    unsigned char buff[MSG_MAX_LEN];
    /* data */
};
//内存中消息块结构，每个进程或者线程都会分配一个
struct memblock
{
    int     msgid;
    int     pid;
    int     tid;
    unsigned char msgbuff[MSG_MAX_COUNT];
};



typedef int(*CALLBACK)(void);

#endif //_PCC_TYPE_H_