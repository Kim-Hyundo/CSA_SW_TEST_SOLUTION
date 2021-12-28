$$${HEADERS}$$$


// -------------------------------------------------------------------------------

__far extern unsigned int _lc_gb_MY_FILLED_STACK0; 
__far extern unsigned int _lc_ge_MY_FILLED_STACK0;

__far extern unsigned int _lc_gb_MY_FILLED_STACK1;
__far extern unsigned int _lc_ge_MY_FILLED_STACK1;

__far extern unsigned int _lc_gb_MY_FILLED_STACK2;
__far extern unsigned int _lc_ge_MY_FILLED_STACK2;

#pragma optimize 0 

void Stack0_Fill(void)
{
    unsigned int *stackptr;
    unsigned int *user_stack_start;
    unsigned int *user_stack_end;
    
    user_stack_start = &_lc_gb_MY_FILLED_STACK0; 
    user_stack_end  = &_lc_ge_MY_FILLED_STACK0;
    
    for(stackptr = user_stack_start; stackptr < user_stack_end; stackptr++)
    {
        *stackptr = 0xA5A5A5A5; 
    }
}

void Stack1_Fill(void)
{
    unsigned int *stackptr;
    unsigned int *user_stack_start;
    unsigned int *user_stack_end;
    
    user_stack_start = &_lc_gb_MY_FILLED_STACK1; 
    user_stack_end  = &_lc_ge_MY_FILLED_STACK1;
    
    for(stackptr = user_stack_start; stackptr < user_stack_end; stackptr++)
    {
        *stackptr = 0xA5A5A5A5; 
    }
}

void Stack2_Fill(void)
{
    unsigned int *stackptr;
    unsigned int *user_stack_start;
    unsigned int *user_stack_end;
    
    user_stack_start = &_lc_gb_MY_FILLED_STACK2; 
    user_stack_end  = &_lc_ge_MY_FILLED_STACK2;
    
    for(stackptr = user_stack_start; stackptr < user_stack_end; stackptr++)
    {
        *stackptr = 0xA5A5A5A5; 
    }
}
#pragma endoptimize

// -------------------------------------------------------------------------------
$$${RUNNABLE_FLAGS}$$$

volatile void Check_Point(void) __at( 0x80000100 )
{
}
volatile unsigned int run_func_flag=0;

void main_core0(void)
{
    int loop_cnt = 1;
    Stack0_Fill();

$$${INITIALIZE_core0}$$$

    while(1)
    {

$$${RUNNABLES_core0}$$$

    }
}

void main_core1(void)
{
    int loop_cnt = 1;
    Stack1_Fill();
	
$$${INITIALIZE_core1}$$$

    while(1)
    {

$$${RUNNABLES_core1}$$$	

    }
}

void main_core2(void)
{
    int loop_cnt = 1;
    Stack2_Fill();

$$${INITIALIZE_core2}$$$

    while(1)
    {

$$${RUNNABLES_core2}$$$
    }
}
