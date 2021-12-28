$$${HEADERS}$$$


// -------------------------------------------------------------------------------

__far extern unsigned int _lc_gb_MY_FILLED_STACK0; 
__far extern unsigned int _lc_ge_MY_FILLED_STACK0;

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
#pragma endoptimize

// -------------------------------------------------------------------------------
$$${RUNNABLE_FLAGS}$$$

volatile void Check_Point(void) __at( 0x80000100 )
{
}


void main(void)
{
    int loop_cnt = 1;
    Stack0_Fill();

$$${INITIALIZE}$$$

    while(1)
    {
        Check_Point();
$$${RUNNABLES}$$$
        
        loop_cnt++;
        if(loop_cnt > 100)
            loop_cnt  = 1;
    }
}
