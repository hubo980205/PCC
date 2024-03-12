#pragma once

#include <sys/signal.h>
#define SIG_MSG_SEND 60

#define PCC_MEM_KEY 90910

#define MSG_MAX_LEN 1024
#define MSG_MAX_COUNT 128


enum msg_value_type
{
    t_string,
    t_i8,
    t_i16,
    t_i32,
    t_ui8,
    t_ui16,
    t_ui32,
    t_ui32,
    t_float,
};
typedef msg_value_type msgt;