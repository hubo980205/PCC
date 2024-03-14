#pragma once
#include<sys/signal.h>
#include "PCC/type.h"


int init_signal();

/// @brief 发送消息信号
/// @param obj 接受消息对象
/// @return 成功=1   失败= -1
int send_signal(pcc_obj obj);

/// @brief 注册回调函数
/// @param  函数指针
/// @return 1成功   -1失败
int register_callback(CALLBACK callback);

