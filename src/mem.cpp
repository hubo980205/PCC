#include <PCC/mem.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

void * g_pshm;;
int g_nshmid;
int initpcount;

int init(int pid,int tid)
{
    
    g_nshmid = shmget(PCC_MEM_KEY,(sizeof(memblock)*1024),IPC_CREAT);
    if(g_nshmid == -1)
    {
        fprintf(stderr, "shmat failed\n");
    }
    else
    {
        g_pshm = shmat(g_nshmid,0,0);
        if(g_pshm != nullptr)
        {
            return g_nshmid;
        }
    }
    return -1;

}
void*  getp()
{
    return g_pshm;
}