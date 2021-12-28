// TASKING VX-toolset for TriCore
// Eclipse project linker script file
// 
#if defined(__PROC_TC23X__)
#include "tc23x.lsl"

section_layout mpe:tc0:linear
{
	group MY_FILLED_STACK0 (run_addr=mem:mpe:dspr0)
	{
		select "ustack_tc0";
	}
}

#elif defined(__PROC_TC26XB__)
#include "tc26xb.lsl"

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

#elif defined(__PROC_TC27X__)
#include "tc27x.lsl"

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

#elif defined(__PROC_TC29X__)
#include "tc29x.lsl"

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
