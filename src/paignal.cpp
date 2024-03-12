#include "PCC/psignal.h"

CALLBACK * g_callback;


int send_signal(pcc_obj obj)
{
    
}



int register_callback(CALLBACK *callback)
{
    if(callback != nullptr)
    {
        g_callback = callback;
        return 1;
    }
    return -1;
}

