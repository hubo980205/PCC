#include "PCC/pmsg.h"
#include <sys/unistd.h>
#include "PCC/psignal.h"
#include <stdio.h>
#include <unistd.h>


#define gettid() syscall(__NR_gettid)

pmsg::pmsg()
{

}
pmsg::~pmsg()
{

}

int pmsg::init()
{
    m_obj.pid = getpid();
    m_obj.tid = gettid();
    return 1;
}