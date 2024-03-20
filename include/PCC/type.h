#ifndef _PCC_TYPE_H_
#define _PCC_TYPE_H_
#include <sys/signal.h>
#define SIG_MSG_SEND 60

#define PCC_MEM_KEY 90910

#define MSG_MAX_LEN 1024
#define MSG_MAX_COUNT 128


typedef int(*CALLBACK)(void);

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
    char name[32];
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
struct mem_block_head
{
    int     msgid;
    int     pid;
    int     tid;
    int     msg_count;
    int     synid;
    unsigned char state;    //0x 0000 0000
    msgst   msg[MSG_MAX_COUNT];
};





struct mem_obj_head
{
    pcc_obj pcc;
    int send_flag;
    int read_flag;
    int heart;
};

struct syn_block
{
    unsigned char flag[MSG_MAX_COUNT];
};


//共享内存进程对象头部信息结构
struct mem_obj_head
{
    //注册进程或者线程到这里，此处存在才会允许去操作对应的消息结构
    int pcc_id;         //唯一id
    int addr_offset;    //地址偏移  对应的是进程对象首地址的偏移
    int heart;          //心跳，目前如何实现还不清楚，但是希望可以通过此处标记判断注册这个位置的进程或者线程是否存活
    int pid;
    int tid;
};  
//共享内存进程对象消息结构  
struct mem_obj_msg
{
    int msg_count;      //当前存在的未读消息
    unsigned char state;//当前读写状态
    msg_obj msg[MSG_MAX_COUNT];
    
};
//共享内存进程对象消息同步结构
struct mem_obj_syn
{

};

struct msg_obj
{
    pcc_obj source_obj;     //消息发送对象
    int send_time;          //发送时间
    int type;               //后续消息地址的解析方式
    int syn_flag;           //同步标记
    unsigned char buff[MSG_MAX_LEN];
};

struct syn_obj
{
    unsigned char use_flag;
    bool syn;               // 为真时准备同步（阻塞）  为假时可以同步（非阻塞）
    int syn_count;          // 同步是否完成标记，设置同步时，必须将此数量何   感觉没必要  暂时不管 
};

#endif //_PCC_TYPE_H_