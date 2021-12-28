$$${HEADERS}$$$
#include "cy_project.h"
#include "cy_device_headers.h"

#define BIT(nr) (1UL << (nr))

// -------------------------------------------------------------------------------

extern unsigned int __ghs_stackstart;
extern unsigned int __ghs_stackend;

#pragma optimize 0 

void Stack0_Fill(void)
{
    unsigned int *stackptr;
    unsigned int *user_stack_start;
    unsigned int *user_stack_end;
    
    user_stack_start = &__ghs_stackstart;
    user_stack_end  = &__ghs_stackend;
    
    for(stackptr = user_stack_start; stackptr < user_stack_end; stackptr++)
    {
        *stackptr = 0xA5A5A5A5; 
    }
}

#pragma endoptimize

// -------------------------------------------------------------------------------
$$${RUNNABLE_FLAGS}$$$

volatile int Check_Point(void)
{
    return 0;
}

volatile unsigned int run_func_flag=0;
$$${GLOBAL_VAR_FLAGS}$$$

enum func_list{
$$${ENUM_FUNCLIST_FLAGS}$$$
};

int main(void) //cm4
{
    int loop_cnt = 1;
    Stack0_Fill();

$$${INITIALIZE_cm4}$$$

    while(1)
    {

$$${RUNNABLES_cm4}$$$

    }
    return 0;
}
