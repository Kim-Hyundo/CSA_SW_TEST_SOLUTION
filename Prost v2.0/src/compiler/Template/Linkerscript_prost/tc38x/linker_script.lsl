// TASKING VX-toolset for TriCore
// Eclipse project linker script file
// 
#define RESET           0xA0000000              /* internal flash start address tc0 */
#ifndef USTACK_TC0
#define USTACK_TC0      16k                     /* user stack size tc0 */
#endif

#ifndef USTACK_TC1
#define USTACK_TC1      16k                      /* user stack size tc1 */
#endif

#ifndef USTACK_TC2
#define USTACK_TC2      16k                      /* user stack size tc2 */
#endif

#ifndef USTACK_TC3
#define USTACK_TC3      16k                      /* user stack size tc3 */
#endif


#if defined(__PROC_TC38X__)
#include "tc38x.lsl"

section_layout mpe:tc0:linear
{
	group MY_FILLED_STACK0 (run_addr=mem:mpe:dspr0)
	{
		select "ustack_tc0";
	}
}

section_layout mpe:tc1:linear
{
	group MY_FILLED_STACK1 (run_addr=mem:mpe:dspr1)
	{
		select "ustack_tc1";
	}
}

section_layout mpe:tc2:linear
{
	group MY_FILLED_STACK2 (run_addr=mem:mpe:dspr2)
	{
		select "ustack_tc2";
	}
}

section_layout mpe:tc3:linear
{
	group MY_FILLED_STACK3 (run_addr=mem:mpe:dspr3)
	{
		select "ustack_tc3";
	}
}

#else
#include <cpu.lsl>
#endif

section_layout mpe:vtc:abs18
{
### $$${SECTION_LAYOUT_abs18}$$$
}

section_layout mpe:vtc:linear
{
	group (run_addr=mem:mpe:pflash0)
    {
		select ".text._Exit*";
		select ".text._c_init*";
		select ".text._ldmst*";
		select ".text._trap*";
		select ".text.cstart*";
		select ".text.libc*";
		select ".text.test*";
		select ".text.main*";
	}
	
### $$${SECTION_LAYOUT_linear}$$$
	
}
