#pragma once
#include "PCC/type.h"
class pmsg
{
    public:
        pmsg();
        ~pmsg();

        int init(pcc_obj obj);

        int send(unsigned char *buff,int len,pcc_obj obj);
        int send(char * buff,int len,pcc_obj obj);
        int send(int n,pcc_obj obj);
        int send(float n,pcc_obj obj);
        

        int register_callback(CALLBACK callback);
};