#include <PCC/mem.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>4 
PCC_MEM::PCC_MEM():
    m_pshm(nullptr),
    m_nshmid(-1)
{

}
PCC_MEM::~PCC_MEM()
{
    //释放资源
}
int PCC_MEM::init(int pid,int tid)
{
    m_nshmid = shmget(PCC_MEM_KEY,(sizeof(memblock)*1024),IPC_CREAT);
    if(m_nshmid == -1)
    {
        fprintf(stderr, "shmat failed\n");
    }
    else
    {
        m_pshm = shmat(m_nshmid,0,0);
    }

}