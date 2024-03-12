#pragma once
#include "type.h"
struct msgst
{
    int sendtime;
    msgt type;
    int msglen;
    unsigned char buff[MSG_MAX_LEN];
    /* data */
};

struct memblock
{
    int     msgid;
    int     pid;
    int     tid;
    unsigned char msgbuff[MSG_MAX_COUNT];
};


class PCC_MEM
{
public:
    PCC_MEM();
    ~PCC_MEM();
    int init(int pid,int tid);

private:
    void * m_pshm;;
    int m_nshmid;
};
