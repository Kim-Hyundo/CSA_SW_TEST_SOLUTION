
#define CPUSS_BASE 0x40210000
#define CM4_PWR_CTL_OFFSET 0x80
#define CM4_VECTOR_TABLE_OFFSET 0x2C0

#define CM4_PWR_CTL_REG *((volatile unsigned int*)(CPUSS_BASE+CM4_PWR_CTL_OFFSET))
#define CM4_VECTOR_TABLE_REG *((volatile unsigned int*)(CPUSS_BASE+CM4_VECTOR_TABLE_OFFSET))

void disable_m4() {
	CM4_PWR_CTL_REG = 0x05fa0000;
}

void enable_m4_finished() {
	__asm volatile ("nop");
}

void enable_m4(unsigned int nM4Vtor) {
	CM4_VECTOR_TABLE_REG = nM4Vtor;
	CM4_PWR_CTL_REG = 0x05fa0003;
	enable_m4_finished();
}