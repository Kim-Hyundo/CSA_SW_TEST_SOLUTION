"""
Program Name : modify_cstart_h.py
Author : Hyundo Kim
Date : 20.03.26
Description : Create Modified Startup Header File
"""

import pickle_api as pa

origin_data_tc = {}
origin_data_tc1 = {}
origin_data_tc2 = {}
origin_data_tc3 = {}
origin_data_tc4 = {}
origin_data_tc5 = {}

def tasking_v62_tc29x_h_default(dic_project_info):
    # tc0 header
    origin_data_tc['__BIV_INIT'] = "0x1"
    origin_data_tc['__BIV_SINGLE_INIT'] = "0x0"
    origin_data_tc['__BIV_8BYTE_INIT'] = "0x0"
    origin_data_tc['__BTV_INIT'] = "0x1"
    origin_data_tc['__CSA_INIT'] = "0x1"
    origin_data_tc['__C_INIT'] = "0x1"
    origin_data_tc['__USP_INIT'] = "0x1"
    origin_data_tc['__ISP_INIT'] = "0x1"
    origin_data_tc['__A0A1_INIT'] = "0x1"
    origin_data_tc['__A8A9_INIT'] = "0x1"
    origin_data_tc['__RM_INIT'] = "0x0"
    origin_data_tc['__RM_VALUE'] = "FE_TONEAREST"
    origin_data_tc['__CDC'] = "0x0"
    origin_data_tc['__USER_STACK'] = "0x1"
    origin_data_tc['__WATCHDOG_DISABLE'] = "0x1"
    origin_data_tc['__SAFETY_WATCHDOG_DISABLE'] = "0x1"
    origin_data_tc['__COMPAT'] = "0xf"
    origin_data_tc['__USE_ARGC_ARGV'] = "0x0"
    origin_data_tc['__ARGCV_BUFSIZE'] = "0x100"
    origin_data_tc['__CLOCKS_PER_SEC_INIT'] = "0x0"
    origin_data_tc['__fOSC'] = dic_project_info['Test_Env']['CPU_Clock']
    origin_data_tc['__PLL_K2_RAMPUP'] = "0x0"
    origin_data_tc['__START_INIT_TC1'] = "0x0"
    origin_data_tc['__START_INIT_TC2'] = "0x0"
    origin_data_tc['__START_INIT_TC3'] = "0x0"
    origin_data_tc['__START_INIT_TC4'] = "0x0"
    origin_data_tc['__START_INIT_TC5'] = "0x0"
    origin_data_tc['__RESOLVE_TRAP_0'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_1'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_2'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_3'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_4'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_5'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_6'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_7'] = "0x1"
    origin_data_tc['__XC800_INIT'] = "0x0"
    origin_data_tc['__EBU_BOOTCFG_INIT'] = "0x1"
    origin_data_tc['__EBU_BOOTCFG_VALUE'] = "0x800C"
    origin_data_tc['__PMI_CON0_INIT'] = "0x1"
    origin_data_tc['__PMI_CON0_VALUE'] = "0x0"
    origin_data_tc['__PMI_CON1_INIT'] = "0x0"
    origin_data_tc['__PMI_CON1_VALUE'] = "0x0"
    origin_data_tc['__PMI_CON2_INIT'] = "0x1"
    origin_data_tc['__PMI_CON2_VALUE'] = "0x0"
    origin_data_tc['__PMU_EIFCON_INIT'] = "0x0"
    origin_data_tc['__PMU_EIFCON_VALUE'] = "0x0"
    origin_data_tc['__DMI_CON_INIT'] = "0x1"
    origin_data_tc['__DMI_CON_VALUE'] = "0x0"
    origin_data_tc['__PLL_CLC_INIT'] = "0x0"
    origin_data_tc['__PLL_CLC_VALUE'] = "0x0"
    origin_data_tc['__SCU_PLLCON0_INIT'] = "0x0"
    origin_data_tc['__SCU_PLLCON0_VALUE'] = "0x0001c600"
    origin_data_tc['__SCU_SYSPLLCON0_INIT'] = "0x0"
    origin_data_tc['__SCU_SYSPLLCON0_VALUE'] = "0x0"
    origin_data_tc['__SCU_PLLCON1_INIT'] = "0x0"
    origin_data_tc['__SCU_PLLCON1_VALUE'] = "0x0002020f"
    origin_data_tc['__SCU_SYSPLLCON1_INIT'] = "0x0"
    origin_data_tc['__SCU_SYSPLLCON1_VALUE'] = "0x0"
    origin_data_tc['__SCU_OSCCON_INIT'] = "0x0"
    origin_data_tc['__SCU_OSCCON_VALUE'] = "0x00000010"
    origin_data_tc['__SCU_CCUCON0_INIT'] = "0x0"
    origin_data_tc['__SCU_CCUCON0_VALUE'] = "0x01120148"
    origin_data_tc['__SCU_CCUCON1_INIT'] = "0x0"
    origin_data_tc['__SCU_CCUCON1_VALUE'] = "0x00002211"
    origin_data_tc['__SCU_CCUCON2_INIT'] = "0x0"
    origin_data_tc['__SCU_CCUCON2_VALUE'] = "0x00000008"
    origin_data_tc['__STM_CLC_INIT'] = "0x0"
    origin_data_tc['__STM_CLC_VALUE'] = "0x0"
    origin_data_tc['__GTM_CLC_INIT'] = "0x1"
    origin_data_tc['__GTM_CLC_VALUE'] = "0x0"
    origin_data_tc['__FLASH0_FCON_INIT'] = "0x0"
    origin_data_tc['__FLASH0_FCON_VALUE'] = "0x00910000"
    origin_data_tc['__FLASH1_FCON_INIT'] = "0x0"
    origin_data_tc['__FLASH1_FCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL0_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL0_VALUE'] = "0xa0000001"
    origin_data_tc['__EBU_ADDRSEL1_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL1_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL2_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL2_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL3_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL3_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL4_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL4_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL5_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL5_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL6_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL6_VALUE'] = "0x0"
    origin_data_tc['__EBU_BFCON_INIT'] = "0x0"
    origin_data_tc['__EBU_BFCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP0_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP1_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP2_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP3_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP4_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP4_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP5_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP5_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP6_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP6_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON0_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON1_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON2_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON3_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON4_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON4_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON5_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON5_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON6_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON6_VALUE'] = "0x0"
    origin_data_tc['__EBU_CLC_INIT'] = "0x0"
    origin_data_tc['__EBU_CLC_VALUE'] = "0x00550000"
    origin_data_tc['__EBU_CON_INIT'] = "0x0"
    origin_data_tc['__EBU_CON_VALUE'] = "0x0"
    origin_data_tc['__EBU_EMUAS_INIT'] = "0x0"
    origin_data_tc['__EBU_EMUAS_VALUE'] = "0x0"
    origin_data_tc['__EBU_EMUBAP_INIT'] = "0x0"
    origin_data_tc['__EBU_EMUBAP_VALUE'] = "0x0"
    origin_data_tc['__EBU_EMUBC_INIT'] = "0x0"
    origin_data_tc['__EBU_EMUBC_VALUE'] = "0x0"
    origin_data_tc['__EBU_EMUCON_INIT'] = "0x0"
    origin_data_tc['__EBU_EMUCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_EMUOVL_INIT'] = "0x0"
    origin_data_tc['__EBU_EMUOVL_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMCON0_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMCON0_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMCON1_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMCON1_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMOD0_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMOD0_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMOD1_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMOD1_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMREF0_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMREF0_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMREF1_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMREF1_VALUE'] = "0x0"
    origin_data_tc['__CBS_MCDBBS_INIT'] = "0x0"
    origin_data_tc['__CBS_MCDBBS_VALUE'] = "0x0"
    origin_data_tc['__SBCU_CON_INIT'] = "0x0"
    origin_data_tc['__SBCU_CON_VALUE'] = "0xff09ffff"
    origin_data_tc['__EBU_BUSRAP1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRAP1_VALUE'] = "0xffffffff"
    origin_data_tc['__EBU_BUSRAP0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRAP0_VALUE'] = "0xffffffff"
    origin_data_tc['__EBU_BUSRAP2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRAP2_VALUE'] = "0xffffffff"
    origin_data_tc['__EBU_BUSRAP3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRAP3_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSRCON0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRCON0_VALUE'] = "0x00d30040"
    origin_data_tc['__EBU_BUSRCON1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRCON1_VALUE'] = "0x00d30040"
    origin_data_tc['__EBU_BUSRCON2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRCON2_VALUE'] = "0x00d30040"
    origin_data_tc['__EBU_BUSRCON3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRCON3_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSWAP0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWAP0_VALUE'] = "0xffffffff"
    origin_data_tc['__EBU_BUSWAP1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWAP1_VALUE'] = "0xffffffff"
    origin_data_tc['__EBU_BUSWAP2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWAP2_VALUE'] = "0xffffffff"
    origin_data_tc['__EBU_BUSWAP3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWAP3_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSWCON0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWCON0_VALUE'] = "0x00d30000"
    origin_data_tc['__EBU_BUSWCON1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWCON1_VALUE'] = "0x00d30000"
    origin_data_tc['__EBU_BUSWCON2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWCON2_VALUE'] = "0x00d30000"
    origin_data_tc['__EBU_BUSWCON3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWCON3_VALUE'] = "0x0"
    origin_data_tc['__EBU_EXTBOOT_INIT'] = "0x0"
    origin_data_tc['__EBU_EXTBOOT_VALUE'] = "0x00000001"
    origin_data_tc['__EBU_MODCON_INIT'] = "0x0"
    origin_data_tc['__EBU_MODCON_VALUE'] = "0x00000020"
    origin_data_tc['__EBU_DDRNCON_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNMOD_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNMOD_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNMOD2_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNMOD2_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNPRLD_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNPRLD_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG0_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG0_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG1_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG1_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG2_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG2_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG3_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG3_VALUE'] = "0x0"
    origin_data_tc['__EBU_DLLCON_INIT'] = "0x0"
    origin_data_tc['__EBU_DLLCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMCON_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMCON_VALUE'] = "0x10000000"
    origin_data_tc['__EBU_SDRMOD_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMOD_VALUE'] = "0x00000020"
    origin_data_tc['__EBU_SDRMREF_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMREF_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRSTAT_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRSTAT_VALUE'] = "0x0"
    origin_data_tc['__P24_PDR0_INIT'] = "0x0"
    origin_data_tc['__P24_PDR0_VALUE'] = "0x33333333"
    origin_data_tc['__P24_PDR1_INIT'] = "0x0"
    origin_data_tc['__P24_PDR1_VALUE'] = "0x33333333"
    origin_data_tc['__P25_PDR0_INIT'] = "0x0"
    origin_data_tc['__P25_PDR0_VALUE'] = "0x33333333"
    origin_data_tc['__P25_PDR1_INIT'] = "0x0"
    origin_data_tc['__P25_PDR1_VALUE'] = "0x33333333"
    origin_data_tc['__P30_PDR0_INIT'] = "0x0"
    origin_data_tc['__P30_PDR0_VALUE'] = "0x33333333"
    origin_data_tc['__P30_PDR1_INIT'] = "0x0"
    origin_data_tc['__P30_PDR1_VALUE'] = "0x33333333"
    origin_data_tc['__P31_PDR0_INIT'] = "0x0"
    origin_data_tc['__P31_PDR0_VALUE'] = "0x33333333"
    origin_data_tc['__P31_PDR1_INIT'] = "0x0"
    origin_data_tc['__P31_PDR1_VALUE'] = "0x33333333"
    origin_data_tc['__PCON0_INIT'] = "0x1"
    origin_data_tc['__PCON0_VALUE'] = "0x0"
    origin_data_tc['__DCON0_INIT'] = "0x1"
    origin_data_tc['__DCON0_VALUE'] = "0x0"

    #tc1 header
    origin_data_tc1['__BIV_TC1_INIT'] = "0x1"
    origin_data_tc1['__BIV_SINGLE_TC1_INIT'] = "0x0"
    origin_data_tc1['__BIV_8BYTE_TC1_INIT'] = "0x0"
    origin_data_tc1['__BTV_TC1_INIT'] = "0x1"
    origin_data_tc1['__CSA_TC1_INIT'] = "0x1"
    origin_data_tc1['__C_TC1_INIT'] = "0x1"
    origin_data_tc1['__USP_TC1_INIT'] = "0x1"
    origin_data_tc1['__ISP_TC1_INIT'] = "0x1"
    origin_data_tc1['__A0A1_TC1_INIT'] = "0x1"
    origin_data_tc1['__A8A9_TC1_INIT'] = "0x1"
    origin_data_tc1['__RM_TC1_INIT'] = "0x0"
    origin_data_tc1['__RM_TC1_VALUE'] = "FE_TONEAREST"
    origin_data_tc1['__CDC_TC1'] = "0x0"
    origin_data_tc1['__USER_STACK_TC1'] = "0x1"
    origin_data_tc1['__COMPAT_TC1'] = "0xf"
    origin_data_tc1['__USE_ARGC_ARGV_TC1'] = "0x0"
    origin_data_tc1['__ARGCV_BUFSIZE_TC1'] = "0x100"
    origin_data_tc1['__RESOLVE_TRAP_0_TC1'] = "0x1"
    origin_data_tc1['__RESOLVE_TRAP_1_TC1'] = "0x1"
    origin_data_tc1['__RESOLVE_TRAP_2_TC1'] = "0x1"
    origin_data_tc1['__RESOLVE_TRAP_3_TC1'] = "0x1"
    origin_data_tc1['__RESOLVE_TRAP_4_TC1'] = "0x1"
    origin_data_tc1['__RESOLVE_TRAP_5_TC1'] = "0x1"
    origin_data_tc1['__RESOLVE_TRAP_6_TC1'] = "0x1"
    origin_data_tc1['__RESOLVE_TRAP_7_TC1'] = "0x1"
    origin_data_tc1['__PCON0_INIT'] = "0x1"
    origin_data_tc1['__PCON0_VALUE'] = "0x0"
    origin_data_tc1['__DCON0_INIT'] = "0x1"
    origin_data_tc1['__DCON0_VALUE'] = "0x0"

    # tc2 header
    origin_data_tc2['__BIV_TC2_INIT'] = "0x1"
    origin_data_tc2['__BIV_SINGLE_TC2_INIT'] = "0x0"
    origin_data_tc2['__BIV_8BYTE_TC2_INIT'] = "0x0"
    origin_data_tc2['__BTV_TC2_INIT'] = "0x1"
    origin_data_tc2['__CSA_TC2_INIT'] = "0x1"
    origin_data_tc2['__C_TC2_INIT'] = "0x1"
    origin_data_tc2['__USP_TC2_INIT'] = "0x1"
    origin_data_tc2['__ISP_TC2_INIT'] = "0x1"
    origin_data_tc2['__A0A1_TC2_INIT'] = "0x1"
    origin_data_tc2['__A8A9_TC2_INIT'] = "0x1"
    origin_data_tc2['__RM_TC2_INIT'] = "0x0"
    origin_data_tc2['__RM_TC2_VALUE'] = "FE_TONEAREST"
    origin_data_tc2['__CDC_TC2'] = "0x0"
    origin_data_tc2['__USER_STACK_TC2'] = "0x1"
    origin_data_tc2['__COMPAT_TC2'] = "0xf"
    origin_data_tc2['__USE_ARGC_ARGV_TC2'] = "0x0"
    origin_data_tc2['__ARGCV_BUFSIZE_TC2'] = "0x100"
    origin_data_tc2['__RESOLVE_TRAP_0_TC2'] = "0x1"
    origin_data_tc2['__RESOLVE_TRAP_1_TC2'] = "0x1"
    origin_data_tc2['__RESOLVE_TRAP_2_TC2'] = "0x1"
    origin_data_tc2['__RESOLVE_TRAP_3_TC2'] = "0x1"
    origin_data_tc2['__RESOLVE_TRAP_4_TC2'] = "0x1"
    origin_data_tc2['__RESOLVE_TRAP_5_TC2'] = "0x1"
    origin_data_tc2['__RESOLVE_TRAP_6_TC2'] = "0x1"
    origin_data_tc2['__RESOLVE_TRAP_7_TC2'] = "0x1"
    origin_data_tc2['__PCON0_INIT'] = "0x1"
    origin_data_tc2['__PCON0_VALUE'] = "0x0"
    origin_data_tc2['__DCON0_INIT'] = "0x1"
    origin_data_tc2['__DCON0_VALUE'] = "0x0"

def tasking_v42_tc29x_h_default(dic_project_info):
    # tc0 header
    origin_data_tc['__BIV_INIT'] = "0x1"
    origin_data_tc['__BIV_SINGLE_INIT'] = "0x0"
    origin_data_tc['__BIV_8BYTE_INIT'] = "0x0"
    origin_data_tc['__BTV_INIT'] = "0x1"
    origin_data_tc['__CSA_INIT'] = "0x1"
    origin_data_tc['__C_INIT'] = "0x1"
    origin_data_tc['__USP_INIT'] = "0x1"
    origin_data_tc['__ISP_INIT'] = "0x1"
    origin_data_tc['__A0A1_INIT'] = "0x1"
    origin_data_tc['__A8A9_INIT'] = "0x1"
    origin_data_tc['__USER_STACK'] = "0x1"
    origin_data_tc['__WATCHDOG_DISABLE'] = "0x1"
    origin_data_tc['__SAFETY_WATCHDOG_DISABLE'] = "0x1"
    origin_data_tc['__USE_ARGC_ARGV'] = "0x0"
    origin_data_tc['__ARGCV_BUFSIZE'] = "0x100"
    origin_data_tc['__CLOCKS_PER_SEC_INIT'] = "0x0"
    origin_data_tc['__fOSC'] = dic_project_info['Test_Env']['CPU_Clock']
    origin_data_tc['__PLL_K2_RAMPUP'] = "0x0"
    origin_data_tc['__STADD_INIT_TC1'] = "0x1"
    origin_data_tc['__STADD_INIT_TC2'] = "0x1"
    origin_data_tc['__HALT_INIT_TC1'] = "0x0"
    origin_data_tc['__HALT_INIT_TC2'] = "0x0"
    origin_data_tc['__HALT_VALUE_TC1'] = "0x0"
    origin_data_tc['__HALT_VALUE_TC2'] = "0x0"
    origin_data_tc['__RESOLVE_TRAP_0'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_1'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_2'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_3'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_4'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_5'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_6'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_7'] = "0x1"
    origin_data_tc['__EBU_BOOTCFG_INIT'] = "0x1"
    origin_data_tc['__EBU_BOOTCFG_VALUE'] = "0x800C"
    origin_data_tc['__PMI_CON0_INIT'] = "0x1"
    origin_data_tc['__PMI_CON0_VALUE'] = "0x0"
    origin_data_tc['__PMI_CON1_INIT'] = "0x0"
    origin_data_tc['__PMI_CON1_VALUE'] = "0x0"
    origin_data_tc['__PMI_CON2_INIT'] = "0x1"
    origin_data_tc['__PMI_CON2_VALUE'] = "0x0"
    origin_data_tc['__PMU_EIFCON_INIT'] = "0x0"
    origin_data_tc['__PMU_EIFCON_VALUE'] = "0x0"
    origin_data_tc['__DMI_CON_INIT'] = "0x1"
    origin_data_tc['__DMI_CON_VALUE'] = "0x0"
    origin_data_tc['__PLL_CLC_INIT'] = "0x0"
    origin_data_tc['__PLL_CLC_VALUE'] = "0x0"
    origin_data_tc['__SCU_PLLCON0_INIT'] = "0x0"
    origin_data_tc['__SCU_PLLCON0_VALUE'] = "0x0001c600"
    origin_data_tc['__SCU_PLLCON1_INIT'] = "0x0"
    origin_data_tc['__SCU_PLLCON1_VALUE'] = "0x0002000f"
    origin_data_tc['__SCU_OSCCON_INIT'] = "0x0"
    origin_data_tc['__SCU_OSCCON_VALUE'] = "0x00000010"
    origin_data_tc['__SCU_CCUCON0_INIT'] = "0x0"
    origin_data_tc['__SCU_CCUCON0_VALUE'] = "0x02020112"
    origin_data_tc['__SCU_CCUCON1_INIT'] = "0x0"
    origin_data_tc['__SCU_CCUCON1_VALUE'] = "0x00002211"
    origin_data_tc['__SCU_CCUCON2_INIT'] = "0x0"
    origin_data_tc['__SCU_CCUCON2_VALUE'] = "0x00000008"
    origin_data_tc['__STM_CLC_INIT'] = "0x0"
    origin_data_tc['__STM_CLC_VALUE'] = "0x0"
    origin_data_tc['__GTM_CLC_INIT'] = "0x1"
    origin_data_tc['__GTM_CLC_VALUE'] = "0x0"
    origin_data_tc['__FLASH0_FCON_INIT'] = "0x0"
    origin_data_tc['__FLASH0_FCON_VALUE'] = "0x00a12b6a"
    origin_data_tc['__FLASH1_FCON_INIT'] = "0x0"
    origin_data_tc['__FLASH1_FCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL0_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL0_VALUE'] = "0xa0000001"
    origin_data_tc['__EBU_ADDRSEL1_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL1_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL2_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL2_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL3_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL3_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL4_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL4_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL5_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL5_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL6_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL6_VALUE'] = "0x0"
    origin_data_tc['__EBU_BFCON_INIT'] = "0x0"
    origin_data_tc['__EBU_BFCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP0_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP1_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP2_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP3_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP4_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP4_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP5_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP5_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP6_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP6_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON0_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON1_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON2_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON3_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON4_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON4_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON5_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON5_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON6_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON6_VALUE'] = "0x0"
    origin_data_tc['__EBU_CLC_INIT'] = "0x0"
    origin_data_tc['__EBU_CLC_VALUE'] = "0x00550000"
    origin_data_tc['__EBU_CON_INIT'] = "0x0"
    origin_data_tc['__EBU_CON_VALUE'] = "0x0"
    origin_data_tc['__EBU_EMUAS_INIT'] = "0x0"
    origin_data_tc['__EBU_EMUAS_VALUE'] = "0x0"
    origin_data_tc['__EBU_EMUBAP_INIT'] = "0x0"
    origin_data_tc['__EBU_EMUBAP_VALUE'] = "0x0"
    origin_data_tc['__EBU_EMUBC_INIT'] = "0x0"
    origin_data_tc['__EBU_EMUBC_VALUE'] = "0x0"
    origin_data_tc['__EBU_EMUCON_INIT'] = "0x0"
    origin_data_tc['__EBU_EMUCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_EMUOVL_INIT'] = "0x0"
    origin_data_tc['__EBU_EMUOVL_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMCON0_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMCON0_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMCON1_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMCON1_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMOD0_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMOD0_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMOD1_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMOD1_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMREF0_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMREF0_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMREF1_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMREF1_VALUE'] = "0x0"
    origin_data_tc['__CBS_MCDBBS_INIT'] = "0x0"
    origin_data_tc['__CBS_MCDBBS_VALUE'] = "0x0"
    origin_data_tc['__SBCU_CON_INIT'] = "0x0"
    origin_data_tc['__SBCU_CON_VALUE'] = "0xff09ffff"
    origin_data_tc['__EBU_BUSRAP1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRAP1_VALUE'] = "0xffffffff"
    origin_data_tc['__EBU_BUSRAP0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRAP0_VALUE'] = "0xffffffff"
    origin_data_tc['__EBU_BUSRAP2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRAP2_VALUE'] = "0xffffffff"
    origin_data_tc['__EBU_BUSRAP3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRAP3_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSRCON0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRCON0_VALUE'] = "0x00d30040"
    origin_data_tc['__EBU_BUSRCON1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRCON1_VALUE'] = "0x00d30040"
    origin_data_tc['__EBU_BUSRCON2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRCON2_VALUE'] = "0x00d30040"
    origin_data_tc['__EBU_BUSRCON3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRCON3_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSWAP0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWAP0_VALUE'] = "0xffffffff"
    origin_data_tc['__EBU_BUSWAP1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWAP1_VALUE'] = "0xffffffff"
    origin_data_tc['__EBU_BUSWAP2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWAP2_VALUE'] = "0xffffffff"
    origin_data_tc['__EBU_BUSWAP3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWAP3_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSWCON0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWCON0_VALUE'] = "0x00d30000"
    origin_data_tc['__EBU_BUSWCON1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWCON1_VALUE'] = "0x00d30000"
    origin_data_tc['__EBU_BUSWCON2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWCON2_VALUE'] = "0x00d30000"
    origin_data_tc['__EBU_BUSWCON3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWCON3_VALUE'] = "0x0"
    origin_data_tc['__EBU_EXTBOOT_INIT'] = "0x0"
    origin_data_tc['__EBU_EXTBOOT_VALUE'] = "0x00000001"
    origin_data_tc['__EBU_MODCON_INIT'] = "0x0"
    origin_data_tc['__EBU_MODCON_VALUE'] = "0x30000020"
    origin_data_tc['__EBU_DDRNCON_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNMOD_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNMOD_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNMOD2_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNMOD2_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNPRLD_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNPRLD_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG0_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG0_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG1_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG1_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG2_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG2_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG3_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG3_VALUE'] = "0x0"
    origin_data_tc['__EBU_DLLCON_INIT'] = "0x0"
    origin_data_tc['__EBU_DLLCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMCON_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMCON_VALUE'] = "0x10000000"
    origin_data_tc['__EBU_SDRMOD_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMOD_VALUE'] = "0x00000020"
    origin_data_tc['__EBU_SDRMREF_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMREF_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRSTAT_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRSTAT_VALUE'] = "0x0"
    origin_data_tc['__PCON0_INIT'] = "0x1"
    origin_data_tc['__PCON0_VALUE'] = "0x0"
    origin_data_tc['__DCON0_INIT'] = "0x1"
    origin_data_tc['__DCON0_VALUE'] = "0x0"

    #tc1 header
    origin_data_tc1['__BIV_TC1_INIT'] = "0x1"
    origin_data_tc1['__BIV_SINGLE_TC1_INIT'] = "0x0"
    origin_data_tc1['__BIV_8BYTE_TC1_INIT'] = "0x0"
    origin_data_tc1['__BTV_TC1_INIT'] = "0x1"
    origin_data_tc1['__CSA_TC1_INIT'] = "0x1"
    origin_data_tc1['__C_TC1_INIT'] = "0x1"
    origin_data_tc1['__USP_TC1_INIT'] = "0x1"
    origin_data_tc1['__ISP_TC1_INIT'] = "0x1"
    origin_data_tc1['__A0A1_TC1_INIT'] = "0x1"
    origin_data_tc1['__A8A9_TC1_INIT'] = "0x1"
    origin_data_tc1['__USER_STACK_TC1'] = "0x1"
    origin_data_tc1['__USE_ARGC_ARGV_TC1'] = "0x0"
    origin_data_tc1['__ARGCV_BUFSIZE_TC1'] = "0x100"
    origin_data_tc1['__RESOLVE_TRAP_0_TC1'] = "0x1"
    origin_data_tc1['__RESOLVE_TRAP_1_TC1'] = "0x1"
    origin_data_tc1['__RESOLVE_TRAP_2_TC1'] = "0x1"
    origin_data_tc1['__RESOLVE_TRAP_3_TC1'] = "0x1"
    origin_data_tc1['__RESOLVE_TRAP_4_TC1'] = "0x1"
    origin_data_tc1['__RESOLVE_TRAP_5_TC1'] = "0x1"
    origin_data_tc1['__RESOLVE_TRAP_6_TC1'] = "0x1"
    origin_data_tc1['__RESOLVE_TRAP_7_TC1'] = "0x1"
    origin_data_tc1['__PCON0_INIT'] = "0x1"
    origin_data_tc1['__PCON0_VALUE'] = "0x0"
    origin_data_tc1['__DCON0_INIT'] = "0x1"
    origin_data_tc1['__DCON0_VALUE'] = "0x0"

    # tc2 header
    origin_data_tc2['__BIV_TC2_INIT'] = "0x1"
    origin_data_tc2['__BIV_SINGLE_TC2_INIT'] = "0x0"
    origin_data_tc2['__BIV_8BYTE_TC2_INIT'] = "0x0"
    origin_data_tc2['__BTV_TC2_INIT'] = "0x1"
    origin_data_tc2['__CSA_TC2_INIT'] = "0x1"
    origin_data_tc2['__C_TC2_INIT'] = "0x1"
    origin_data_tc2['__USP_TC2_INIT'] = "0x1"
    origin_data_tc2['__ISP_TC2_INIT'] = "0x1"
    origin_data_tc2['__A0A1_TC2_INIT'] = "0x1"
    origin_data_tc2['__A8A9_TC2_INIT'] = "0x1"
    origin_data_tc2['__USER_STACK_TC2'] = "0x1"
    origin_data_tc2['__USE_ARGC_ARGV_TC2'] = "0x0"
    origin_data_tc2['__ARGCV_BUFSIZE_TC2'] = "0x100"
    origin_data_tc2['__RESOLVE_TRAP_0_TC2'] = "0x1"
    origin_data_tc2['__RESOLVE_TRAP_1_TC2'] = "0x1"
    origin_data_tc2['__RESOLVE_TRAP_2_TC2'] = "0x1"
    origin_data_tc2['__RESOLVE_TRAP_3_TC2'] = "0x1"
    origin_data_tc2['__RESOLVE_TRAP_4_TC2'] = "0x1"
    origin_data_tc2['__RESOLVE_TRAP_5_TC2'] = "0x1"
    origin_data_tc2['__RESOLVE_TRAP_6_TC2'] = "0x1"
    origin_data_tc2['__RESOLVE_TRAP_7_TC2'] = "0x1"
    origin_data_tc2['__PCON0_INIT'] = "0x1"
    origin_data_tc2['__PCON0_VALUE'] = "0x0"
    origin_data_tc2['__DCON0_INIT'] = "0x1"
    origin_data_tc2['__DCON0_VALUE'] = "0x0"

def tasking_v43_tc27x_h_default(dic_project_info):
    # tc0 header
    origin_data_tc['__BIV_INIT'] = "0x1"
    origin_data_tc['__BIV_SINGLE_INIT'] = "0x0"
    origin_data_tc['__BIV_8BYTE_INIT'] = "0x0"
    origin_data_tc['__BTV_INIT'] = "0x1"
    origin_data_tc['__CSA_INIT'] = "0x1"
    origin_data_tc['__C_INIT'] = "0x1"
    origin_data_tc['__USP_INIT'] = "0x1"
    origin_data_tc['__ISP_INIT'] = "0x1"
    origin_data_tc['__A0A1_INIT'] = "0x1"
    origin_data_tc['__A8A9_INIT'] = "0x1"
    origin_data_tc['__USER_STACK'] = "0x1"
    origin_data_tc['__WATCHDOG_DISABLE'] = "0x1"
    origin_data_tc['__SAFETY_WATCHDOG_DISABLE'] = "0x1"
    origin_data_tc['__USE_ARGC_ARGV'] = "0x0"
    origin_data_tc['__ARGCV_BUFSIZE'] = "0x100"
    origin_data_tc['__CLOCKS_PER_SEC_INIT'] = "0x0"
    origin_data_tc['__fOSC'] = dic_project_info['Test_Env']['CPU_Clock']
    origin_data_tc['__PLL_K2_RAMPUP'] = "0x0"
    origin_data_tc['__STADD_INIT_TC1'] = "0x1"
    origin_data_tc['__STADD_INIT_TC2'] = "0x1"
    origin_data_tc['__HALT_INIT_TC1'] = "0x0"
    origin_data_tc['__HALT_INIT_TC2'] = "0x0"
    origin_data_tc['__HALT_VALUE_TC1'] = "0x0"
    origin_data_tc['__HALT_VALUE_TC2'] = "0x0"
    origin_data_tc['__RESOLVE_TRAP_0'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_1'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_2'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_3'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_4'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_5'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_6'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_7'] = "0x1"
    origin_data_tc['__EBU_BOOTCFG_INIT'] = "0x1"
    origin_data_tc['__EBU_BOOTCFG_VALUE'] = "0x800C"
    origin_data_tc['__PMI_CON0_INIT'] = "0x1"
    origin_data_tc['__PMI_CON0_VALUE'] = "0x0"
    origin_data_tc['__PMI_CON1_INIT'] = "0x0"
    origin_data_tc['__PMI_CON1_VALUE'] = "0x0"
    origin_data_tc['__PMI_CON2_INIT'] = "0x1"
    origin_data_tc['__PMI_CON2_VALUE'] = "0x0"
    origin_data_tc['__PMU_EIFCON_INIT'] = "0x0"
    origin_data_tc['__PMU_EIFCON_VALUE'] = "0x0"
    origin_data_tc['__DMI_CON_INIT'] = "0x1"
    origin_data_tc['__DMI_CON_VALUE'] = "0x0"
    origin_data_tc['__PLL_CLC_INIT'] = "0x0"
    origin_data_tc['__PLL_CLC_VALUE'] = "0x0"
    origin_data_tc['__SCU_PLLCON0_INIT'] = "0x0"
    origin_data_tc['__SCU_PLLCON0_VALUE'] = "0x0001c600"
    origin_data_tc['__SCU_PLLCON1_INIT'] = "0x0"
    origin_data_tc['__SCU_PLLCON1_VALUE'] = "0x0002000f"
    origin_data_tc['__SCU_OSCCON_INIT'] = "0x0"
    origin_data_tc['__SCU_OSCCON_VALUE'] = "0x0000001c"
    origin_data_tc['__SCU_CCUCON0_INIT'] = "0x0"
    origin_data_tc['__SCU_CCUCON0_VALUE'] = "0x03040404"
    origin_data_tc['__SCU_CCUCON1_INIT'] = "0x0"
    origin_data_tc['__SCU_CCUCON1_VALUE'] = "0x00002211"
    origin_data_tc['__SCU_CCUCON2_INIT'] = "0x0"
    origin_data_tc['__SCU_CCUCON2_VALUE'] = "0x000004b4"
    origin_data_tc['__STM_CLC_INIT'] = "0x0"
    origin_data_tc['__STM_CLC_VALUE'] = "0x0"
    origin_data_tc['__GTM_CLC_INIT'] = "0x1"
    origin_data_tc['__GTM_CLC_VALUE'] = "0x0"
    origin_data_tc['__FLASH0_FCON_INIT'] = "0x0"
    origin_data_tc['__FLASH0_FCON_VALUE'] = "0x00a12b6a"
    origin_data_tc['__FLASH1_FCON_INIT'] = "0x0"
    origin_data_tc['__FLASH1_FCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL0_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL0_VALUE'] = "0x00000001"
    origin_data_tc['__EBU_ADDRSEL1_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL1_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL2_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL2_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL3_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL3_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL4_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL4_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL5_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL5_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL6_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL6_VALUE'] = "0x0"
    origin_data_tc['__EBU_BFCON_INIT'] = "0x0"
    origin_data_tc['__EBU_BFCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP0_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP1_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP2_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP3_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP4_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP4_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP5_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP5_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP6_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP6_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON0_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON1_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON2_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON3_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON4_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON4_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON5_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON5_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON6_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON6_VALUE'] = "0x0"
    origin_data_tc['__EBU_CLC_INIT'] = "0x0"
    origin_data_tc['__EBU_CLC_VALUE'] = "0x00000000"
    origin_data_tc['__EBU_CON_INIT'] = "0x0"
    origin_data_tc['__EBU_CON_VALUE'] = "0x0"
    origin_data_tc['__EBU_EMUAS_INIT'] = "0x0"
    origin_data_tc['__EBU_EMUAS_VALUE'] = "0x0"
    origin_data_tc['__EBU_EMUBAP_INIT'] = "0x0"
    origin_data_tc['__EBU_EMUBAP_VALUE'] = "0x0"
    origin_data_tc['__EBU_EMUBC_INIT'] = "0x0"
    origin_data_tc['__EBU_EMUBC_VALUE'] = "0x0"
    origin_data_tc['__EBU_EMUCON_INIT'] = "0x0"
    origin_data_tc['__EBU_EMUCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_EMUOVL_INIT'] = "0x0"
    origin_data_tc['__EBU_EMUOVL_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMCON0_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMCON0_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMCON1_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMCON1_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMOD0_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMOD0_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMOD1_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMOD1_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMREF0_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMREF0_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMREF1_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMREF1_VALUE'] = "0x0"
    origin_data_tc['__CBS_MCDBBS_INIT'] = "0x0"
    origin_data_tc['__CBS_MCDBBS_VALUE'] = "0x0"
    origin_data_tc['__SBCU_CON_INIT'] = "0x0"
    origin_data_tc['__SBCU_CON_VALUE'] = "0xff09ffff"
    origin_data_tc['__EBU_BUSRAP1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRAP1_VALUE'] = "0x00000000"
    origin_data_tc['__EBU_BUSRAP0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRAP0_VALUE'] = "0x00000000"
    origin_data_tc['__EBU_BUSRAP2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRAP2_VALUE'] = "0x00000000"
    origin_data_tc['__EBU_BUSRAP3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRAP3_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSRCON0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRCON0_VALUE'] = "0x00000000"
    origin_data_tc['__EBU_BUSRCON1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRCON1_VALUE'] = "0x00000000"
    origin_data_tc['__EBU_BUSRCON2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRCON2_VALUE'] = "0x00000000"
    origin_data_tc['__EBU_BUSRCON3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRCON3_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSWAP0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWAP0_VALUE'] = "0x00000000"
    origin_data_tc['__EBU_BUSWAP1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWAP1_VALUE'] = "0x00000000"
    origin_data_tc['__EBU_BUSWAP2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWAP2_VALUE'] = "0x00000000"
    origin_data_tc['__EBU_BUSWAP3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWAP3_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSWCON0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWCON0_VALUE'] = "0x00000000"
    origin_data_tc['__EBU_BUSWCON1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWCON1_VALUE'] = "0x00000000"
    origin_data_tc['__EBU_BUSWCON2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWCON2_VALUE'] = "0x00000000"
    origin_data_tc['__EBU_BUSWCON3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWCON3_VALUE'] = "0x0"
    origin_data_tc['__EBU_EXTBOOT_INIT'] = "0x0"
    origin_data_tc['__EBU_EXTBOOT_VALUE'] = "0x00000000"
    origin_data_tc['__EBU_MODCON_INIT'] = "0x0"
    origin_data_tc['__EBU_MODCON_VALUE'] = "0x00000000"
    origin_data_tc['__EBU_DDRNCON_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNMOD_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNMOD_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNMOD2_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNMOD2_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNPRLD_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNPRLD_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG0_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG0_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG1_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG1_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG2_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG2_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG3_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG3_VALUE'] = "0x0"
    origin_data_tc['__EBU_DLLCON_INIT'] = "0x0"
    origin_data_tc['__EBU_DLLCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMCON_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMCON_VALUE'] = "0x00000000"
    origin_data_tc['__EBU_SDRMOD_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMOD_VALUE'] = "0x00000000"
    origin_data_tc['__EBU_SDRMREF_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMREF_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRSTAT_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRSTAT_VALUE'] = "0x0"
    origin_data_tc['__PCON0_INIT'] = "0x1"
    origin_data_tc['__PCON0_VALUE'] = "0x0"
    origin_data_tc['__DCON0_INIT'] = "0x1"
    origin_data_tc['__DCON0_VALUE'] = "0x0"

    #tc1 header
    origin_data_tc1['__BIV_TC1_INIT'] = "0x1"
    origin_data_tc1['__BIV_SINGLE_TC1_INIT'] = "0x0"
    origin_data_tc1['__BIV_8BYTE_TC1_INIT'] = "0x0"
    origin_data_tc1['__BTV_TC1_INIT'] = "0x1"
    origin_data_tc1['__CSA_TC1_INIT'] = "0x1"
    origin_data_tc1['__C_TC1_INIT'] = "0x1"
    origin_data_tc1['__USP_TC1_INIT'] = "0x1"
    origin_data_tc1['__ISP_TC1_INIT'] = "0x1"
    origin_data_tc1['__A0A1_TC1_INIT'] = "0x1"
    origin_data_tc1['__A8A9_TC1_INIT'] = "0x1"
    origin_data_tc1['__USER_STACK_TC1'] = "0x1"
    origin_data_tc1['__USE_ARGC_ARGV_TC1'] = "0x0"
    origin_data_tc1['__ARGCV_BUFSIZE_TC1'] = "0x100"
    origin_data_tc1['__RESOLVE_TRAP_0_TC1'] = "0x1"
    origin_data_tc1['__RESOLVE_TRAP_1_TC1'] = "0x1"
    origin_data_tc1['__RESOLVE_TRAP_2_TC1'] = "0x1"
    origin_data_tc1['__RESOLVE_TRAP_3_TC1'] = "0x1"
    origin_data_tc1['__RESOLVE_TRAP_4_TC1'] = "0x1"
    origin_data_tc1['__RESOLVE_TRAP_5_TC1'] = "0x1"
    origin_data_tc1['__RESOLVE_TRAP_6_TC1'] = "0x1"
    origin_data_tc1['__RESOLVE_TRAP_7_TC1'] = "0x1"
    origin_data_tc1['__PCON0_INIT'] = "0x1"
    origin_data_tc1['__PCON0_VALUE'] = "0x0"
    origin_data_tc1['__DCON0_INIT'] = "0x1"
    origin_data_tc1['__DCON0_VALUE'] = "0x0"

    # tc2 header
    origin_data_tc2['__BIV_TC2_INIT'] = "0x1"
    origin_data_tc2['__BIV_SINGLE_TC2_INIT'] = "0x0"
    origin_data_tc2['__BIV_8BYTE_TC2_INIT'] = "0x0"
    origin_data_tc2['__BTV_TC2_INIT'] = "0x1"
    origin_data_tc2['__CSA_TC2_INIT'] = "0x1"
    origin_data_tc2['__C_TC2_INIT'] = "0x1"
    origin_data_tc2['__USP_TC2_INIT'] = "0x1"
    origin_data_tc2['__ISP_TC2_INIT'] = "0x1"
    origin_data_tc2['__A0A1_TC2_INIT'] = "0x1"
    origin_data_tc2['__A8A9_TC2_INIT'] = "0x1"
    origin_data_tc2['__USER_STACK_TC2'] = "0x1"
    origin_data_tc2['__USE_ARGC_ARGV_TC2'] = "0x0"
    origin_data_tc2['__ARGCV_BUFSIZE_TC2'] = "0x100"
    origin_data_tc2['__RESOLVE_TRAP_0_TC2'] = "0x1"
    origin_data_tc2['__RESOLVE_TRAP_1_TC2'] = "0x1"
    origin_data_tc2['__RESOLVE_TRAP_2_TC2'] = "0x1"
    origin_data_tc2['__RESOLVE_TRAP_3_TC2'] = "0x1"
    origin_data_tc2['__RESOLVE_TRAP_4_TC2'] = "0x1"
    origin_data_tc2['__RESOLVE_TRAP_5_TC2'] = "0x1"
    origin_data_tc2['__RESOLVE_TRAP_6_TC2'] = "0x1"
    origin_data_tc2['__RESOLVE_TRAP_7_TC2'] = "0x1"
    origin_data_tc2['__PCON0_INIT'] = "0x1"
    origin_data_tc2['__PCON0_VALUE'] = "0x0"
    origin_data_tc2['__DCON0_INIT'] = "0x1"
    origin_data_tc2['__DCON0_VALUE'] = "0x0"

def tasking_v62_tc29x_h_modify_save(save_file_path):
    # tc0 header create
    save_file_name = save_file_path + "\\prost_cstart.h"
    with open(save_file_name, 'wt', encoding='utf-8', newline='') as header_file:
        header_file.write("/**************************************************************************\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  FILE        :  cstart.h                                               *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  DESCRIPTION :                                                         *\n")
        header_file.write("**      Header file to control the system startup code's general settings *\n")
        header_file.write("**      and register initializations. The cstart.c file must be part of   *\n")
        header_file.write("**      your project to make use of this cstart.h.                        *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**      In the Eclipse environment this file can be modified using the    *\n")
        header_file.write("**      C startup code editor, which provides a GUI to modify the         *\n")
        header_file.write("**      Configuration settings and register initialization.               *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  Copyright 1996-2018 TASKING BV                                        *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**************************************************************************/\n")
        header_file.write("\n")
        header_file.write("#ifndef PROST_CSTART_H\n")
        header_file.write("#define PROST_CSTART_H\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * These items are shown on in Eclipse on the C Start Configuration page\n")
        header_file.write(" */\n")
        header_file.write("\n")
        header_file.write("#ifndef __NO_CSTART_DEFAULT_CONFIG\n")
        header_file.write("\n")
        header_file.write("/* C Startup settings */\n")
        header_file.write(
            "#define __BIV_INIT              {}       /* Initialize base address of interrupt vector table */\n".format(
                origin_data_tc['__BIV_INIT']))
        header_file.write(
            "#define __BIV_SINGLE_INIT       {}       /* Initialize single entry interrupt vector table */\n".format(
                origin_data_tc['__BIV_SINGLE_INIT']))
        header_file.write(
            "#define __BIV_8BYTE_INIT        {}       /* Initialize 8 byte spacing interrupt vector table */\n".format(
                origin_data_tc['__BIV_8BYTE_INIT']))
        header_file.write(
            "#define __BTV_INIT              {}       /* Initialize base address of trap vector table */\n".format(
                origin_data_tc['__BTV_INIT']))
        header_file.write(
            "#define __CSA_INIT              {}       /* Initialize CSA lists */\n".format(origin_data_tc['__CSA_INIT']))
        header_file.write("#define __C_INIT                {}       /* Initialize and clear C variables */\n".format(
            origin_data_tc['__C_INIT']))
        header_file.write("#define __USP_INIT              {}       /* Initialize user stack pointer */\n".format(
            origin_data_tc['__USP_INIT']))
        header_file.write("#define __ISP_INIT              {}       /* Initialize interrupt stack pointer */\n".format(
            origin_data_tc['__ISP_INIT']))
        header_file.write(
            "#define __A0A1_INIT             {}       /* Initialize a0 and a1 for _a0/_a1 addressing */\n".format(
                origin_data_tc['__A0A1_INIT']))
        header_file.write(
            "#define __A8A9_INIT             {}       /* Initialize a8 and a9 for _a8/_a9 addressing (OS support) */\n".format(
                origin_data_tc['__A8A9_INIT']))
        header_file.write("#define __RM_INIT               {}       /* Initialize rounding mode */\n".format(
            origin_data_tc['__RM_INIT']))
        header_file.write(
            "#define __RM_VALUE              {}  /* FE_TONEAREST, FE_UPWARD, FE_DOWNWARD or FE_TOWARDZERO */\n".format(
                origin_data_tc['__RM_VALUE']))
        header_file.write("\n")
        header_file.write("#define __CDC                   {}     /* Call Depth Counter (set PSW.CDC) */\n".format(
            origin_data_tc['__CDC']))
        header_file.write("#define __USER_STACK            {}       /* Use the user stack (clear PSW.IS) */\n".format(
            origin_data_tc['__USER_STACK']))
        header_file.write("#define __WATCHDOG_DISABLE      {}       /* Watchdog disable */\n".format(
            origin_data_tc['__WATCHDOG_DISABLE']))
        header_file.write("#define __SAFETY_WATCHDOG_DISABLE {}     /* Safety watchdog disable */\n".format(
            origin_data_tc['__SAFETY_WATCHDOG_DISABLE']))
        header_file.write(
            "#define __COMPAT                {}     /* Compatibility mode */\n".format(origin_data_tc['__COMPAT']))
        header_file.write("#define __USE_ARGC_ARGV         {}       /* Enable passing argc/argv to main() */\n".format(
            origin_data_tc['__USE_ARGC_ARGV']))
        header_file.write("#define __ARGCV_BUFSIZE       {}       /* Buffer size for argv */\n".format(
            origin_data_tc['__ARGCV_BUFSIZE']))
        header_file.write("#define __CLOCKS_PER_SEC_INIT   {}       /* Initialize clocks per sec */\n".format(
            origin_data_tc['__CLOCKS_PER_SEC_INIT']))
        header_file.write(
            "#define __fOSC           {}       /* Oscillator frequency Hz */\n".format(origin_data_tc['__fOSC']))
        header_file.write(
            "#define __PLL_K2_RAMPUP         {}       /* PLL K2 rampup */\n".format(origin_data_tc['__PLL_K2_RAMPUP']))
        header_file.write(
            "#define __START_INIT_TC1        {}       /* Start TC1 */\n".format(origin_data_tc['__START_INIT_TC1']))
        header_file.write(
            "#define __START_INIT_TC2        {}       /* Start TC2 */\n".format(origin_data_tc['__START_INIT_TC2']))
        header_file.write(
            "#define __START_INIT_TC3        {}       /* Start TC3 */\n".format(origin_data_tc['__START_INIT_TC3']))
        header_file.write(
            "#define __START_INIT_TC4        {}       /* Start TC4 */\n".format(origin_data_tc['__START_INIT_TC4']))
        header_file.write(
            "#define __START_INIT_TC5        {}       /* Start TC5 */\n".format(origin_data_tc['__START_INIT_TC5']))
        header_file.write("\n")
        header_file.write("/* Trap Vectors */\n")
        header_file.write(
            "#define __RESOLVE_TRAP_0        {}       /* Class 0: MMU */\n".format(origin_data_tc['__RESOLVE_TRAP_0']))
        header_file.write("#define __RESOLVE_TRAP_1        {}       /* Class 1: Internal protection */\n".format(
            origin_data_tc['__RESOLVE_TRAP_1']))
        header_file.write("#define __RESOLVE_TRAP_2        {}       /* Class 2: Instruction error */\n".format(
            origin_data_tc['__RESOLVE_TRAP_2']))
        header_file.write("#define __RESOLVE_TRAP_3        {}       /* Class 3: Context management */\n".format(
            origin_data_tc['__RESOLVE_TRAP_3']))
        header_file.write(
            "#define __RESOLVE_TRAP_4        {}       /* Class 4: System bus and peripheral errors */\n".format(
                origin_data_tc['__RESOLVE_TRAP_4']))
        header_file.write("#define __RESOLVE_TRAP_5        {}       /* Class 5: Assertion */\n".format(
            origin_data_tc['__RESOLVE_TRAP_5']))
        header_file.write("#define __RESOLVE_TRAP_6        {}       /* Class 6: System call */\n".format(
            origin_data_tc['__RESOLVE_TRAP_6']))
        header_file.write("#define __RESOLVE_TRAP_7        {}       /* Class 7: Non-maskable interrupt */\n".format(
            origin_data_tc['__RESOLVE_TRAP_7']))
        header_file.write("\n")
        header_file.write("#define __XC800_INIT            {}       /* Download XC800 image to XRAM */\n".format(
            origin_data_tc['__XC800_INIT']))
        header_file.write("\n")
        header_file.write("#endif /* __NO_CSTART_DEFAULT_CONFIG */\n")
        header_file.write("\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * Control of initialization registers\n")
        header_file.write(" *\n")
        header_file.write(" * The *_VALUE macros define the value of the register\n")
        header_file.write(" * The *_INIT macros must be defined to 0 or 1, specifying whether\n")
        header_file.write(" * or not it will be intialized by the cstart.c code.\n")
        header_file.write(" *\n")
        header_file.write(" * Most registers are not set to be initialized, which means that\n")
        header_file.write(" * the CPU's defaults are used. The bus configuration registers will be\n")
        header_file.write(" * set by running the 'Target Board Configuration' wizard.\n")
        header_file.write(" * The Eclipse environment will automatically apply the CPU default\n")
        header_file.write(" * values to the registers. These defaults are defined in the SFR files\n")
        header_file.write(" * from the include/sfr directory of the product.\n")
        header_file.write(" *\n")
        header_file.write(" */\n")
        header_file.write("\n")
        header_file.write("#define __EBU_BOOTCFG_INIT      {}\n".format(origin_data_tc['__EBU_BOOTCFG_INIT']))
        header_file.write("#define __EBU_BOOTCFG_VALUE     {}\n".format(origin_data_tc['__EBU_BOOTCFG_VALUE']))
        header_file.write("\n")
        header_file.write("#ifndef __NO_CSTART_REGISTER_CONFIG\n")
        header_file.write("/* Non-bus configuration: */\n")
        header_file.write("#define __PMI_CON0_INIT         {}\n".format(origin_data_tc['__PMI_CON0_INIT']))
        header_file.write("#define __PMI_CON0_VALUE        {}\n".format(origin_data_tc['__PMI_CON0_VALUE']))
        header_file.write("#define __PMI_CON1_INIT         {}\n".format(origin_data_tc['__PMI_CON1_INIT']))
        header_file.write("#define __PMI_CON1_VALUE        {}\n".format(origin_data_tc['__PMI_CON1_VALUE']))
        header_file.write("#define __PMI_CON2_INIT         {}\n".format(origin_data_tc['__PMI_CON2_INIT']))
        header_file.write("#define __PMI_CON2_VALUE        {}\n".format(origin_data_tc['__PMI_CON2_VALUE']))
        header_file.write("#define __PMU_EIFCON_INIT       {}\n".format(origin_data_tc['__PMU_EIFCON_INIT']))
        header_file.write("#define __PMU_EIFCON_VALUE      {}\n".format(origin_data_tc['__PMU_EIFCON_VALUE']))
        header_file.write("#define __DMI_CON_INIT          {}\n".format(origin_data_tc['__DMI_CON_INIT']))
        header_file.write("#define __DMI_CON_VALUE         {}\n".format(origin_data_tc['__DMI_CON_VALUE']))
        header_file.write("#define __PLL_CLC_INIT          {}\n".format(origin_data_tc['__PLL_CLC_INIT']))
        header_file.write("#define __PLL_CLC_VALUE         {}\n".format(origin_data_tc['__PLL_CLC_VALUE']))
        header_file.write("#define __SCU_PLLCON0_INIT      {}\n".format(origin_data_tc['__SCU_PLLCON0_INIT']))
        header_file.write("#define __SCU_PLLCON0_VALUE     {}\n".format(origin_data_tc['__SCU_PLLCON0_VALUE']))
        header_file.write("#define __SCU_SYSPLLCON0_INIT   {}\n".format(origin_data_tc['__SCU_SYSPLLCON0_INIT']))
        header_file.write("#define __SCU_SYSPLLCON0_VALUE  {}\n".format(origin_data_tc['__SCU_SYSPLLCON0_VALUE']))
        header_file.write("#define __SCU_PLLCON1_INIT      {}\n".format(origin_data_tc['__SCU_PLLCON1_INIT']))
        header_file.write("#define __SCU_PLLCON1_VALUE     {}\n".format(origin_data_tc['__SCU_PLLCON1_VALUE']))
        header_file.write("#define __SCU_SYSPLLCON1_INIT   {}\n".format(origin_data_tc['__SCU_SYSPLLCON1_INIT']))
        header_file.write("#define __SCU_SYSPLLCON1_VALUE  {}\n".format(origin_data_tc['__SCU_SYSPLLCON1_VALUE']))
        header_file.write("#define __SCU_OSCCON_INIT       {}\n".format(origin_data_tc['__SCU_OSCCON_INIT']))
        header_file.write("#define __SCU_OSCCON_VALUE      {}\n".format(origin_data_tc['__SCU_OSCCON_VALUE']))
        header_file.write("#define __SCU_CCUCON0_INIT      {}\n".format(origin_data_tc['__SCU_CCUCON0_INIT']))
        header_file.write("#define __SCU_CCUCON0_VALUE     {}\n".format(origin_data_tc['__SCU_CCUCON0_VALUE']))
        header_file.write("#define __SCU_CCUCON1_INIT      {}\n".format(origin_data_tc['__SCU_CCUCON1_INIT']))
        header_file.write("#define __SCU_CCUCON1_VALUE     {}\n".format(origin_data_tc['__SCU_CCUCON1_VALUE']))
        header_file.write("#define __SCU_CCUCON2_INIT      {}\n".format(origin_data_tc['__SCU_CCUCON2_INIT']))
        header_file.write("#define __SCU_CCUCON2_VALUE     {}\n".format(origin_data_tc['__SCU_CCUCON2_VALUE']))
        header_file.write("#define __STM_CLC_INIT          {}\n".format(origin_data_tc['__STM_CLC_INIT']))
        header_file.write("#define __STM_CLC_VALUE         {}\n".format(origin_data_tc['__STM_CLC_VALUE']))
        header_file.write("#define __GTM_CLC_INIT          {}\n".format(origin_data_tc['__GTM_CLC_INIT']))
        header_file.write("#define __GTM_CLC_VALUE         {}\n".format(origin_data_tc['__GTM_CLC_VALUE']))
        header_file.write("#define __FLASH0_FCON_INIT      {}\n".format(origin_data_tc['__FLASH0_FCON_INIT']))
        header_file.write("#define __FLASH0_FCON_VALUE     {}\n".format(origin_data_tc['__FLASH0_FCON_VALUE']))
        header_file.write("#define __FLASH1_FCON_INIT      {}\n".format(origin_data_tc['__FLASH1_FCON_INIT']))
        header_file.write("#define __FLASH1_FCON_VALUE     {}\n".format(origin_data_tc['__FLASH1_FCON_VALUE']))
        header_file.write("/* Bus configuration: (set by 'Target Board Configuration' wizard) */\n")
        header_file.write("#define __EBU_ADDRSEL0_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL0_INIT']))
        header_file.write("#define __EBU_ADDRSEL0_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL0_VALUE']))
        header_file.write("#define __EBU_ADDRSEL1_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL1_INIT']))
        header_file.write("#define __EBU_ADDRSEL1_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL1_VALUE']))
        header_file.write("#define __EBU_ADDRSEL2_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL2_INIT']))
        header_file.write("#define __EBU_ADDRSEL2_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL2_VALUE']))
        header_file.write("#define __EBU_ADDRSEL3_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL3_INIT']))
        header_file.write("#define __EBU_ADDRSEL3_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL3_VALUE']))
        header_file.write("#define __EBU_ADDRSEL4_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL4_INIT']))
        header_file.write("#define __EBU_ADDRSEL4_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL4_VALUE']))
        header_file.write("#define __EBU_ADDRSEL5_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL5_INIT']))
        header_file.write("#define __EBU_ADDRSEL5_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL5_VALUE']))
        header_file.write("#define __EBU_ADDRSEL6_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL6_INIT']))
        header_file.write("#define __EBU_ADDRSEL6_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL6_VALUE']))
        header_file.write("#define __EBU_BFCON_INIT        {}\n".format(origin_data_tc['__EBU_BFCON_INIT']))
        header_file.write("#define __EBU_BFCON_VALUE       {}\n".format(origin_data_tc['__EBU_BFCON_VALUE']))
        header_file.write("#define __EBU_BUSAP0_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP0_INIT']))
        header_file.write("#define __EBU_BUSAP0_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP0_VALUE']))
        header_file.write("#define __EBU_BUSAP1_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP1_INIT']))
        header_file.write("#define __EBU_BUSAP1_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP1_VALUE']))
        header_file.write("#define __EBU_BUSAP2_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP2_INIT']))
        header_file.write("#define __EBU_BUSAP2_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP2_VALUE']))
        header_file.write("#define __EBU_BUSAP3_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP3_INIT']))
        header_file.write("#define __EBU_BUSAP3_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP3_VALUE']))
        header_file.write("#define __EBU_BUSAP4_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP4_INIT']))
        header_file.write("#define __EBU_BUSAP4_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP4_VALUE']))
        header_file.write("#define __EBU_BUSAP5_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP5_INIT']))
        header_file.write("#define __EBU_BUSAP5_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP5_VALUE']))
        header_file.write("#define __EBU_BUSAP6_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP6_INIT']))
        header_file.write("#define __EBU_BUSAP6_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP6_VALUE']))
        header_file.write("#define __EBU_BUSCON0_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON0_INIT']))
        header_file.write("#define __EBU_BUSCON0_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON0_VALUE']))
        header_file.write("#define __EBU_BUSCON1_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON1_INIT']))
        header_file.write("#define __EBU_BUSCON1_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON1_VALUE']))
        header_file.write("#define __EBU_BUSCON2_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON2_INIT']))
        header_file.write("#define __EBU_BUSCON2_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON2_VALUE']))
        header_file.write("#define __EBU_BUSCON3_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON3_INIT']))
        header_file.write("#define __EBU_BUSCON3_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON3_VALUE']))
        header_file.write("#define __EBU_BUSCON4_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON4_INIT']))
        header_file.write("#define __EBU_BUSCON4_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON4_VALUE']))
        header_file.write("#define __EBU_BUSCON5_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON5_INIT']))
        header_file.write("#define __EBU_BUSCON5_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON5_VALUE']))
        header_file.write("#define __EBU_BUSCON6_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON6_INIT']))
        header_file.write("#define __EBU_BUSCON6_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON6_VALUE']))
        header_file.write("#define __EBU_CLC_INIT          {}\n".format(origin_data_tc['__EBU_CLC_INIT']))
        header_file.write("#define __EBU_CLC_VALUE         {}\n".format(origin_data_tc['__EBU_CLC_VALUE']))
        header_file.write("#define __EBU_CON_INIT          {}\n".format(origin_data_tc['__EBU_CON_INIT']))
        header_file.write("#define __EBU_CON_VALUE         {}\n".format(origin_data_tc['__EBU_CON_VALUE']))
        header_file.write("#define __EBU_EMUAS_INIT        {}\n".format(origin_data_tc['__EBU_EMUAS_INIT']))
        header_file.write("#define __EBU_EMUAS_VALUE       {}\n".format(origin_data_tc['__EBU_EMUAS_VALUE']))
        header_file.write("#define __EBU_EMUBAP_INIT       {}\n".format(origin_data_tc['__EBU_EMUBAP_INIT']))
        header_file.write("#define __EBU_EMUBAP_VALUE      {}\n".format(origin_data_tc['__EBU_EMUBAP_VALUE']))
        header_file.write("#define __EBU_EMUBC_INIT        {}\n".format(origin_data_tc['__EBU_EMUBC_INIT']))
        header_file.write("#define __EBU_EMUBC_VALUE       {}\n".format(origin_data_tc['__EBU_EMUBC_VALUE']))
        header_file.write("#define __EBU_EMUCON_INIT       {}\n".format(origin_data_tc['__EBU_EMUCON_INIT']))
        header_file.write("#define __EBU_EMUCON_VALUE      {}\n".format(origin_data_tc['__EBU_EMUCON_VALUE']))
        header_file.write("#define __EBU_EMUOVL_INIT       {}\n".format(origin_data_tc['__EBU_EMUOVL_INIT']))
        header_file.write("#define __EBU_EMUOVL_VALUE      {}\n".format(origin_data_tc['__EBU_EMUOVL_VALUE']))
        header_file.write("#define __EBU_SDRMCON0_INIT     {}\n".format(origin_data_tc['__EBU_SDRMCON0_INIT']))
        header_file.write("#define __EBU_SDRMCON0_VALUE    {}\n".format(origin_data_tc['__EBU_SDRMCON0_VALUE']))
        header_file.write("#define __EBU_SDRMCON1_INIT     {}\n".format(origin_data_tc['__EBU_SDRMCON1_INIT']))
        header_file.write("#define __EBU_SDRMCON1_VALUE    {}\n".format(origin_data_tc['__EBU_SDRMCON1_VALUE']))
        header_file.write("#define __EBU_SDRMOD0_INIT      {}\n".format(origin_data_tc['__EBU_SDRMOD0_INIT']))
        header_file.write("#define __EBU_SDRMOD0_VALUE     {}\n".format(origin_data_tc['__EBU_SDRMOD0_VALUE']))
        header_file.write("#define __EBU_SDRMOD1_INIT      {}\n".format(origin_data_tc['__EBU_SDRMOD1_INIT']))
        header_file.write("#define __EBU_SDRMOD1_VALUE     {}\n".format(origin_data_tc['__EBU_SDRMOD1_VALUE']))
        header_file.write("#define __EBU_SDRMREF0_INIT     {}\n".format(origin_data_tc['__EBU_SDRMREF0_INIT']))
        header_file.write("#define __EBU_SDRMREF0_VALUE    {}\n".format(origin_data_tc['__EBU_SDRMREF0_VALUE']))
        header_file.write("#define __EBU_SDRMREF1_INIT     {}\n".format(origin_data_tc['__EBU_SDRMREF1_INIT']))
        header_file.write("#define __EBU_SDRMREF1_VALUE    {}\n".format(origin_data_tc['__EBU_SDRMREF1_VALUE']))
        header_file.write("#define __CBS_MCDBBS_INIT       {}\n".format(origin_data_tc['__CBS_MCDBBS_INIT']))
        header_file.write("#define __CBS_MCDBBS_VALUE      {}\n".format(origin_data_tc['__CBS_MCDBBS_VALUE']))
        header_file.write("#define __SBCU_CON_INIT         {}\n".format(origin_data_tc['__SBCU_CON_INIT']))
        header_file.write("#define __SBCU_CON_VALUE        {}\n".format(origin_data_tc['__SBCU_CON_VALUE']))
        header_file.write("#define __EBU_BUSRAP1_INIT      {}\n".format(origin_data_tc['__EBU_BUSRAP1_INIT']))
        header_file.write("#define __EBU_BUSRAP1_VALUE     {}\n".format(origin_data_tc['__EBU_BUSRAP1_VALUE']))
        header_file.write("#define __EBU_BUSRAP0_INIT      {}\n".format(origin_data_tc['__EBU_BUSRAP0_INIT']))
        header_file.write("#define __EBU_BUSRAP0_VALUE     {}\n".format(origin_data_tc['__EBU_BUSRAP0_VALUE']))
        header_file.write("#define __EBU_BUSRAP2_INIT      {}\n".format(origin_data_tc['__EBU_BUSRAP2_INIT']))
        header_file.write("#define __EBU_BUSRAP2_VALUE     {}\n".format(origin_data_tc['__EBU_BUSRAP2_VALUE']))
        header_file.write("#define __EBU_BUSRAP3_INIT      {}\n".format(origin_data_tc['__EBU_BUSRAP3_INIT']))
        header_file.write("#define __EBU_BUSRAP3_VALUE     {}\n".format(origin_data_tc['__EBU_BUSRAP3_VALUE']))
        header_file.write("#define __EBU_BUSRCON0_INIT     {}\n".format(origin_data_tc['__EBU_BUSRCON0_INIT']))
        header_file.write("#define __EBU_BUSRCON0_VALUE    {}\n".format(origin_data_tc['__EBU_BUSRCON0_VALUE']))
        header_file.write("#define __EBU_BUSRCON1_INIT     {}\n".format(origin_data_tc['__EBU_BUSRCON1_INIT']))
        header_file.write("#define __EBU_BUSRCON1_VALUE    {}\n".format(origin_data_tc['__EBU_BUSRCON1_VALUE']))
        header_file.write("#define __EBU_BUSRCON2_INIT     {}\n".format(origin_data_tc['__EBU_BUSRCON2_INIT']))
        header_file.write("#define __EBU_BUSRCON2_VALUE    {}\n".format(origin_data_tc['__EBU_BUSRCON2_VALUE']))
        header_file.write("#define __EBU_BUSRCON3_INIT     {}\n".format(origin_data_tc['__EBU_BUSRCON3_INIT']))
        header_file.write("#define __EBU_BUSRCON3_VALUE    {}\n".format(origin_data_tc['__EBU_BUSRCON3_VALUE']))
        header_file.write("#define __EBU_BUSWAP0_INIT      {}\n".format(origin_data_tc['__EBU_BUSWAP0_INIT']))
        header_file.write("#define __EBU_BUSWAP0_VALUE     {}\n".format(origin_data_tc['__EBU_BUSWAP0_VALUE']))
        header_file.write("#define __EBU_BUSWAP1_INIT      {}\n".format(origin_data_tc['__EBU_BUSWAP1_INIT']))
        header_file.write("#define __EBU_BUSWAP1_VALUE     {}\n".format(origin_data_tc['__EBU_BUSWAP1_VALUE']))
        header_file.write("#define __EBU_BUSWAP2_INIT      {}\n".format(origin_data_tc['__EBU_BUSWAP2_INIT']))
        header_file.write("#define __EBU_BUSWAP2_VALUE     {}\n".format(origin_data_tc['__EBU_BUSWAP2_VALUE']))
        header_file.write("#define __EBU_BUSWAP3_INIT      {}\n".format(origin_data_tc['__EBU_BUSWAP3_INIT']))
        header_file.write("#define __EBU_BUSWAP3_VALUE     {}\n".format(origin_data_tc['__EBU_BUSWAP3_VALUE']))
        header_file.write("#define __EBU_BUSWCON0_INIT     {}\n".format(origin_data_tc['__EBU_BUSWCON0_INIT']))
        header_file.write("#define __EBU_BUSWCON0_VALUE    {}\n".format(origin_data_tc['__EBU_BUSWCON0_VALUE']))
        header_file.write("#define __EBU_BUSWCON1_INIT     {}\n".format(origin_data_tc['__EBU_BUSWCON1_INIT']))
        header_file.write("#define __EBU_BUSWCON1_VALUE    {}\n".format(origin_data_tc['__EBU_BUSWCON1_VALUE']))
        header_file.write("#define __EBU_BUSWCON2_INIT     {}\n".format(origin_data_tc['__EBU_BUSWCON2_INIT']))
        header_file.write("#define __EBU_BUSWCON2_VALUE    {}\n".format(origin_data_tc['__EBU_BUSWCON2_VALUE']))
        header_file.write("#define __EBU_BUSWCON3_INIT     {}\n".format(origin_data_tc['__EBU_BUSWCON3_INIT']))
        header_file.write("#define __EBU_BUSWCON3_VALUE    {}\n".format(origin_data_tc['__EBU_BUSWCON3_VALUE']))
        header_file.write("#define __EBU_EXTBOOT_INIT      {}\n".format(origin_data_tc['__EBU_EXTBOOT_INIT']))
        header_file.write("#define __EBU_EXTBOOT_VALUE     {}\n".format(origin_data_tc['__EBU_EXTBOOT_VALUE']))
        header_file.write("#define __EBU_MODCON_INIT       {}\n".format(origin_data_tc['__EBU_MODCON_INIT']))
        header_file.write("#define __EBU_MODCON_VALUE      {}\n".format(origin_data_tc['__EBU_MODCON_VALUE']))
        header_file.write("#define __EBU_DDRNCON_INIT      {}\n".format(origin_data_tc['__EBU_DDRNCON_INIT']))
        header_file.write("#define __EBU_DDRNCON_VALUE     {}\n".format(origin_data_tc['__EBU_DDRNCON_VALUE']))
        header_file.write("#define __EBU_DDRNMOD_INIT      {}\n".format(origin_data_tc['__EBU_DDRNMOD_INIT']))
        header_file.write("#define __EBU_DDRNMOD_VALUE     {}\n".format(origin_data_tc['__EBU_DDRNMOD_VALUE']))
        header_file.write("#define __EBU_DDRNMOD2_INIT     {}\n".format(origin_data_tc['__EBU_DDRNMOD2_INIT']))
        header_file.write("#define __EBU_DDRNMOD2_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNMOD2_VALUE']))
        header_file.write("#define __EBU_DDRNPRLD_INIT     {}\n".format(origin_data_tc['__EBU_DDRNPRLD_INIT']))
        header_file.write("#define __EBU_DDRNPRLD_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNPRLD_VALUE']))
        header_file.write("#define __EBU_DDRNTAG0_INIT     {}\n".format(origin_data_tc['__EBU_DDRNTAG0_INIT']))
        header_file.write("#define __EBU_DDRNTAG0_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNTAG0_VALUE']))
        header_file.write("#define __EBU_DDRNTAG1_INIT     {}\n".format(origin_data_tc['__EBU_DDRNTAG1_INIT']))
        header_file.write("#define __EBU_DDRNTAG1_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNTAG1_VALUE']))
        header_file.write("#define __EBU_DDRNTAG2_INIT     {}\n".format(origin_data_tc['__EBU_DDRNTAG2_INIT']))
        header_file.write("#define __EBU_DDRNTAG2_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNTAG2_VALUE']))
        header_file.write("#define __EBU_DDRNTAG3_INIT     {}\n".format(origin_data_tc['__EBU_DDRNTAG3_INIT']))
        header_file.write("#define __EBU_DDRNTAG3_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNTAG3_VALUE']))
        header_file.write("#define __EBU_DLLCON_INIT       {}\n".format(origin_data_tc['__EBU_DLLCON_INIT']))
        header_file.write("#define __EBU_DLLCON_VALUE      {}\n".format(origin_data_tc['__EBU_DLLCON_VALUE']))
        header_file.write("#define __EBU_SDRMCON_INIT      {}\n".format(origin_data_tc['__EBU_SDRMCON_INIT']))
        header_file.write("#define __EBU_SDRMCON_VALUE     {}\n".format(origin_data_tc['__EBU_SDRMCON_VALUE']))
        header_file.write("#define __EBU_SDRMOD_INIT       {}\n".format(origin_data_tc['__EBU_SDRMOD_INIT']))
        header_file.write("#define __EBU_SDRMOD_VALUE      {}\n".format(origin_data_tc['__EBU_SDRMOD_VALUE']))
        header_file.write("#define __EBU_SDRMREF_INIT      {}\n".format(origin_data_tc['__EBU_SDRMREF_INIT']))
        header_file.write("#define __EBU_SDRMREF_VALUE     {}\n".format(origin_data_tc['__EBU_SDRMREF_VALUE']))
        header_file.write("#define __EBU_SDRSTAT_INIT      {}\n".format(origin_data_tc['__EBU_SDRSTAT_INIT']))
        header_file.write("#define __EBU_SDRSTAT_VALUE     {}\n".format(origin_data_tc['__EBU_SDRSTAT_VALUE']))
        header_file.write("#define __P24_PDR0_INIT         {}\n".format(origin_data_tc['__P24_PDR0_INIT']))
        header_file.write("#define __P24_PDR0_VALUE        {}\n".format(origin_data_tc['__P24_PDR0_VALUE']))
        header_file.write("#define __P24_PDR1_INIT         {}\n".format(origin_data_tc['__P24_PDR1_INIT']))
        header_file.write("#define __P24_PDR1_VALUE        {}\n".format(origin_data_tc['__P24_PDR1_VALUE']))
        header_file.write("#define __P25_PDR0_INIT         {}\n".format(origin_data_tc['__P25_PDR0_INIT']))
        header_file.write("#define __P25_PDR0_VALUE        {}\n".format(origin_data_tc['__P25_PDR0_VALUE']))
        header_file.write("#define __P25_PDR1_INIT         {}\n".format(origin_data_tc['__P25_PDR1_INIT']))
        header_file.write("#define __P25_PDR1_VALUE        {}\n".format(origin_data_tc['__P25_PDR1_VALUE']))
        header_file.write("#define __P30_PDR0_INIT         {}\n".format(origin_data_tc['__P30_PDR0_INIT']))
        header_file.write("#define __P30_PDR0_VALUE        {}\n".format(origin_data_tc['__P30_PDR0_VALUE']))
        header_file.write("#define __P30_PDR1_INIT         {}\n".format(origin_data_tc['__P30_PDR1_INIT']))
        header_file.write("#define __P30_PDR1_VALUE        {}\n".format(origin_data_tc['__P30_PDR1_VALUE']))
        header_file.write("#define __P31_PDR0_INIT         {}\n".format(origin_data_tc['__P31_PDR0_INIT']))
        header_file.write("#define __P31_PDR0_VALUE        {}\n".format(origin_data_tc['__P31_PDR0_VALUE']))
        header_file.write("#define __P31_PDR1_INIT         {}\n".format(origin_data_tc['__P31_PDR1_INIT']))
        header_file.write("#define __P31_PDR1_VALUE        {}\n".format(origin_data_tc['__P31_PDR1_VALUE']))
        header_file.write("#define __PCON0_INIT            {}\n".format(origin_data_tc['__PCON0_INIT']))
        header_file.write("#define __PCON0_VALUE           {}\n".format(origin_data_tc['__PCON0_VALUE']))
        header_file.write("#define __DCON0_INIT            {}\n".format(origin_data_tc['__DCON0_INIT']))
        header_file.write("#define __DCON0_VALUE           {}\n".format(origin_data_tc['__DCON0_VALUE']))
        header_file.write("\n")
        header_file.write("#endif /*__NO_CSTART_REGISTER_CONFIG */\n")
        header_file.write("\n")
        header_file.write("#endif /* CSTART_H */\n")

    # tc1 header create
    save_file_name = save_file_path + "\\prost_cstart_tc1.h"
    with open(save_file_name, 'wt', encoding='utf-8', newline='') as header_file:
        header_file.write("/**************************************************************************\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  FILE        :  cstart_tc1.h                                           *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  DESCRIPTION :                                                         *\n")
        header_file.write("**      Header file to control the system startup code's general settings *\n")
        header_file.write("**      and register initializations. The cstart__tc1.c file must be part *\n")
        header_file.write("**      of your project to make use of this cstart__tc1.h.                *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**      In the Eclipse environment this file can be modified using the    *\n")
        header_file.write("**      C startup code editor, which provides a GUI to modify the         *\n")
        header_file.write("**      Configuration settings and register initialization.               *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  Copyright 1996-2018 TASKING BV                                        *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**************************************************************************/\n")
        header_file.write("\n")
        header_file.write("#ifndef PROST_CSTART_TC1_H\n")
        header_file.write("#define PROST_CSTART_TC1_H\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * These items are shown in Eclipse on the C Start Configuration page\n")
        header_file.write(" */\n")
        header_file.write("\n")
        header_file.write("#ifndef __NO_CSTART_DEFAULT_CONFIG\n")
        header_file.write("\n")
        header_file.write("/* C Startup settings */\n")
        header_file.write(
            "#define __BIV_TC1_INIT          {}       /* Initialize base address of interrupt vector table */\n".format(
                origin_data_tc1['__BIV_TC1_INIT']))
        header_file.write(
            "#define __BIV_SINGLE_TC1_INIT   {}       /* Initialize single entry interrupt vector table */\n".format(
                origin_data_tc1['__BIV_SINGLE_TC1_INIT']))
        header_file.write(
            "#define __BIV_8BYTE_TC1_INIT    {}       /* Initialize 8 byte spacing interrupt vector table */\n".format(
                origin_data_tc1['__BIV_8BYTE_TC1_INIT']))
        header_file.write(
            "#define __BTV_TC1_INIT          {}       /* Initialize base address of trap vector table */\n".format(
                origin_data_tc1['__BTV_TC1_INIT']))
        header_file.write("#define __CSA_TC1_INIT          {}       /* Initialize CSA lists */\n".format(
            origin_data_tc1['__CSA_TC1_INIT']))
        header_file.write("#define __C_TC1_INIT            {}       /* Initialize and clear C variables */\n".format(
            origin_data_tc1['__C_TC1_INIT']))
        header_file.write("#define __USP_TC1_INIT          {}       /* Initialize user stack pointer */\n".format(
            origin_data_tc1['__USP_TC1_INIT']))
        header_file.write("#define __ISP_TC1_INIT          {}       /* Initialize interrupt stack pointer */\n".format(
            origin_data_tc1['__ISP_TC1_INIT']))
        header_file.write(
            "#define __A0A1_TC1_INIT         {}       /* Initialize a0 and a1 for _a0/_a1 addressing */\n".format(
                origin_data_tc1['__A0A1_TC1_INIT']))
        header_file.write(
            "#define __A8A9_TC1_INIT         {}       /* Initialize a8 and a9 for _a8/_a9 addressing (OS support) */\n".format(
                origin_data_tc1['__A8A9_TC1_INIT']))
        header_file.write("#define __RM_TC1_INIT           {}       /* Initialize rounding mode */\n".format(
            origin_data_tc1['__RM_TC1_INIT']))
        header_file.write(
            "#define __RM_TC1_VALUE          {}  /* FE_TONEAREST, FE_UPWARD, FE_DOWNWARD or FE_TOWARDZERO */\n".format(
                origin_data_tc1['__RM_TC1_VALUE']))
        header_file.write("\n")
        header_file.write(
            "#define __CDC_TC1                       {}     /* Call Depth Counter (set PSW.CDC) */\n".format(
                origin_data_tc1['__CDC_TC1']))
        header_file.write(
            "#define __USER_STACK_TC1                {}       /* Use the user stack (clear PSW.IS) */\n".format(
                origin_data_tc1['__USER_STACK_TC1']))
        header_file.write(
            "#define __COMPAT_TC1            {}     /* Compatibility mode */\n".format(origin_data_tc1['__COMPAT_TC1']))
        header_file.write("#define __USE_ARGC_ARGV_TC1     {}       /* Enable passing argc/argv to main() */\n".format(
            origin_data_tc1['__USE_ARGC_ARGV_TC1']))
        header_file.write("#define __ARGCV_BUFSIZE_TC1     {}     /* Buffer size for argv */\n".format(
            origin_data_tc1['__ARGCV_BUFSIZE_TC1']))
        header_file.write("\n")
        header_file.write("/* Trap Vectors */\n")
        header_file.write("#define __RESOLVE_TRAP_0_TC1    {}       /* Class 0: MMU */\n".format(
            origin_data_tc1['__RESOLVE_TRAP_0_TC1']))
        header_file.write("#define __RESOLVE_TRAP_1_TC1    {}       /* Class 1: Internal protection */\n".format(
            origin_data_tc1['__RESOLVE_TRAP_1_TC1']))
        header_file.write("#define __RESOLVE_TRAP_2_TC1    {}       /* Class 2: Instruction error */\n".format(
            origin_data_tc1['__RESOLVE_TRAP_2_TC1']))
        header_file.write("#define __RESOLVE_TRAP_3_TC1    {}       /* Class 3: Context management */\n".format(
            origin_data_tc1['__RESOLVE_TRAP_3_TC1']))
        header_file.write(
            "#define __RESOLVE_TRAP_4_TC1    {}       /* Class 4: System bus and peripheral errors */\n".format(
                origin_data_tc1['__RESOLVE_TRAP_4_TC1']))
        header_file.write("#define __RESOLVE_TRAP_5_TC1    {}       /* Class 5: Assertion */\n".format(
            origin_data_tc1['__RESOLVE_TRAP_5_TC1']))
        header_file.write("#define __RESOLVE_TRAP_6_TC1    {}       /* Class 6: System call */\n".format(
            origin_data_tc1['__RESOLVE_TRAP_6_TC1']))
        header_file.write("#define __RESOLVE_TRAP_7_TC1    {}       /* Class 7: Non-maskable interrupt */\n".format(
            origin_data_tc1['__RESOLVE_TRAP_7_TC1']))
        header_file.write("\n")
        header_file.write("#endif /* __NO_CSTART_DEFAULT_CONFIG */\n")
        header_file.write("\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * Control of initialization registers\n")
        header_file.write(" *\n")
        header_file.write(" * The *_VALUE macros define the value of the register\n")
        header_file.write(" * The *_INIT macros must be defined to 0 or 1, specifying whether\n")
        header_file.write(" * or not it will be intialized by the cstart.c code.\n")
        header_file.write(" *\n")
        header_file.write(" * Most registers are not set to be initialized, which means that\n")
        header_file.write(" * the CPU's defaults are used. The bus configuration registers will be\n")
        header_file.write(" * set by running the 'Target Board Configuration' wizard.\n")
        header_file.write(" * The Eclipse environment will automatically apply the CPU default\n")
        header_file.write(" * values to the registers. These defaults are defined in the SFR files\n")
        header_file.write(" * from the include/sfr directory of the product.\n")
        header_file.write(" *\n")
        header_file.write(" */\n")
        header_file.write("#ifndef __NO_CSTART_REGISTER_CONFIG\n")
        header_file.write("\n")
        header_file.write("#define __PCON0_INIT            {}\n".format(origin_data_tc1['__PCON0_INIT']))
        header_file.write("#define __PCON0_VALUE           {}\n".format(origin_data_tc1['__PCON0_VALUE']))
        header_file.write("#define __DCON0_INIT            {}\n".format(origin_data_tc1['__DCON0_INIT']))
        header_file.write("#define __DCON0_VALUE           {}\n".format(origin_data_tc1['__DCON0_VALUE']))
        header_file.write("\n")
        header_file.write("#endif /*__NO_CSTART_REGISTER_CONFIG */\n")
        header_file.write("\n")
        header_file.write("#endif /* CSTART_TC1_H */\n")

    # tc2 header create
    save_file_name = save_file_path + "\\prost_cstart_tc2.h"
    with open(save_file_name, 'wt', encoding='utf-8', newline='') as header_file:
        header_file.write("/**************************************************************************\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  FILE        :  cstart_tc2.h                                           *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  DESCRIPTION :                                                         *\n")
        header_file.write("**      Header file to control the system startup code's general settings *\n")
        header_file.write("**      and register initializations. The cstart__tc2.c file must be part *\n")
        header_file.write("**      of your project to make use of this cstart__tc2.h.                *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**      In the Eclipse environment this file can be modified using the    *\n")
        header_file.write("**      C startup code editor, which provides a GUI to modify the         *\n")
        header_file.write("**      Configuration settings and register initialization.               *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  Copyright 1996-2018 TASKING BV                                        *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**************************************************************************/\n")
        header_file.write("\n")
        header_file.write("#ifndef PROST_CSTART_TC2_H\n")
        header_file.write("#define PROST_CSTART_TC2_H\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * These items are shown in Eclipse on the C Start Configuration page\n")
        header_file.write(" */\n")
        header_file.write("\n")
        header_file.write("#ifndef __NO_CSTART_DEFAULT_CONFIG\n")
        header_file.write("\n")
        header_file.write("/* C Startup settings */\n")
        header_file.write(
            "#define __BIV_TC2_INIT          {}       /* Initialize base address of interrupt vector table */\n".format(
                origin_data_tc2['__BIV_TC2_INIT']))
        header_file.write(
            "#define __BIV_SINGLE_TC2_INIT   {}       /* Initialize single entry interrupt vector table */\n".format(
                origin_data_tc2['__BIV_SINGLE_TC2_INIT']))
        header_file.write(
            "#define __BIV_8BYTE_TC2_INIT    {}       /* Initialize 8 byte spacing interrupt vector table */\n".format(
                origin_data_tc2['__BIV_8BYTE_TC2_INIT']))
        header_file.write(
            "#define __BTV_TC2_INIT          {}       /* Initialize base address of trap vector table */\n".format(
                origin_data_tc2['__BTV_TC2_INIT']))
        header_file.write("#define __CSA_TC2_INIT          {}       /* Initialize CSA lists */\n".format(
            origin_data_tc2['__CSA_TC2_INIT']))
        header_file.write("#define __C_TC2_INIT            {}       /* Initialize and clear C variables */\n".format(
            origin_data_tc2['__C_TC2_INIT']))
        header_file.write("#define __USP_TC2_INIT          {}       /* Initialize user stack pointer */\n".format(
            origin_data_tc2['__USP_TC2_INIT']))
        header_file.write("#define __ISP_TC2_INIT          {}       /* Initialize interrupt stack pointer */\n".format(
            origin_data_tc2['__ISP_TC2_INIT']))
        header_file.write(
            "#define __A0A1_TC2_INIT         {}       /* Initialize a0 and a1 for _a0/_a1 addressing */\n".format(
                origin_data_tc2['__A0A1_TC2_INIT']))
        header_file.write(
            "#define __A8A9_TC2_INIT         {}       /* Initialize a8 and a9 for _a8/_a9 addressing (OS support) */\n".format(
                origin_data_tc2['__A8A9_TC2_INIT']))
        header_file.write("#define __RM_TC2_INIT           {}       /* Initialize rounding mode */\n".format(
            origin_data_tc2['__RM_TC2_INIT']))
        header_file.write(
            "#define __RM_TC2_VALUE          {}  /* FE_TONEAREST, FE_UPWARD, FE_DOWNWARD or FE_TOWARDZERO */\n".format(
                origin_data_tc2['__RM_TC2_VALUE']))
        header_file.write("\n")
        header_file.write(
            "#define __CDC_TC2                       {}     /* Call Depth Counter (set PSW.CDC) */\n".format(
                origin_data_tc2['__CDC_TC2']))
        header_file.write(
            "#define __USER_STACK_TC2                {}       /* Use the user stack (clear PSW.IS) */\n".format(
                origin_data_tc2['__USER_STACK_TC2']))
        header_file.write(
            "#define __COMPAT_TC2            {}     /* Compatibility mode */\n".format(origin_data_tc2['__COMPAT_TC2']))
        header_file.write("#define __USE_ARGC_ARGV_TC2     {}       /* Enable passing argc/argv to main() */\n".format(
            origin_data_tc2['__USE_ARGC_ARGV_TC2']))
        header_file.write("#define __ARGCV_BUFSIZE_TC2     {}     /* Buffer size for argv */\n".format(
            origin_data_tc2['__ARGCV_BUFSIZE_TC2']))
        header_file.write("\n")
        header_file.write("/* Trap Vectors */\n")
        header_file.write("#define __RESOLVE_TRAP_0_TC2    {}       /* Class 0: MMU */\n".format(
            origin_data_tc2['__RESOLVE_TRAP_0_TC2']))
        header_file.write("#define __RESOLVE_TRAP_1_TC2    {}       /* Class 1: Internal protection */\n".format(
            origin_data_tc2['__RESOLVE_TRAP_1_TC2']))
        header_file.write("#define __RESOLVE_TRAP_2_TC2    {}       /* Class 2: Instruction error */\n".format(
            origin_data_tc2['__RESOLVE_TRAP_2_TC2']))
        header_file.write("#define __RESOLVE_TRAP_3_TC2    {}       /* Class 3: Context management */\n".format(
            origin_data_tc2['__RESOLVE_TRAP_3_TC2']))
        header_file.write(
            "#define __RESOLVE_TRAP_4_TC2    {}       /* Class 4: System bus and peripheral errors */\n".format(
                origin_data_tc2['__RESOLVE_TRAP_4_TC2']))
        header_file.write("#define __RESOLVE_TRAP_5_TC2    {}       /* Class 5: Assertion */\n".format(
            origin_data_tc2['__RESOLVE_TRAP_5_TC2']))
        header_file.write("#define __RESOLVE_TRAP_6_TC2    {}       /* Class 6: System call */\n".format(
            origin_data_tc2['__RESOLVE_TRAP_6_TC2']))
        header_file.write("#define __RESOLVE_TRAP_7_TC2    {}       /* Class 7: Non-maskable interrupt */\n".format(
            origin_data_tc2['__RESOLVE_TRAP_7_TC2']))
        header_file.write("\n")
        header_file.write("#endif /* __NO_CSTART_DEFAULT_CONFIG */\n")
        header_file.write("\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * Control of initialization registers\n")
        header_file.write(" *\n")
        header_file.write(" * The *_VALUE macros define the value of the register\n")
        header_file.write(" * The *_INIT macros must be defined to 0 or 1, specifying whether\n")
        header_file.write(" * or not it will be intialized by the cstart.c code.\n")
        header_file.write(" *\n")
        header_file.write(" * Most registers are not set to be initialized, which means that\n")
        header_file.write(" * the CPU's defaults are used. The bus configuration registers will be\n")
        header_file.write(" * set by running the 'Target Board Configuration' wizard.\n")
        header_file.write(" * The Eclipse environment will automatically apply the CPU default\n")
        header_file.write(" * values to the registers. These defaults are defined in the SFR files\n")
        header_file.write(" * from the include/sfr directory of the product.\n")
        header_file.write(" *\n")
        header_file.write(" */\n")
        header_file.write("#ifndef __NO_CSTART_REGISTER_CONFIG\n")
        header_file.write("\n")
        header_file.write("#define __PCON0_INIT            {}\n".format(origin_data_tc2['__PCON0_INIT']))
        header_file.write("#define __PCON0_VALUE           {}\n".format(origin_data_tc2['__PCON0_VALUE']))
        header_file.write("#define __DCON0_INIT            {}\n".format(origin_data_tc2['__DCON0_INIT']))
        header_file.write("#define __DCON0_VALUE           {}\n".format(origin_data_tc2['__DCON0_VALUE']))
        header_file.write("\n")
        header_file.write("#endif /*__NO_CSTART_REGISTER_CONFIG */\n")
        header_file.write("\n")
        header_file.write("#endif /* CSTART_TC2_H */\n")
        header_file.write("\n")

def tasking_v42_tc29x_h_modify_save(save_file_path):
    # tc0 header create
    save_file_name = save_file_path + "\\prost_cstart.h"
    with open(save_file_name, 'wt', encoding='utf-8', newline='') as header_file:
        header_file.write("/**************************************************************************\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  FILE        :  cstart.h                                               *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  DESCRIPTION :                                                         *\n")
        header_file.write("**      Header file to control the system startup code's general settings *\n")
        header_file.write("**      and register initializations. The cstart.c file must be part of   *\n")
        header_file.write("**      your project to make use of this cstart.h.                        *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**      In the Eclipse environment this file can be modified using the    *\n")
        header_file.write("**      C startup code editor, which provides a GUI to modify the         *\n")
        header_file.write("**      Configuration settings and register initialization.               *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  Copyright 1996-2013 Altium BV                                         *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**************************************************************************/\n")
        header_file.write("\n")
        header_file.write("#ifndef PROST_CSTART_H\n")
        header_file.write("#define PROST_CSTART_H\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * These items are shown on in Eclipse on the C Start Configuration page\n")
        header_file.write(" */\n")
        header_file.write("\n")
        header_file.write("#ifndef __NO_CSTART_DEFAULT_CONFIG\n")
        header_file.write("\n")
        header_file.write("/* C Startup settings */\n")
        header_file.write(
            "#define __BIV_INIT              {}       /* Initialize base address of interrupt vector table */\n".format(
                origin_data_tc['__BIV_INIT']))
        header_file.write(
            "#define __BIV_SINGLE_INIT       {}       /* Initialize single entry interrupt vector table */\n".format(
                origin_data_tc['__BIV_SINGLE_INIT']))
        header_file.write(
            "#define __BIV_8BYTE_INIT        {}       /* Initialize 8 byte spacing interrupt vector table */\n".format(
                origin_data_tc['__BIV_8BYTE_INIT']))
        header_file.write(
            "#define __BTV_INIT              {}       /* Initialize base address of trap vector table */\n".format(
                origin_data_tc['__BTV_INIT']))
        header_file.write(
            "#define __CSA_INIT              {}       /* Initialize CSA lists */\n".format(origin_data_tc['__CSA_INIT']))
        header_file.write("#define __C_INIT                {}       /* Initialize and clear C variables */\n".format(
            origin_data_tc['__C_INIT']))
        header_file.write("#define __USP_INIT              {}       /* Initialize user stack pointer */\n".format(
            origin_data_tc['__USP_INIT']))
        header_file.write("#define __ISP_INIT              {}       /* Initialize interrupt stack pointer */\n".format(
            origin_data_tc['__ISP_INIT']))
        header_file.write(
            "#define __A0A1_INIT             {}       /* Initialize a0 and a1 for _a0/_a1 addressing */\n".format(
                origin_data_tc['__A0A1_INIT']))
        header_file.write(
            "#define __A8A9_INIT             {}       /* Initialize a8 and a9 for _a8/_a9 addressing (OS support) */\n".format(
                origin_data_tc['__A8A9_INIT']))
        header_file.write("\n")
        header_file.write("#define __USER_STACK            {}       /* Use the user stack (clear PSW.IS) */\n".format(
            origin_data_tc['__USER_STACK']))
        header_file.write("#define __WATCHDOG_DISABLE      {}       /* Watchdog disable */\n".format(
            origin_data_tc['__WATCHDOG_DISABLE']))
        header_file.write("#define __SAFETY_WATCHDOG_DISABLE {}     /* Safety watchdog disable */\n".format(
            origin_data_tc['__SAFETY_WATCHDOG_DISABLE']))
        header_file.write("#define __USE_ARGC_ARGV         {}       /* Enable passing argc/argv to main() */\n".format(
            origin_data_tc['__USE_ARGC_ARGV']))
        header_file.write("#define __ARGCV_BUFSIZE       {}       /* Buffer size for argv */\n".format(
            origin_data_tc['__ARGCV_BUFSIZE']))
        header_file.write("#define __CLOCKS_PER_SEC_INIT   {}       /* Initialize clocks per sec */\n".format(
            origin_data_tc['__CLOCKS_PER_SEC_INIT']))
        header_file.write(
            "#define __fOSC           {}       /* Oscillator frequency Hz */\n".format(origin_data_tc['__fOSC']))
        header_file.write(
            "#define __PLL_K2_RAMPUP         {}       /* PLL K2 rampup */\n".format(origin_data_tc['__PLL_K2_RAMPUP']))
        header_file.write(
            "#define __STADD_INIT_TC1        {}       /* Initialize start address TC1 */\n".format(origin_data_tc['__STADD_INIT_TC1']))
        header_file.write(
            "#define __STADD_INIT_TC2        {}       /* Initialize start address TC2 */\n".format(origin_data_tc['__STADD_INIT_TC2']))
        header_file.write(
            "#define __HALT_INIT_TC1        {}       /* Initialize HALT state of TC1 */\n".format(origin_data_tc['__HALT_INIT_TC1']))
        header_file.write(
            "#define __HALT_INIT_TC2        {}       /* Initialize HALT state of TC2 */\n".format(origin_data_tc['__HALT_INIT_TC2']))
        header_file.write(
            "#define __HALT_VALUE_TC1        {}       /* Set HALT value of TC1 */\n".format(origin_data_tc['__HALT_VALUE_TC1']))
        header_file.write("                                        /* 0 R:running W:unchanged\n")
        header_file.write("                                           1 R:halted W:unchanged\n")
        header_file.write("                                           2 R:n.a. W:reset halt\n")
        header_file.write("                                           3 R:n.a. W:set when debug enable\n")
        header_file.write("                                        */\n")
        header_file.write(
            "#define __HALT_VALUE_TC2        {}       /* Set HALT value of TC1 */\n".format(
                origin_data_tc['__HALT_VALUE_TC2']))
        header_file.write("                                        /* 0 R:running W:unchanged\n")
        header_file.write("                                           1 R:halted W:unchanged\n")
        header_file.write("                                           2 R:n.a. W:reset halt\n")
        header_file.write("                                           3 R:n.a. W:set when debug enable\n")
        header_file.write("                                        */\n")
        header_file.write("\n")
        header_file.write("/* Trap Vectors */\n")
        header_file.write(
            "#define __RESOLVE_TRAP_0        {}       /* Class 0: MMU */\n".format(origin_data_tc['__RESOLVE_TRAP_0']))
        header_file.write("#define __RESOLVE_TRAP_1        {}       /* Class 1: Internal protection */\n".format(
            origin_data_tc['__RESOLVE_TRAP_1']))
        header_file.write("#define __RESOLVE_TRAP_2        {}       /* Class 2: Instruction error */\n".format(
            origin_data_tc['__RESOLVE_TRAP_2']))
        header_file.write("#define __RESOLVE_TRAP_3        {}       /* Class 3: Context management */\n".format(
            origin_data_tc['__RESOLVE_TRAP_3']))
        header_file.write(
            "#define __RESOLVE_TRAP_4        {}       /* Class 4: System bus and peripheral errors */\n".format(
                origin_data_tc['__RESOLVE_TRAP_4']))
        header_file.write("#define __RESOLVE_TRAP_5        {}       /* Class 5: Assertion */\n".format(
            origin_data_tc['__RESOLVE_TRAP_5']))
        header_file.write("#define __RESOLVE_TRAP_6        {}       /* Class 6: System call */\n".format(
            origin_data_tc['__RESOLVE_TRAP_6']))
        header_file.write("#define __RESOLVE_TRAP_7        {}       /* Class 7: Non-maskable interrupt */\n".format(
            origin_data_tc['__RESOLVE_TRAP_7']))
        header_file.write("\n")
        header_file.write("\n")
        header_file.write("#endif /* __NO_CSTART_DEFAULT_CONFIG */\n")
        header_file.write("\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * Control of initialization registers\n")
        header_file.write(" *\n")
        header_file.write(" * The *_VALUE macros define the value of the register\n")
        header_file.write(" * The *_INIT macros must be defined to 0 or 1, specifying whether\n")
        header_file.write(" * or not it will be intialized by the cstart.c code.\n")
        header_file.write(" *\n")
        header_file.write(" * Most registers are not set to be initialized, which means that\n")
        header_file.write(" * the CPU's defaults are used. The bus configuration registers will be\n")
        header_file.write(" * set by running the 'Target Board Configuration' wizard.\n")
        header_file.write(" * The Eclipse environment will automatically apply the CPU default\n")
        header_file.write(" * values to the registers. These defaults are defined in the SFR files\n")
        header_file.write(" * from the include/sfr directory of the product.\n")
        header_file.write(" *\n")
        header_file.write(" */\n")
        header_file.write("\n")
        header_file.write("#define __EBU_BOOTCFG_INIT      {}\n".format(origin_data_tc['__EBU_BOOTCFG_INIT']))
        header_file.write("#define __EBU_BOOTCFG_VALUE     {}\n".format(origin_data_tc['__EBU_BOOTCFG_VALUE']))
        header_file.write("\n")
        header_file.write("#ifndef __NO_CSTART_REGISTER_CONFIG\n")
        header_file.write("/* Non-bus configuration: */\n")
        header_file.write("#define __PMI_CON0_INIT         {}\n".format(origin_data_tc['__PMI_CON0_INIT']))
        header_file.write("#define __PMI_CON0_VALUE        {}\n".format(origin_data_tc['__PMI_CON0_VALUE']))
        header_file.write("#define __PMI_CON1_INIT         {}\n".format(origin_data_tc['__PMI_CON1_INIT']))
        header_file.write("#define __PMI_CON1_VALUE        {}\n".format(origin_data_tc['__PMI_CON1_VALUE']))
        header_file.write("#define __PMI_CON2_INIT         {}\n".format(origin_data_tc['__PMI_CON2_INIT']))
        header_file.write("#define __PMI_CON2_VALUE        {}\n".format(origin_data_tc['__PMI_CON2_VALUE']))
        header_file.write("#define __PMU_EIFCON_INIT       {}\n".format(origin_data_tc['__PMU_EIFCON_INIT']))
        header_file.write("#define __PMU_EIFCON_VALUE      {}\n".format(origin_data_tc['__PMU_EIFCON_VALUE']))
        header_file.write("#define __DMI_CON_INIT          {}\n".format(origin_data_tc['__DMI_CON_INIT']))
        header_file.write("#define __DMI_CON_VALUE         {}\n".format(origin_data_tc['__DMI_CON_VALUE']))
        header_file.write("#define __PLL_CLC_INIT          {}\n".format(origin_data_tc['__PLL_CLC_INIT']))
        header_file.write("#define __PLL_CLC_VALUE         {}\n".format(origin_data_tc['__PLL_CLC_VALUE']))
        header_file.write("#define __SCU_PLLCON0_INIT      {}\n".format(origin_data_tc['__SCU_PLLCON0_INIT']))
        header_file.write("#define __SCU_PLLCON0_VALUE     {}\n".format(origin_data_tc['__SCU_PLLCON0_VALUE']))
        header_file.write("#define __SCU_PLLCON1_INIT      {}\n".format(origin_data_tc['__SCU_PLLCON1_INIT']))
        header_file.write("#define __SCU_PLLCON1_VALUE     {}\n".format(origin_data_tc['__SCU_PLLCON1_VALUE']))
        header_file.write("#define __SCU_OSCCON_INIT       {}\n".format(origin_data_tc['__SCU_OSCCON_INIT']))
        header_file.write("#define __SCU_OSCCON_VALUE      {}\n".format(origin_data_tc['__SCU_OSCCON_VALUE']))
        header_file.write("#define __SCU_CCUCON0_INIT      {}\n".format(origin_data_tc['__SCU_CCUCON0_INIT']))
        header_file.write("#define __SCU_CCUCON0_VALUE     {}\n".format(origin_data_tc['__SCU_CCUCON0_VALUE']))
        header_file.write("#define __SCU_CCUCON1_INIT      {}\n".format(origin_data_tc['__SCU_CCUCON1_INIT']))
        header_file.write("#define __SCU_CCUCON1_VALUE     {}\n".format(origin_data_tc['__SCU_CCUCON1_VALUE']))
        header_file.write("#define __SCU_CCUCON2_INIT      {}\n".format(origin_data_tc['__SCU_CCUCON2_INIT']))
        header_file.write("#define __SCU_CCUCON2_VALUE     {}\n".format(origin_data_tc['__SCU_CCUCON2_VALUE']))
        header_file.write("#define __STM_CLC_INIT          {}\n".format(origin_data_tc['__STM_CLC_INIT']))
        header_file.write("#define __STM_CLC_VALUE         {}\n".format(origin_data_tc['__STM_CLC_VALUE']))
        header_file.write("#define __GTM_CLC_INIT          {}\n".format(origin_data_tc['__GTM_CLC_INIT']))
        header_file.write("#define __GTM_CLC_VALUE         {}\n".format(origin_data_tc['__GTM_CLC_VALUE']))
        header_file.write("#define __FLASH0_FCON_INIT      {}\n".format(origin_data_tc['__FLASH0_FCON_INIT']))
        header_file.write("#define __FLASH0_FCON_VALUE     {}\n".format(origin_data_tc['__FLASH0_FCON_VALUE']))
        header_file.write("#define __FLASH1_FCON_INIT      {}\n".format(origin_data_tc['__FLASH1_FCON_INIT']))
        header_file.write("#define __FLASH1_FCON_VALUE     {}\n".format(origin_data_tc['__FLASH1_FCON_VALUE']))
        header_file.write("/* Bus configuration: (set by 'Target Board Configuration' wizard) */\n")
        header_file.write("#define __EBU_ADDRSEL0_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL0_INIT']))
        header_file.write("#define __EBU_ADDRSEL0_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL0_VALUE']))
        header_file.write("#define __EBU_ADDRSEL1_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL1_INIT']))
        header_file.write("#define __EBU_ADDRSEL1_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL1_VALUE']))
        header_file.write("#define __EBU_ADDRSEL2_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL2_INIT']))
        header_file.write("#define __EBU_ADDRSEL2_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL2_VALUE']))
        header_file.write("#define __EBU_ADDRSEL3_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL3_INIT']))
        header_file.write("#define __EBU_ADDRSEL3_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL3_VALUE']))
        header_file.write("#define __EBU_ADDRSEL4_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL4_INIT']))
        header_file.write("#define __EBU_ADDRSEL4_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL4_VALUE']))
        header_file.write("#define __EBU_ADDRSEL5_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL5_INIT']))
        header_file.write("#define __EBU_ADDRSEL5_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL5_VALUE']))
        header_file.write("#define __EBU_ADDRSEL6_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL6_INIT']))
        header_file.write("#define __EBU_ADDRSEL6_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL6_VALUE']))
        header_file.write("#define __EBU_BFCON_INIT        {}\n".format(origin_data_tc['__EBU_BFCON_INIT']))
        header_file.write("#define __EBU_BFCON_VALUE       {}\n".format(origin_data_tc['__EBU_BFCON_VALUE']))
        header_file.write("#define __EBU_BUSAP0_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP0_INIT']))
        header_file.write("#define __EBU_BUSAP0_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP0_VALUE']))
        header_file.write("#define __EBU_BUSAP1_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP1_INIT']))
        header_file.write("#define __EBU_BUSAP1_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP1_VALUE']))
        header_file.write("#define __EBU_BUSAP2_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP2_INIT']))
        header_file.write("#define __EBU_BUSAP2_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP2_VALUE']))
        header_file.write("#define __EBU_BUSAP3_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP3_INIT']))
        header_file.write("#define __EBU_BUSAP3_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP3_VALUE']))
        header_file.write("#define __EBU_BUSAP4_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP4_INIT']))
        header_file.write("#define __EBU_BUSAP4_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP4_VALUE']))
        header_file.write("#define __EBU_BUSAP5_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP5_INIT']))
        header_file.write("#define __EBU_BUSAP5_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP5_VALUE']))
        header_file.write("#define __EBU_BUSAP6_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP6_INIT']))
        header_file.write("#define __EBU_BUSAP6_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP6_VALUE']))
        header_file.write("#define __EBU_BUSCON0_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON0_INIT']))
        header_file.write("#define __EBU_BUSCON0_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON0_VALUE']))
        header_file.write("#define __EBU_BUSCON1_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON1_INIT']))
        header_file.write("#define __EBU_BUSCON1_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON1_VALUE']))
        header_file.write("#define __EBU_BUSCON2_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON2_INIT']))
        header_file.write("#define __EBU_BUSCON2_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON2_VALUE']))
        header_file.write("#define __EBU_BUSCON3_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON3_INIT']))
        header_file.write("#define __EBU_BUSCON3_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON3_VALUE']))
        header_file.write("#define __EBU_BUSCON4_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON4_INIT']))
        header_file.write("#define __EBU_BUSCON4_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON4_VALUE']))
        header_file.write("#define __EBU_BUSCON5_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON5_INIT']))
        header_file.write("#define __EBU_BUSCON5_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON5_VALUE']))
        header_file.write("#define __EBU_BUSCON6_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON6_INIT']))
        header_file.write("#define __EBU_BUSCON6_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON6_VALUE']))
        header_file.write("#define __EBU_CLC_INIT          {}\n".format(origin_data_tc['__EBU_CLC_INIT']))
        header_file.write("#define __EBU_CLC_VALUE         {}\n".format(origin_data_tc['__EBU_CLC_VALUE']))
        header_file.write("#define __EBU_CON_INIT          {}\n".format(origin_data_tc['__EBU_CON_INIT']))
        header_file.write("#define __EBU_CON_VALUE         {}\n".format(origin_data_tc['__EBU_CON_VALUE']))
        header_file.write("#define __EBU_EMUAS_INIT        {}\n".format(origin_data_tc['__EBU_EMUAS_INIT']))
        header_file.write("#define __EBU_EMUAS_VALUE       {}\n".format(origin_data_tc['__EBU_EMUAS_VALUE']))
        header_file.write("#define __EBU_EMUBAP_INIT       {}\n".format(origin_data_tc['__EBU_EMUBAP_INIT']))
        header_file.write("#define __EBU_EMUBAP_VALUE      {}\n".format(origin_data_tc['__EBU_EMUBAP_VALUE']))
        header_file.write("#define __EBU_EMUBC_INIT        {}\n".format(origin_data_tc['__EBU_EMUBC_INIT']))
        header_file.write("#define __EBU_EMUBC_VALUE       {}\n".format(origin_data_tc['__EBU_EMUBC_VALUE']))
        header_file.write("#define __EBU_EMUCON_INIT       {}\n".format(origin_data_tc['__EBU_EMUCON_INIT']))
        header_file.write("#define __EBU_EMUCON_VALUE      {}\n".format(origin_data_tc['__EBU_EMUCON_VALUE']))
        header_file.write("#define __EBU_EMUOVL_INIT       {}\n".format(origin_data_tc['__EBU_EMUOVL_INIT']))
        header_file.write("#define __EBU_EMUOVL_VALUE      {}\n".format(origin_data_tc['__EBU_EMUOVL_VALUE']))
        header_file.write("#define __EBU_SDRMCON0_INIT     {}\n".format(origin_data_tc['__EBU_SDRMCON0_INIT']))
        header_file.write("#define __EBU_SDRMCON0_VALUE    {}\n".format(origin_data_tc['__EBU_SDRMCON0_VALUE']))
        header_file.write("#define __EBU_SDRMCON1_INIT     {}\n".format(origin_data_tc['__EBU_SDRMCON1_INIT']))
        header_file.write("#define __EBU_SDRMCON1_VALUE    {}\n".format(origin_data_tc['__EBU_SDRMCON1_VALUE']))
        header_file.write("#define __EBU_SDRMOD0_INIT      {}\n".format(origin_data_tc['__EBU_SDRMOD0_INIT']))
        header_file.write("#define __EBU_SDRMOD0_VALUE     {}\n".format(origin_data_tc['__EBU_SDRMOD0_VALUE']))
        header_file.write("#define __EBU_SDRMOD1_INIT      {}\n".format(origin_data_tc['__EBU_SDRMOD1_INIT']))
        header_file.write("#define __EBU_SDRMOD1_VALUE     {}\n".format(origin_data_tc['__EBU_SDRMOD1_VALUE']))
        header_file.write("#define __EBU_SDRMREF0_INIT     {}\n".format(origin_data_tc['__EBU_SDRMREF0_INIT']))
        header_file.write("#define __EBU_SDRMREF0_VALUE    {}\n".format(origin_data_tc['__EBU_SDRMREF0_VALUE']))
        header_file.write("#define __EBU_SDRMREF1_INIT     {}\n".format(origin_data_tc['__EBU_SDRMREF1_INIT']))
        header_file.write("#define __EBU_SDRMREF1_VALUE    {}\n".format(origin_data_tc['__EBU_SDRMREF1_VALUE']))
        header_file.write("#define __CBS_MCDBBS_INIT       {}\n".format(origin_data_tc['__CBS_MCDBBS_INIT']))
        header_file.write("#define __CBS_MCDBBS_VALUE      {}\n".format(origin_data_tc['__CBS_MCDBBS_VALUE']))
        header_file.write("#define __SBCU_CON_INIT         {}\n".format(origin_data_tc['__SBCU_CON_INIT']))
        header_file.write("#define __SBCU_CON_VALUE        {}\n".format(origin_data_tc['__SBCU_CON_VALUE']))
        header_file.write("#define __EBU_BUSRAP1_INIT      {}\n".format(origin_data_tc['__EBU_BUSRAP1_INIT']))
        header_file.write("#define __EBU_BUSRAP1_VALUE     {}\n".format(origin_data_tc['__EBU_BUSRAP1_VALUE']))
        header_file.write("#define __EBU_BUSRAP0_INIT      {}\n".format(origin_data_tc['__EBU_BUSRAP0_INIT']))
        header_file.write("#define __EBU_BUSRAP0_VALUE     {}\n".format(origin_data_tc['__EBU_BUSRAP0_VALUE']))
        header_file.write("#define __EBU_BUSRAP2_INIT      {}\n".format(origin_data_tc['__EBU_BUSRAP2_INIT']))
        header_file.write("#define __EBU_BUSRAP2_VALUE     {}\n".format(origin_data_tc['__EBU_BUSRAP2_VALUE']))
        header_file.write("#define __EBU_BUSRAP3_INIT      {}\n".format(origin_data_tc['__EBU_BUSRAP3_INIT']))
        header_file.write("#define __EBU_BUSRAP3_VALUE     {}\n".format(origin_data_tc['__EBU_BUSRAP3_VALUE']))
        header_file.write("#define __EBU_BUSRCON0_INIT     {}\n".format(origin_data_tc['__EBU_BUSRCON0_INIT']))
        header_file.write("#define __EBU_BUSRCON0_VALUE    {}\n".format(origin_data_tc['__EBU_BUSRCON0_VALUE']))
        header_file.write("#define __EBU_BUSRCON1_INIT     {}\n".format(origin_data_tc['__EBU_BUSRCON1_INIT']))
        header_file.write("#define __EBU_BUSRCON1_VALUE    {}\n".format(origin_data_tc['__EBU_BUSRCON1_VALUE']))
        header_file.write("#define __EBU_BUSRCON2_INIT     {}\n".format(origin_data_tc['__EBU_BUSRCON2_INIT']))
        header_file.write("#define __EBU_BUSRCON2_VALUE    {}\n".format(origin_data_tc['__EBU_BUSRCON2_VALUE']))
        header_file.write("#define __EBU_BUSRCON3_INIT     {}\n".format(origin_data_tc['__EBU_BUSRCON3_INIT']))
        header_file.write("#define __EBU_BUSRCON3_VALUE    {}\n".format(origin_data_tc['__EBU_BUSRCON3_VALUE']))
        header_file.write("#define __EBU_BUSWAP0_INIT      {}\n".format(origin_data_tc['__EBU_BUSWAP0_INIT']))
        header_file.write("#define __EBU_BUSWAP0_VALUE     {}\n".format(origin_data_tc['__EBU_BUSWAP0_VALUE']))
        header_file.write("#define __EBU_BUSWAP1_INIT      {}\n".format(origin_data_tc['__EBU_BUSWAP1_INIT']))
        header_file.write("#define __EBU_BUSWAP1_VALUE     {}\n".format(origin_data_tc['__EBU_BUSWAP1_VALUE']))
        header_file.write("#define __EBU_BUSWAP2_INIT      {}\n".format(origin_data_tc['__EBU_BUSWAP2_INIT']))
        header_file.write("#define __EBU_BUSWAP2_VALUE     {}\n".format(origin_data_tc['__EBU_BUSWAP2_VALUE']))
        header_file.write("#define __EBU_BUSWAP3_INIT      {}\n".format(origin_data_tc['__EBU_BUSWAP3_INIT']))
        header_file.write("#define __EBU_BUSWAP3_VALUE     {}\n".format(origin_data_tc['__EBU_BUSWAP3_VALUE']))
        header_file.write("#define __EBU_BUSWCON0_INIT     {}\n".format(origin_data_tc['__EBU_BUSWCON0_INIT']))
        header_file.write("#define __EBU_BUSWCON0_VALUE    {}\n".format(origin_data_tc['__EBU_BUSWCON0_VALUE']))
        header_file.write("#define __EBU_BUSWCON1_INIT     {}\n".format(origin_data_tc['__EBU_BUSWCON1_INIT']))
        header_file.write("#define __EBU_BUSWCON1_VALUE    {}\n".format(origin_data_tc['__EBU_BUSWCON1_VALUE']))
        header_file.write("#define __EBU_BUSWCON2_INIT     {}\n".format(origin_data_tc['__EBU_BUSWCON2_INIT']))
        header_file.write("#define __EBU_BUSWCON2_VALUE    {}\n".format(origin_data_tc['__EBU_BUSWCON2_VALUE']))
        header_file.write("#define __EBU_BUSWCON3_INIT     {}\n".format(origin_data_tc['__EBU_BUSWCON3_INIT']))
        header_file.write("#define __EBU_BUSWCON3_VALUE    {}\n".format(origin_data_tc['__EBU_BUSWCON3_VALUE']))
        header_file.write("#define __EBU_EXTBOOT_INIT      {}\n".format(origin_data_tc['__EBU_EXTBOOT_INIT']))
        header_file.write("#define __EBU_EXTBOOT_VALUE     {}\n".format(origin_data_tc['__EBU_EXTBOOT_VALUE']))
        header_file.write("#define __EBU_MODCON_INIT       {}\n".format(origin_data_tc['__EBU_MODCON_INIT']))
        header_file.write("#define __EBU_MODCON_VALUE      {}\n".format(origin_data_tc['__EBU_MODCON_VALUE']))
        header_file.write("#define __EBU_DDRNCON_INIT      {}\n".format(origin_data_tc['__EBU_DDRNCON_INIT']))
        header_file.write("#define __EBU_DDRNCON_VALUE     {}\n".format(origin_data_tc['__EBU_DDRNCON_VALUE']))
        header_file.write("#define __EBU_DDRNMOD_INIT      {}\n".format(origin_data_tc['__EBU_DDRNMOD_INIT']))
        header_file.write("#define __EBU_DDRNMOD_VALUE     {}\n".format(origin_data_tc['__EBU_DDRNMOD_VALUE']))
        header_file.write("#define __EBU_DDRNMOD2_INIT     {}\n".format(origin_data_tc['__EBU_DDRNMOD2_INIT']))
        header_file.write("#define __EBU_DDRNMOD2_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNMOD2_VALUE']))
        header_file.write("#define __EBU_DDRNPRLD_INIT     {}\n".format(origin_data_tc['__EBU_DDRNPRLD_INIT']))
        header_file.write("#define __EBU_DDRNPRLD_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNPRLD_VALUE']))
        header_file.write("#define __EBU_DDRNTAG0_INIT     {}\n".format(origin_data_tc['__EBU_DDRNTAG0_INIT']))
        header_file.write("#define __EBU_DDRNTAG0_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNTAG0_VALUE']))
        header_file.write("#define __EBU_DDRNTAG1_INIT     {}\n".format(origin_data_tc['__EBU_DDRNTAG1_INIT']))
        header_file.write("#define __EBU_DDRNTAG1_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNTAG1_VALUE']))
        header_file.write("#define __EBU_DDRNTAG2_INIT     {}\n".format(origin_data_tc['__EBU_DDRNTAG2_INIT']))
        header_file.write("#define __EBU_DDRNTAG2_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNTAG2_VALUE']))
        header_file.write("#define __EBU_DDRNTAG3_INIT     {}\n".format(origin_data_tc['__EBU_DDRNTAG3_INIT']))
        header_file.write("#define __EBU_DDRNTAG3_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNTAG3_VALUE']))
        header_file.write("#define __EBU_DLLCON_INIT       {}\n".format(origin_data_tc['__EBU_DLLCON_INIT']))
        header_file.write("#define __EBU_DLLCON_VALUE      {}\n".format(origin_data_tc['__EBU_DLLCON_VALUE']))
        header_file.write("#define __EBU_SDRMCON_INIT      {}\n".format(origin_data_tc['__EBU_SDRMCON_INIT']))
        header_file.write("#define __EBU_SDRMCON_VALUE     {}\n".format(origin_data_tc['__EBU_SDRMCON_VALUE']))
        header_file.write("#define __EBU_SDRMOD_INIT       {}\n".format(origin_data_tc['__EBU_SDRMOD_INIT']))
        header_file.write("#define __EBU_SDRMOD_VALUE      {}\n".format(origin_data_tc['__EBU_SDRMOD_VALUE']))
        header_file.write("#define __EBU_SDRMREF_INIT      {}\n".format(origin_data_tc['__EBU_SDRMREF_INIT']))
        header_file.write("#define __EBU_SDRMREF_VALUE     {}\n".format(origin_data_tc['__EBU_SDRMREF_VALUE']))
        header_file.write("#define __EBU_SDRSTAT_INIT      {}\n".format(origin_data_tc['__EBU_SDRSTAT_INIT']))
        header_file.write("#define __EBU_SDRSTAT_VALUE     {}\n".format(origin_data_tc['__EBU_SDRSTAT_VALUE']))
        header_file.write("#define __PCON0_INIT            {}\n".format(origin_data_tc['__PCON0_INIT']))
        header_file.write("#define __PCON0_VALUE           {}\n".format(origin_data_tc['__PCON0_VALUE']))
        header_file.write("#define __DCON0_INIT            {}\n".format(origin_data_tc['__DCON0_INIT']))
        header_file.write("#define __DCON0_VALUE           {}\n".format(origin_data_tc['__DCON0_VALUE']))
        header_file.write("\n")
        header_file.write("#endif /*__NO_CSTART_REGISTER_CONFIG */\n")
        header_file.write("\n")
        header_file.write("#endif /* CSTART_H */\n")

    # tc1 header create
    save_file_name = save_file_path + "\\prost_cstart_tc1.h"
    with open(save_file_name, 'wt', encoding='utf-8', newline='') as header_file:
        header_file.write("/**************************************************************************\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  FILE        :  cstart_tc1.h                                           *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  DESCRIPTION :                                                         *\n")
        header_file.write("**      Header file to control the system startup code's general settings *\n")
        header_file.write("**      and register initializations. The cstart__tc1.c file must be part *\n")
        header_file.write("**      of your project to make use of this cstart__tc1.h.                *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**      In the Eclipse environment this file can be modified using the    *\n")
        header_file.write("**      C startup code editor, which provides a GUI to modify the         *\n")
        header_file.write("**      Configuration settings and register initialization.               *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  Copyright 1996-2013 Altium BV                                         *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**************************************************************************/\n")
        header_file.write("\n")
        header_file.write("#ifndef PROST_CSTART_TC1_H\n")
        header_file.write("#define PROST_CSTART_TC1_H\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * These items are shown in Eclipse on the C Start Configuration page\n")
        header_file.write(" */\n")
        header_file.write("\n")
        header_file.write("#ifndef __NO_CSTART_DEFAULT_CONFIG\n")
        header_file.write("\n")
        header_file.write("/* C Startup settings */\n")
        header_file.write(
            "#define __BIV_TC1_INIT          {}       /* Initialize base address of interrupt vector table */\n".format(
                origin_data_tc1['__BIV_TC1_INIT']))
        header_file.write(
            "#define __BIV_SINGLE_TC1_INIT   {}       /* Initialize single entry interrupt vector table */\n".format(
                origin_data_tc1['__BIV_SINGLE_TC1_INIT']))
        header_file.write(
            "#define __BIV_8BYTE_TC1_INIT    {}       /* Initialize 8 byte spacing interrupt vector table */\n".format(
                origin_data_tc1['__BIV_8BYTE_TC1_INIT']))
        header_file.write(
            "#define __BTV_TC1_INIT          {}       /* Initialize base address of trap vector table */\n".format(
                origin_data_tc1['__BTV_TC1_INIT']))
        header_file.write("#define __CSA_TC1_INIT          {}       /* Initialize CSA lists */\n".format(
            origin_data_tc1['__CSA_TC1_INIT']))
        header_file.write("#define __C_TC1_INIT            {}       /* Initialize and clear C variables */\n".format(
            origin_data_tc1['__C_TC1_INIT']))
        header_file.write("#define __USP_TC1_INIT          {}       /* Initialize user stack pointer */\n".format(
            origin_data_tc1['__USP_TC1_INIT']))
        header_file.write("#define __ISP_TC1_INIT          {}       /* Initialize interrupt stack pointer */\n".format(
            origin_data_tc1['__ISP_TC1_INIT']))
        header_file.write(
            "#define __A0A1_TC1_INIT         {}       /* Initialize a0 and a1 for _a0/_a1 addressing */\n".format(
                origin_data_tc1['__A0A1_TC1_INIT']))
        header_file.write(
            "#define __A8A9_TC1_INIT         {}       /* Initialize a8 and a9 for _a8/_a9 addressing (OS support) */\n".format(
                origin_data_tc1['__A8A9_TC1_INIT']))

        header_file.write(
            "#define __USER_STACK_TC1                {}       /* Use the user stack (clear PSW.IS) */\n".format(
                origin_data_tc1['__USER_STACK_TC1']))
        header_file.write(
            "#define __USE_ARGC_ARGV_TC1     {}       /* Enable passing argc/argv to main() */\n".format(
                origin_data_tc1['__USE_ARGC_ARGV_TC1']))
        header_file.write(
            "#define __ARGCV_BUFSIZE_TC1     {}     /* Buffer size for argv */\n".format(
                origin_data_tc1['__ARGCV_BUFSIZE_TC1']))
        header_file.write("\n")
        header_file.write("\n")
        header_file.write("/* Trap Vectors */\n")
        header_file.write("#define __RESOLVE_TRAP_0_TC1    {}       /* Class 0: MMU */\n".format(
            origin_data_tc1['__RESOLVE_TRAP_0_TC1']))
        header_file.write("#define __RESOLVE_TRAP_1_TC1    {}       /* Class 1: Internal protection */\n".format(
            origin_data_tc1['__RESOLVE_TRAP_1_TC1']))
        header_file.write("#define __RESOLVE_TRAP_2_TC1    {}       /* Class 2: Instruction error */\n".format(
            origin_data_tc1['__RESOLVE_TRAP_2_TC1']))
        header_file.write("#define __RESOLVE_TRAP_3_TC1    {}       /* Class 3: Context management */\n".format(
            origin_data_tc1['__RESOLVE_TRAP_3_TC1']))
        header_file.write(
            "#define __RESOLVE_TRAP_4_TC1    {}       /* Class 4: System bus and peripheral errors */\n".format(
                origin_data_tc1['__RESOLVE_TRAP_4_TC1']))
        header_file.write("#define __RESOLVE_TRAP_5_TC1    {}       /* Class 5: Assertion */\n".format(
            origin_data_tc1['__RESOLVE_TRAP_5_TC1']))
        header_file.write("#define __RESOLVE_TRAP_6_TC1    {}       /* Class 6: System call */\n".format(
            origin_data_tc1['__RESOLVE_TRAP_6_TC1']))
        header_file.write("#define __RESOLVE_TRAP_7_TC1    {}       /* Class 7: Non-maskable interrupt */\n".format(
            origin_data_tc1['__RESOLVE_TRAP_7_TC1']))
        header_file.write("\n")
        header_file.write("#endif /* __NO_CSTART_DEFAULT_CONFIG */\n")
        header_file.write("\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * Control of initialization registers\n")
        header_file.write(" *\n")
        header_file.write(" * The *_VALUE macros define the value of the register\n")
        header_file.write(" * The *_INIT macros must be defined to 0 or 1, specifying whether\n")
        header_file.write(" * or not it will be intialized by the cstart.c code.\n")
        header_file.write(" *\n")
        header_file.write(" * Most registers are not set to be initialized, which means that\n")
        header_file.write(" * the CPU's defaults are used. The bus configuration registers will be\n")
        header_file.write(" * set by running the 'Target Board Configuration' wizard.\n")
        header_file.write(" * The Eclipse environment will automatically apply the CPU default\n")
        header_file.write(" * values to the registers. These defaults are defined in the SFR files\n")
        header_file.write(" * from the include/sfr directory of the product.\n")
        header_file.write(" *\n")
        header_file.write(" */\n")
        header_file.write("#ifndef __NO_CSTART_REGISTER_CONFIG\n")
        header_file.write("\n")
        header_file.write("#define __PCON0_INIT            {}\n".format(origin_data_tc1['__PCON0_INIT']))
        header_file.write("#define __PCON0_VALUE           {}\n".format(origin_data_tc1['__PCON0_VALUE']))
        header_file.write("#define __DCON0_INIT            {}\n".format(origin_data_tc1['__DCON0_INIT']))
        header_file.write("#define __DCON0_VALUE           {}\n".format(origin_data_tc1['__DCON0_VALUE']))
        header_file.write("\n")
        header_file.write("#endif /*__NO_CSTART_REGISTER_CONFIG */\n")
        header_file.write("\n")
        header_file.write("#endif /* CSTART_TC1_H */\n")

    # tc2 header create
    save_file_name = save_file_path + "\\prost_cstart_tc2.h"
    with open(save_file_name, 'wt', encoding='utf-8', newline='') as header_file:
        header_file.write("/**************************************************************************\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  FILE        :  cstart_tc2.h                                           *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  DESCRIPTION :                                                         *\n")
        header_file.write("**      Header file to control the system startup code's general settings *\n")
        header_file.write("**      and register initializations. The cstart__tc2.c file must be part *\n")
        header_file.write("**      of your project to make use of this cstart__tc2.h.                *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**      In the Eclipse environment this file can be modified using the    *\n")
        header_file.write("**      C startup code editor, which provides a GUI to modify the         *\n")
        header_file.write("**      Configuration settings and register initialization.               *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  Copyright 1996-2013 Altium BV                                         *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**************************************************************************/\n")
        header_file.write("\n")
        header_file.write("#ifndef PROST_CSTART_TC2_H\n")
        header_file.write("#define PROST_CSTART_TC2_H\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * These items are shown in Eclipse on the C Start Configuration page\n")
        header_file.write(" */\n")
        header_file.write("\n")
        header_file.write("#ifndef __NO_CSTART_DEFAULT_CONFIG\n")
        header_file.write("\n")
        header_file.write("/* C Startup settings */\n")
        header_file.write(
            "#define __BIV_TC2_INIT          {}       /* Initialize base address of interrupt vector table */\n".format(
                origin_data_tc2['__BIV_TC2_INIT']))
        header_file.write(
            "#define __BIV_SINGLE_TC2_INIT   {}       /* Initialize single entry interrupt vector table */\n".format(
                origin_data_tc2['__BIV_SINGLE_TC2_INIT']))
        header_file.write(
            "#define __BIV_8BYTE_TC2_INIT    {}       /* Initialize 8 byte spacing interrupt vector table */\n".format(
                origin_data_tc2['__BIV_8BYTE_TC2_INIT']))
        header_file.write(
            "#define __BTV_TC2_INIT          {}       /* Initialize base address of trap vector table */\n".format(
                origin_data_tc2['__BTV_TC2_INIT']))
        header_file.write("#define __CSA_TC2_INIT          {}       /* Initialize CSA lists */\n".format(
            origin_data_tc2['__CSA_TC2_INIT']))
        header_file.write("#define __C_TC2_INIT            {}       /* Initialize and clear C variables */\n".format(
            origin_data_tc2['__C_TC2_INIT']))
        header_file.write("#define __USP_TC2_INIT          {}       /* Initialize user stack pointer */\n".format(
            origin_data_tc2['__USP_TC2_INIT']))
        header_file.write("#define __ISP_TC2_INIT          {}       /* Initialize interrupt stack pointer */\n".format(
            origin_data_tc2['__ISP_TC2_INIT']))
        header_file.write(
            "#define __A0A1_TC2_INIT         {}       /* Initialize a0 and a1 for _a0/_a1 addressing */\n".format(
                origin_data_tc2['__A0A1_TC2_INIT']))
        header_file.write(
            "#define __A8A9_TC2_INIT         {}       /* Initialize a8 and a9 for _a8/_a9 addressing (OS support) */\n".format(
                origin_data_tc2['__A8A9_TC2_INIT']))

        header_file.write(
            "#define __USER_STACK_TC2                {}       /* Use the user stack (clear PSW.IS) */\n".format(
                origin_data_tc2['__USER_STACK_TC2']))
        header_file.write(
            "#define __USE_ARGC_ARGV_TC2     {}       /* Enable passing argc/argv to main() */\n".format(
                origin_data_tc2['__USE_ARGC_ARGV_TC2']))
        header_file.write(
            "#define __ARGCV_BUFSIZE_TC2     {}     /* Buffer size for argv */\n".format(
                origin_data_tc2['__ARGCV_BUFSIZE_TC2']))

        header_file.write("\n")
        header_file.write("/* Trap Vectors */\n")
        header_file.write("#define __RESOLVE_TRAP_0_TC2    {}       /* Class 0: MMU */\n".format(
            origin_data_tc2['__RESOLVE_TRAP_0_TC2']))
        header_file.write("#define __RESOLVE_TRAP_1_TC2    {}       /* Class 1: Internal protection */\n".format(
            origin_data_tc2['__RESOLVE_TRAP_1_TC2']))
        header_file.write("#define __RESOLVE_TRAP_2_TC2    {}       /* Class 2: Instruction error */\n".format(
            origin_data_tc2['__RESOLVE_TRAP_2_TC2']))
        header_file.write("#define __RESOLVE_TRAP_3_TC2    {}       /* Class 3: Context management */\n".format(
            origin_data_tc2['__RESOLVE_TRAP_3_TC2']))
        header_file.write(
            "#define __RESOLVE_TRAP_4_TC2    {}       /* Class 4: System bus and peripheral errors */\n".format(
                origin_data_tc2['__RESOLVE_TRAP_4_TC2']))
        header_file.write("#define __RESOLVE_TRAP_5_TC2    {}       /* Class 5: Assertion */\n".format(
            origin_data_tc2['__RESOLVE_TRAP_5_TC2']))
        header_file.write("#define __RESOLVE_TRAP_6_TC2    {}       /* Class 6: System call */\n".format(
            origin_data_tc2['__RESOLVE_TRAP_6_TC2']))
        header_file.write("#define __RESOLVE_TRAP_7_TC2    {}       /* Class 7: Non-maskable interrupt */\n".format(
            origin_data_tc2['__RESOLVE_TRAP_7_TC2']))
        header_file.write("\n")
        header_file.write("#endif /* __NO_CSTART_DEFAULT_CONFIG */\n")
        header_file.write("\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * Control of initialization registers\n")
        header_file.write(" *\n")
        header_file.write(" * The *_VALUE macros define the value of the register\n")
        header_file.write(" * The *_INIT macros must be defined to 0 or 1, specifying whether\n")
        header_file.write(" * or not it will be intialized by the cstart.c code.\n")
        header_file.write(" *\n")
        header_file.write(" * Most registers are not set to be initialized, which means that\n")
        header_file.write(" * the CPU's defaults are used. The bus configuration registers will be\n")
        header_file.write(" * set by running the 'Target Board Configuration' wizard.\n")
        header_file.write(" * The Eclipse environment will automatically apply the CPU default\n")
        header_file.write(" * values to the registers. These defaults are defined in the SFR files\n")
        header_file.write(" * from the include/sfr directory of the product.\n")
        header_file.write(" *\n")
        header_file.write(" */\n")
        header_file.write("#ifndef __NO_CSTART_REGISTER_CONFIG\n")
        header_file.write("\n")
        header_file.write("#define __PCON0_INIT            {}\n".format(origin_data_tc2['__PCON0_INIT']))
        header_file.write("#define __PCON0_VALUE           {}\n".format(origin_data_tc2['__PCON0_VALUE']))
        header_file.write("#define __DCON0_INIT            {}\n".format(origin_data_tc2['__DCON0_INIT']))
        header_file.write("#define __DCON0_VALUE           {}\n".format(origin_data_tc2['__DCON0_VALUE']))
        header_file.write("\n")
        header_file.write("#endif /*__NO_CSTART_REGISTER_CONFIG */\n")
        header_file.write("\n")
        header_file.write("#endif /* CSTART_TC2_H */\n")
        header_file.write("\n")

def tasking_v43_tc27x_h_modify_save(save_file_path):
    # tc0 header create
    save_file_name = save_file_path + "\\prost_cstart.h"
    with open(save_file_name, 'wt', encoding='utf-8', newline='') as header_file:
        header_file.write("/**************************************************************************\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  FILE        :  cstart.h                                               *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  DESCRIPTION :                                                         *\n")
        header_file.write("**      Header file to control the system startup code's general settings *\n")
        header_file.write("**      and register initializations. The cstart.c file must be part of   *\n")
        header_file.write("**      your project to make use of this cstart.h.                        *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**      In the Eclipse environment this file can be modified using the    *\n")
        header_file.write("**      C startup code editor, which provides a GUI to modify the         *\n")
        header_file.write("**      Configuration settings and register initialization.               *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  Copyright 1996-2013 Altium BV                                         *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**************************************************************************/\n")
        header_file.write("\n")
        header_file.write("#ifndef PROST_CSTART_H\n")
        header_file.write("#define PROST_CSTART_H\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * These items are shown on in Eclipse on the C Start Configuration page\n")
        header_file.write(" */\n")
        header_file.write("\n")
        header_file.write("#ifndef __NO_CSTART_DEFAULT_CONFIG\n")
        header_file.write("\n")
        header_file.write("/* C Startup settings */\n")
        header_file.write(
            "#define __BIV_INIT              {}       /* Initialize base address of interrupt vector table */\n".format(
                origin_data_tc['__BIV_INIT']))
        header_file.write(
            "#define __BIV_SINGLE_INIT       {}       /* Initialize single entry interrupt vector table */\n".format(
                origin_data_tc['__BIV_SINGLE_INIT']))
        header_file.write(
            "#define __BIV_8BYTE_INIT        {}       /* Initialize 8 byte spacing interrupt vector table */\n".format(
                origin_data_tc['__BIV_8BYTE_INIT']))
        header_file.write(
            "#define __BTV_INIT              {}       /* Initialize base address of trap vector table */\n".format(
                origin_data_tc['__BTV_INIT']))
        header_file.write(
            "#define __CSA_INIT              {}       /* Initialize CSA lists */\n".format(origin_data_tc['__CSA_INIT']))
        header_file.write("#define __C_INIT                {}       /* Initialize and clear C variables */\n".format(
            origin_data_tc['__C_INIT']))
        header_file.write("#define __USP_INIT              {}       /* Initialize user stack pointer */\n".format(
            origin_data_tc['__USP_INIT']))
        header_file.write("#define __ISP_INIT              {}       /* Initialize interrupt stack pointer */\n".format(
            origin_data_tc['__ISP_INIT']))
        header_file.write(
            "#define __A0A1_INIT             {}       /* Initialize a0 and a1 for _a0/_a1 addressing */\n".format(
                origin_data_tc['__A0A1_INIT']))
        header_file.write(
            "#define __A8A9_INIT             {}       /* Initialize a8 and a9 for _a8/_a9 addressing (OS support) */\n".format(
                origin_data_tc['__A8A9_INIT']))
        header_file.write("\n")
        header_file.write("#define __USER_STACK            {}       /* Use the user stack (clear PSW.IS) */\n".format(
            origin_data_tc['__USER_STACK']))
        header_file.write("#define __WATCHDOG_DISABLE      {}       /* Watchdog disable */\n".format(
            origin_data_tc['__WATCHDOG_DISABLE']))
        header_file.write("#define __SAFETY_WATCHDOG_DISABLE {}     /* Safety watchdog disable */\n".format(
            origin_data_tc['__SAFETY_WATCHDOG_DISABLE']))
        header_file.write("#define __USE_ARGC_ARGV         {}       /* Enable passing argc/argv to main() */\n".format(
            origin_data_tc['__USE_ARGC_ARGV']))
        header_file.write("#define __ARGCV_BUFSIZE       {}       /* Buffer size for argv */\n".format(
            origin_data_tc['__ARGCV_BUFSIZE']))
        header_file.write("#define __CLOCKS_PER_SEC_INIT   {}       /* Initialize clocks per sec */\n".format(
            origin_data_tc['__CLOCKS_PER_SEC_INIT']))
        header_file.write(
            "#define __fOSC           {}       /* Oscillator frequency Hz */\n".format(origin_data_tc['__fOSC']))
        header_file.write(
            "#define __PLL_K2_RAMPUP         {}       /* PLL K2 rampup */\n".format(origin_data_tc['__PLL_K2_RAMPUP']))
        header_file.write(
            "#define __STADD_INIT_TC1        {}       /* Initialize start address TC1 */\n".format(origin_data_tc['__STADD_INIT_TC1']))
        header_file.write(
            "#define __STADD_INIT_TC2        {}       /* Initialize start address TC2 */\n".format(origin_data_tc['__STADD_INIT_TC2']))
        header_file.write(
            "#define __HALT_INIT_TC1        {}       /* Initialize HALT state of TC1 */\n".format(origin_data_tc['__HALT_INIT_TC1']))
        header_file.write(
            "#define __HALT_INIT_TC2        {}       /* Initialize HALT state of TC2 */\n".format(origin_data_tc['__HALT_INIT_TC2']))
        header_file.write(
            "#define __HALT_VALUE_TC1        {}       /* Set HALT value of TC1 */\n".format(origin_data_tc['__HALT_VALUE_TC1']))
        header_file.write("                                        /* 0 R:running W:unchanged\n")
        header_file.write("                                           1 R:halted W:unchanged\n")
        header_file.write("                                           2 R:n.a. W:reset halt\n")
        header_file.write("                                           3 R:n.a. W:set when debug enable\n")
        header_file.write("                                        */\n")
        header_file.write(
            "#define __HALT_VALUE_TC2        {}       /* Set HALT value of TC1 */\n".format(
                origin_data_tc['__HALT_VALUE_TC2']))
        header_file.write("                                        /* 0 R:running W:unchanged\n")
        header_file.write("                                           1 R:halted W:unchanged\n")
        header_file.write("                                           2 R:n.a. W:reset halt\n")
        header_file.write("                                           3 R:n.a. W:set when debug enable\n")
        header_file.write("                                        */\n")
        header_file.write("\n")
        header_file.write("/* Trap Vectors */\n")
        header_file.write(
            "#define __RESOLVE_TRAP_0        {}       /* Class 0: MMU */\n".format(origin_data_tc['__RESOLVE_TRAP_0']))
        header_file.write("#define __RESOLVE_TRAP_1        {}       /* Class 1: Internal protection */\n".format(
            origin_data_tc['__RESOLVE_TRAP_1']))
        header_file.write("#define __RESOLVE_TRAP_2        {}       /* Class 2: Instruction error */\n".format(
            origin_data_tc['__RESOLVE_TRAP_2']))
        header_file.write("#define __RESOLVE_TRAP_3        {}       /* Class 3: Context management */\n".format(
            origin_data_tc['__RESOLVE_TRAP_3']))
        header_file.write(
            "#define __RESOLVE_TRAP_4        {}       /* Class 4: System bus and peripheral errors */\n".format(
                origin_data_tc['__RESOLVE_TRAP_4']))
        header_file.write("#define __RESOLVE_TRAP_5        {}       /* Class 5: Assertion */\n".format(
            origin_data_tc['__RESOLVE_TRAP_5']))
        header_file.write("#define __RESOLVE_TRAP_6        {}       /* Class 6: System call */\n".format(
            origin_data_tc['__RESOLVE_TRAP_6']))
        header_file.write("#define __RESOLVE_TRAP_7        {}       /* Class 7: Non-maskable interrupt */\n".format(
            origin_data_tc['__RESOLVE_TRAP_7']))
        header_file.write("\n")
        header_file.write("\n")
        header_file.write("#endif /* __NO_CSTART_DEFAULT_CONFIG */\n")
        header_file.write("\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * Control of initialization registers\n")
        header_file.write(" *\n")
        header_file.write(" * The *_VALUE macros define the value of the register\n")
        header_file.write(" * The *_INIT macros must be defined to 0 or 1, specifying whether\n")
        header_file.write(" * or not it will be intialized by the cstart.c code.\n")
        header_file.write(" *\n")
        header_file.write(" * Most registers are not set to be initialized, which means that\n")
        header_file.write(" * the CPU's defaults are used. The bus configuration registers will be\n")
        header_file.write(" * set by running the 'Target Board Configuration' wizard.\n")
        header_file.write(" * The Eclipse environment will automatically apply the CPU default\n")
        header_file.write(" * values to the registers. These defaults are defined in the SFR files\n")
        header_file.write(" * from the include/sfr directory of the product.\n")
        header_file.write(" *\n")
        header_file.write(" */\n")
        header_file.write("\n")
        header_file.write("#define __EBU_BOOTCFG_INIT      {}\n".format(origin_data_tc['__EBU_BOOTCFG_INIT']))
        header_file.write("#define __EBU_BOOTCFG_VALUE     {}\n".format(origin_data_tc['__EBU_BOOTCFG_VALUE']))
        header_file.write("\n")
        header_file.write("#ifndef __NO_CSTART_REGISTER_CONFIG\n")
        header_file.write("/* Non-bus configuration: */\n")
        header_file.write("#define __PMI_CON0_INIT         {}\n".format(origin_data_tc['__PMI_CON0_INIT']))
        header_file.write("#define __PMI_CON0_VALUE        {}\n".format(origin_data_tc['__PMI_CON0_VALUE']))
        header_file.write("#define __PMI_CON1_INIT         {}\n".format(origin_data_tc['__PMI_CON1_INIT']))
        header_file.write("#define __PMI_CON1_VALUE        {}\n".format(origin_data_tc['__PMI_CON1_VALUE']))
        header_file.write("#define __PMI_CON2_INIT         {}\n".format(origin_data_tc['__PMI_CON2_INIT']))
        header_file.write("#define __PMI_CON2_VALUE        {}\n".format(origin_data_tc['__PMI_CON2_VALUE']))
        header_file.write("#define __PMU_EIFCON_INIT       {}\n".format(origin_data_tc['__PMU_EIFCON_INIT']))
        header_file.write("#define __PMU_EIFCON_VALUE      {}\n".format(origin_data_tc['__PMU_EIFCON_VALUE']))
        header_file.write("#define __DMI_CON_INIT          {}\n".format(origin_data_tc['__DMI_CON_INIT']))
        header_file.write("#define __DMI_CON_VALUE         {}\n".format(origin_data_tc['__DMI_CON_VALUE']))
        header_file.write("#define __PLL_CLC_INIT          {}\n".format(origin_data_tc['__PLL_CLC_INIT']))
        header_file.write("#define __PLL_CLC_VALUE         {}\n".format(origin_data_tc['__PLL_CLC_VALUE']))
        header_file.write("#define __SCU_PLLCON0_INIT      {}\n".format(origin_data_tc['__SCU_PLLCON0_INIT']))
        header_file.write("#define __SCU_PLLCON0_VALUE     {}\n".format(origin_data_tc['__SCU_PLLCON0_VALUE']))
        header_file.write("#define __SCU_PLLCON1_INIT      {}\n".format(origin_data_tc['__SCU_PLLCON1_INIT']))
        header_file.write("#define __SCU_PLLCON1_VALUE     {}\n".format(origin_data_tc['__SCU_PLLCON1_VALUE']))
        header_file.write("#define __SCU_OSCCON_INIT       {}\n".format(origin_data_tc['__SCU_OSCCON_INIT']))
        header_file.write("#define __SCU_OSCCON_VALUE      {}\n".format(origin_data_tc['__SCU_OSCCON_VALUE']))
        header_file.write("#define __SCU_CCUCON0_INIT      {}\n".format(origin_data_tc['__SCU_CCUCON0_INIT']))
        header_file.write("#define __SCU_CCUCON0_VALUE     {}\n".format(origin_data_tc['__SCU_CCUCON0_VALUE']))
        header_file.write("#define __SCU_CCUCON1_INIT      {}\n".format(origin_data_tc['__SCU_CCUCON1_INIT']))
        header_file.write("#define __SCU_CCUCON1_VALUE     {}\n".format(origin_data_tc['__SCU_CCUCON1_VALUE']))
        header_file.write("#define __SCU_CCUCON2_INIT      {}\n".format(origin_data_tc['__SCU_CCUCON2_INIT']))
        header_file.write("#define __SCU_CCUCON2_VALUE     {}\n".format(origin_data_tc['__SCU_CCUCON2_VALUE']))
        header_file.write("#define __STM_CLC_INIT          {}\n".format(origin_data_tc['__STM_CLC_INIT']))
        header_file.write("#define __STM_CLC_VALUE         {}\n".format(origin_data_tc['__STM_CLC_VALUE']))
        header_file.write("#define __GTM_CLC_INIT          {}\n".format(origin_data_tc['__GTM_CLC_INIT']))
        header_file.write("#define __GTM_CLC_VALUE         {}\n".format(origin_data_tc['__GTM_CLC_VALUE']))
        header_file.write("#define __FLASH0_FCON_INIT      {}\n".format(origin_data_tc['__FLASH0_FCON_INIT']))
        header_file.write("#define __FLASH0_FCON_VALUE     {}\n".format(origin_data_tc['__FLASH0_FCON_VALUE']))
        header_file.write("#define __FLASH1_FCON_INIT      {}\n".format(origin_data_tc['__FLASH1_FCON_INIT']))
        header_file.write("#define __FLASH1_FCON_VALUE     {}\n".format(origin_data_tc['__FLASH1_FCON_VALUE']))
        header_file.write("/* Bus configuration: (set by 'Target Board Configuration' wizard) */\n")
        header_file.write("#define __EBU_ADDRSEL0_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL0_INIT']))
        header_file.write("#define __EBU_ADDRSEL0_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL0_VALUE']))
        header_file.write("#define __EBU_ADDRSEL1_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL1_INIT']))
        header_file.write("#define __EBU_ADDRSEL1_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL1_VALUE']))
        header_file.write("#define __EBU_ADDRSEL2_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL2_INIT']))
        header_file.write("#define __EBU_ADDRSEL2_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL2_VALUE']))
        header_file.write("#define __EBU_ADDRSEL3_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL3_INIT']))
        header_file.write("#define __EBU_ADDRSEL3_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL3_VALUE']))
        header_file.write("#define __EBU_ADDRSEL4_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL4_INIT']))
        header_file.write("#define __EBU_ADDRSEL4_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL4_VALUE']))
        header_file.write("#define __EBU_ADDRSEL5_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL5_INIT']))
        header_file.write("#define __EBU_ADDRSEL5_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL5_VALUE']))
        header_file.write("#define __EBU_ADDRSEL6_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL6_INIT']))
        header_file.write("#define __EBU_ADDRSEL6_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL6_VALUE']))
        header_file.write("#define __EBU_BFCON_INIT        {}\n".format(origin_data_tc['__EBU_BFCON_INIT']))
        header_file.write("#define __EBU_BFCON_VALUE       {}\n".format(origin_data_tc['__EBU_BFCON_VALUE']))
        header_file.write("#define __EBU_BUSAP0_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP0_INIT']))
        header_file.write("#define __EBU_BUSAP0_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP0_VALUE']))
        header_file.write("#define __EBU_BUSAP1_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP1_INIT']))
        header_file.write("#define __EBU_BUSAP1_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP1_VALUE']))
        header_file.write("#define __EBU_BUSAP2_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP2_INIT']))
        header_file.write("#define __EBU_BUSAP2_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP2_VALUE']))
        header_file.write("#define __EBU_BUSAP3_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP3_INIT']))
        header_file.write("#define __EBU_BUSAP3_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP3_VALUE']))
        header_file.write("#define __EBU_BUSAP4_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP4_INIT']))
        header_file.write("#define __EBU_BUSAP4_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP4_VALUE']))
        header_file.write("#define __EBU_BUSAP5_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP5_INIT']))
        header_file.write("#define __EBU_BUSAP5_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP5_VALUE']))
        header_file.write("#define __EBU_BUSAP6_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP6_INIT']))
        header_file.write("#define __EBU_BUSAP6_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP6_VALUE']))
        header_file.write("#define __EBU_BUSCON0_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON0_INIT']))
        header_file.write("#define __EBU_BUSCON0_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON0_VALUE']))
        header_file.write("#define __EBU_BUSCON1_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON1_INIT']))
        header_file.write("#define __EBU_BUSCON1_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON1_VALUE']))
        header_file.write("#define __EBU_BUSCON2_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON2_INIT']))
        header_file.write("#define __EBU_BUSCON2_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON2_VALUE']))
        header_file.write("#define __EBU_BUSCON3_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON3_INIT']))
        header_file.write("#define __EBU_BUSCON3_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON3_VALUE']))
        header_file.write("#define __EBU_BUSCON4_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON4_INIT']))
        header_file.write("#define __EBU_BUSCON4_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON4_VALUE']))
        header_file.write("#define __EBU_BUSCON5_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON5_INIT']))
        header_file.write("#define __EBU_BUSCON5_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON5_VALUE']))
        header_file.write("#define __EBU_BUSCON6_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON6_INIT']))
        header_file.write("#define __EBU_BUSCON6_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON6_VALUE']))
        header_file.write("#define __EBU_CLC_INIT          {}\n".format(origin_data_tc['__EBU_CLC_INIT']))
        header_file.write("#define __EBU_CLC_VALUE         {}\n".format(origin_data_tc['__EBU_CLC_VALUE']))
        header_file.write("#define __EBU_CON_INIT          {}\n".format(origin_data_tc['__EBU_CON_INIT']))
        header_file.write("#define __EBU_CON_VALUE         {}\n".format(origin_data_tc['__EBU_CON_VALUE']))
        header_file.write("#define __EBU_EMUAS_INIT        {}\n".format(origin_data_tc['__EBU_EMUAS_INIT']))
        header_file.write("#define __EBU_EMUAS_VALUE       {}\n".format(origin_data_tc['__EBU_EMUAS_VALUE']))
        header_file.write("#define __EBU_EMUBAP_INIT       {}\n".format(origin_data_tc['__EBU_EMUBAP_INIT']))
        header_file.write("#define __EBU_EMUBAP_VALUE      {}\n".format(origin_data_tc['__EBU_EMUBAP_VALUE']))
        header_file.write("#define __EBU_EMUBC_INIT        {}\n".format(origin_data_tc['__EBU_EMUBC_INIT']))
        header_file.write("#define __EBU_EMUBC_VALUE       {}\n".format(origin_data_tc['__EBU_EMUBC_VALUE']))
        header_file.write("#define __EBU_EMUCON_INIT       {}\n".format(origin_data_tc['__EBU_EMUCON_INIT']))
        header_file.write("#define __EBU_EMUCON_VALUE      {}\n".format(origin_data_tc['__EBU_EMUCON_VALUE']))
        header_file.write("#define __EBU_EMUOVL_INIT       {}\n".format(origin_data_tc['__EBU_EMUOVL_INIT']))
        header_file.write("#define __EBU_EMUOVL_VALUE      {}\n".format(origin_data_tc['__EBU_EMUOVL_VALUE']))
        header_file.write("#define __EBU_SDRMCON0_INIT     {}\n".format(origin_data_tc['__EBU_SDRMCON0_INIT']))
        header_file.write("#define __EBU_SDRMCON0_VALUE    {}\n".format(origin_data_tc['__EBU_SDRMCON0_VALUE']))
        header_file.write("#define __EBU_SDRMCON1_INIT     {}\n".format(origin_data_tc['__EBU_SDRMCON1_INIT']))
        header_file.write("#define __EBU_SDRMCON1_VALUE    {}\n".format(origin_data_tc['__EBU_SDRMCON1_VALUE']))
        header_file.write("#define __EBU_SDRMOD0_INIT      {}\n".format(origin_data_tc['__EBU_SDRMOD0_INIT']))
        header_file.write("#define __EBU_SDRMOD0_VALUE     {}\n".format(origin_data_tc['__EBU_SDRMOD0_VALUE']))
        header_file.write("#define __EBU_SDRMOD1_INIT      {}\n".format(origin_data_tc['__EBU_SDRMOD1_INIT']))
        header_file.write("#define __EBU_SDRMOD1_VALUE     {}\n".format(origin_data_tc['__EBU_SDRMOD1_VALUE']))
        header_file.write("#define __EBU_SDRMREF0_INIT     {}\n".format(origin_data_tc['__EBU_SDRMREF0_INIT']))
        header_file.write("#define __EBU_SDRMREF0_VALUE    {}\n".format(origin_data_tc['__EBU_SDRMREF0_VALUE']))
        header_file.write("#define __EBU_SDRMREF1_INIT     {}\n".format(origin_data_tc['__EBU_SDRMREF1_INIT']))
        header_file.write("#define __EBU_SDRMREF1_VALUE    {}\n".format(origin_data_tc['__EBU_SDRMREF1_VALUE']))
        header_file.write("#define __CBS_MCDBBS_INIT       {}\n".format(origin_data_tc['__CBS_MCDBBS_INIT']))
        header_file.write("#define __CBS_MCDBBS_VALUE      {}\n".format(origin_data_tc['__CBS_MCDBBS_VALUE']))
        header_file.write("#define __SBCU_CON_INIT         {}\n".format(origin_data_tc['__SBCU_CON_INIT']))
        header_file.write("#define __SBCU_CON_VALUE        {}\n".format(origin_data_tc['__SBCU_CON_VALUE']))
        header_file.write("#define __EBU_BUSRAP1_INIT      {}\n".format(origin_data_tc['__EBU_BUSRAP1_INIT']))
        header_file.write("#define __EBU_BUSRAP1_VALUE     {}\n".format(origin_data_tc['__EBU_BUSRAP1_VALUE']))
        header_file.write("#define __EBU_BUSRAP0_INIT      {}\n".format(origin_data_tc['__EBU_BUSRAP0_INIT']))
        header_file.write("#define __EBU_BUSRAP0_VALUE     {}\n".format(origin_data_tc['__EBU_BUSRAP0_VALUE']))
        header_file.write("#define __EBU_BUSRAP2_INIT      {}\n".format(origin_data_tc['__EBU_BUSRAP2_INIT']))
        header_file.write("#define __EBU_BUSRAP2_VALUE     {}\n".format(origin_data_tc['__EBU_BUSRAP2_VALUE']))
        header_file.write("#define __EBU_BUSRAP3_INIT      {}\n".format(origin_data_tc['__EBU_BUSRAP3_INIT']))
        header_file.write("#define __EBU_BUSRAP3_VALUE     {}\n".format(origin_data_tc['__EBU_BUSRAP3_VALUE']))
        header_file.write("#define __EBU_BUSRCON0_INIT     {}\n".format(origin_data_tc['__EBU_BUSRCON0_INIT']))
        header_file.write("#define __EBU_BUSRCON0_VALUE    {}\n".format(origin_data_tc['__EBU_BUSRCON0_VALUE']))
        header_file.write("#define __EBU_BUSRCON1_INIT     {}\n".format(origin_data_tc['__EBU_BUSRCON1_INIT']))
        header_file.write("#define __EBU_BUSRCON1_VALUE    {}\n".format(origin_data_tc['__EBU_BUSRCON1_VALUE']))
        header_file.write("#define __EBU_BUSRCON2_INIT     {}\n".format(origin_data_tc['__EBU_BUSRCON2_INIT']))
        header_file.write("#define __EBU_BUSRCON2_VALUE    {}\n".format(origin_data_tc['__EBU_BUSRCON2_VALUE']))
        header_file.write("#define __EBU_BUSRCON3_INIT     {}\n".format(origin_data_tc['__EBU_BUSRCON3_INIT']))
        header_file.write("#define __EBU_BUSRCON3_VALUE    {}\n".format(origin_data_tc['__EBU_BUSRCON3_VALUE']))
        header_file.write("#define __EBU_BUSWAP0_INIT      {}\n".format(origin_data_tc['__EBU_BUSWAP0_INIT']))
        header_file.write("#define __EBU_BUSWAP0_VALUE     {}\n".format(origin_data_tc['__EBU_BUSWAP0_VALUE']))
        header_file.write("#define __EBU_BUSWAP1_INIT      {}\n".format(origin_data_tc['__EBU_BUSWAP1_INIT']))
        header_file.write("#define __EBU_BUSWAP1_VALUE     {}\n".format(origin_data_tc['__EBU_BUSWAP1_VALUE']))
        header_file.write("#define __EBU_BUSWAP2_INIT      {}\n".format(origin_data_tc['__EBU_BUSWAP2_INIT']))
        header_file.write("#define __EBU_BUSWAP2_VALUE     {}\n".format(origin_data_tc['__EBU_BUSWAP2_VALUE']))
        header_file.write("#define __EBU_BUSWAP3_INIT      {}\n".format(origin_data_tc['__EBU_BUSWAP3_INIT']))
        header_file.write("#define __EBU_BUSWAP3_VALUE     {}\n".format(origin_data_tc['__EBU_BUSWAP3_VALUE']))
        header_file.write("#define __EBU_BUSWCON0_INIT     {}\n".format(origin_data_tc['__EBU_BUSWCON0_INIT']))
        header_file.write("#define __EBU_BUSWCON0_VALUE    {}\n".format(origin_data_tc['__EBU_BUSWCON0_VALUE']))
        header_file.write("#define __EBU_BUSWCON1_INIT     {}\n".format(origin_data_tc['__EBU_BUSWCON1_INIT']))
        header_file.write("#define __EBU_BUSWCON1_VALUE    {}\n".format(origin_data_tc['__EBU_BUSWCON1_VALUE']))
        header_file.write("#define __EBU_BUSWCON2_INIT     {}\n".format(origin_data_tc['__EBU_BUSWCON2_INIT']))
        header_file.write("#define __EBU_BUSWCON2_VALUE    {}\n".format(origin_data_tc['__EBU_BUSWCON2_VALUE']))
        header_file.write("#define __EBU_BUSWCON3_INIT     {}\n".format(origin_data_tc['__EBU_BUSWCON3_INIT']))
        header_file.write("#define __EBU_BUSWCON3_VALUE    {}\n".format(origin_data_tc['__EBU_BUSWCON3_VALUE']))
        header_file.write("#define __EBU_EXTBOOT_INIT      {}\n".format(origin_data_tc['__EBU_EXTBOOT_INIT']))
        header_file.write("#define __EBU_EXTBOOT_VALUE     {}\n".format(origin_data_tc['__EBU_EXTBOOT_VALUE']))
        header_file.write("#define __EBU_MODCON_INIT       {}\n".format(origin_data_tc['__EBU_MODCON_INIT']))
        header_file.write("#define __EBU_MODCON_VALUE      {}\n".format(origin_data_tc['__EBU_MODCON_VALUE']))
        header_file.write("#define __EBU_DDRNCON_INIT      {}\n".format(origin_data_tc['__EBU_DDRNCON_INIT']))
        header_file.write("#define __EBU_DDRNCON_VALUE     {}\n".format(origin_data_tc['__EBU_DDRNCON_VALUE']))
        header_file.write("#define __EBU_DDRNMOD_INIT      {}\n".format(origin_data_tc['__EBU_DDRNMOD_INIT']))
        header_file.write("#define __EBU_DDRNMOD_VALUE     {}\n".format(origin_data_tc['__EBU_DDRNMOD_VALUE']))
        header_file.write("#define __EBU_DDRNMOD2_INIT     {}\n".format(origin_data_tc['__EBU_DDRNMOD2_INIT']))
        header_file.write("#define __EBU_DDRNMOD2_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNMOD2_VALUE']))
        header_file.write("#define __EBU_DDRNPRLD_INIT     {}\n".format(origin_data_tc['__EBU_DDRNPRLD_INIT']))
        header_file.write("#define __EBU_DDRNPRLD_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNPRLD_VALUE']))
        header_file.write("#define __EBU_DDRNTAG0_INIT     {}\n".format(origin_data_tc['__EBU_DDRNTAG0_INIT']))
        header_file.write("#define __EBU_DDRNTAG0_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNTAG0_VALUE']))
        header_file.write("#define __EBU_DDRNTAG1_INIT     {}\n".format(origin_data_tc['__EBU_DDRNTAG1_INIT']))
        header_file.write("#define __EBU_DDRNTAG1_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNTAG1_VALUE']))
        header_file.write("#define __EBU_DDRNTAG2_INIT     {}\n".format(origin_data_tc['__EBU_DDRNTAG2_INIT']))
        header_file.write("#define __EBU_DDRNTAG2_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNTAG2_VALUE']))
        header_file.write("#define __EBU_DDRNTAG3_INIT     {}\n".format(origin_data_tc['__EBU_DDRNTAG3_INIT']))
        header_file.write("#define __EBU_DDRNTAG3_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNTAG3_VALUE']))
        header_file.write("#define __EBU_DLLCON_INIT       {}\n".format(origin_data_tc['__EBU_DLLCON_INIT']))
        header_file.write("#define __EBU_DLLCON_VALUE      {}\n".format(origin_data_tc['__EBU_DLLCON_VALUE']))
        header_file.write("#define __EBU_SDRMCON_INIT      {}\n".format(origin_data_tc['__EBU_SDRMCON_INIT']))
        header_file.write("#define __EBU_SDRMCON_VALUE     {}\n".format(origin_data_tc['__EBU_SDRMCON_VALUE']))
        header_file.write("#define __EBU_SDRMOD_INIT       {}\n".format(origin_data_tc['__EBU_SDRMOD_INIT']))
        header_file.write("#define __EBU_SDRMOD_VALUE      {}\n".format(origin_data_tc['__EBU_SDRMOD_VALUE']))
        header_file.write("#define __EBU_SDRMREF_INIT      {}\n".format(origin_data_tc['__EBU_SDRMREF_INIT']))
        header_file.write("#define __EBU_SDRMREF_VALUE     {}\n".format(origin_data_tc['__EBU_SDRMREF_VALUE']))
        header_file.write("#define __EBU_SDRSTAT_INIT      {}\n".format(origin_data_tc['__EBU_SDRSTAT_INIT']))
        header_file.write("#define __EBU_SDRSTAT_VALUE     {}\n".format(origin_data_tc['__EBU_SDRSTAT_VALUE']))
        header_file.write("#define __PCON0_INIT            {}\n".format(origin_data_tc['__PCON0_INIT']))
        header_file.write("#define __PCON0_VALUE           {}\n".format(origin_data_tc['__PCON0_VALUE']))
        header_file.write("#define __DCON0_INIT            {}\n".format(origin_data_tc['__DCON0_INIT']))
        header_file.write("#define __DCON0_VALUE           {}\n".format(origin_data_tc['__DCON0_VALUE']))
        header_file.write("\n")
        header_file.write("#endif /*__NO_CSTART_REGISTER_CONFIG */\n")
        header_file.write("\n")
        header_file.write("#endif /* CSTART_H */\n")

    # tc1 header create
    save_file_name = save_file_path + "\\prost_cstart_tc1.h"
    with open(save_file_name, 'wt', encoding='utf-8', newline='') as header_file:
        header_file.write("/**************************************************************************\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  FILE        :  cstart_tc1.h                                           *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  DESCRIPTION :                                                         *\n")
        header_file.write("**      Header file to control the system startup code's general settings *\n")
        header_file.write("**      and register initializations. The cstart__tc1.c file must be part *\n")
        header_file.write("**      of your project to make use of this cstart__tc1.h.                *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**      In the Eclipse environment this file can be modified using the    *\n")
        header_file.write("**      C startup code editor, which provides a GUI to modify the         *\n")
        header_file.write("**      Configuration settings and register initialization.               *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  Copyright 1996-2013 Altium BV                                         *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**************************************************************************/\n")
        header_file.write("\n")
        header_file.write("#ifndef PROST_CSTART_TC1_H\n")
        header_file.write("#define PROST_CSTART_TC1_H\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * These items are shown in Eclipse on the C Start Configuration page\n")
        header_file.write(" */\n")
        header_file.write("\n")
        header_file.write("#ifndef __NO_CSTART_DEFAULT_CONFIG\n")
        header_file.write("\n")
        header_file.write("/* C Startup settings */\n")
        header_file.write(
            "#define __BIV_TC1_INIT          {}       /* Initialize base address of interrupt vector table */\n".format(
                origin_data_tc1['__BIV_TC1_INIT']))
        header_file.write(
            "#define __BIV_SINGLE_TC1_INIT   {}       /* Initialize single entry interrupt vector table */\n".format(
                origin_data_tc1['__BIV_SINGLE_TC1_INIT']))
        header_file.write(
            "#define __BIV_8BYTE_TC1_INIT    {}       /* Initialize 8 byte spacing interrupt vector table */\n".format(
                origin_data_tc1['__BIV_8BYTE_TC1_INIT']))
        header_file.write(
            "#define __BTV_TC1_INIT          {}       /* Initialize base address of trap vector table */\n".format(
                origin_data_tc1['__BTV_TC1_INIT']))
        header_file.write("#define __CSA_TC1_INIT          {}       /* Initialize CSA lists */\n".format(
            origin_data_tc1['__CSA_TC1_INIT']))
        header_file.write("#define __C_TC1_INIT            {}       /* Initialize and clear C variables */\n".format(
            origin_data_tc1['__C_TC1_INIT']))
        header_file.write("#define __USP_TC1_INIT          {}       /* Initialize user stack pointer */\n".format(
            origin_data_tc1['__USP_TC1_INIT']))
        header_file.write("#define __ISP_TC1_INIT          {}       /* Initialize interrupt stack pointer */\n".format(
            origin_data_tc1['__ISP_TC1_INIT']))
        header_file.write(
            "#define __A0A1_TC1_INIT         {}       /* Initialize a0 and a1 for _a0/_a1 addressing */\n".format(
                origin_data_tc1['__A0A1_TC1_INIT']))
        header_file.write(
            "#define __A8A9_TC1_INIT         {}       /* Initialize a8 and a9 for _a8/_a9 addressing (OS support) */\n".format(
                origin_data_tc1['__A8A9_TC1_INIT']))

        header_file.write(
            "#define __USER_STACK_TC1                {}       /* Use the user stack (clear PSW.IS) */\n".format(
                origin_data_tc1['__USER_STACK_TC1']))
        header_file.write(
            "#define __USE_ARGC_ARGV_TC1     {}       /* Enable passing argc/argv to main() */\n".format(
                origin_data_tc1['__USE_ARGC_ARGV_TC1']))
        header_file.write(
            "#define __ARGCV_BUFSIZE_TC1     {}     /* Buffer size for argv */\n".format(
                origin_data_tc1['__ARGCV_BUFSIZE_TC1']))
        header_file.write("\n")
        header_file.write("\n")
        header_file.write("/* Trap Vectors */\n")
        header_file.write("#define __RESOLVE_TRAP_0_TC1    {}       /* Class 0: MMU */\n".format(
            origin_data_tc1['__RESOLVE_TRAP_0_TC1']))
        header_file.write("#define __RESOLVE_TRAP_1_TC1    {}       /* Class 1: Internal protection */\n".format(
            origin_data_tc1['__RESOLVE_TRAP_1_TC1']))
        header_file.write("#define __RESOLVE_TRAP_2_TC1    {}       /* Class 2: Instruction error */\n".format(
            origin_data_tc1['__RESOLVE_TRAP_2_TC1']))
        header_file.write("#define __RESOLVE_TRAP_3_TC1    {}       /* Class 3: Context management */\n".format(
            origin_data_tc1['__RESOLVE_TRAP_3_TC1']))
        header_file.write(
            "#define __RESOLVE_TRAP_4_TC1    {}       /* Class 4: System bus and peripheral errors */\n".format(
                origin_data_tc1['__RESOLVE_TRAP_4_TC1']))
        header_file.write("#define __RESOLVE_TRAP_5_TC1    {}       /* Class 5: Assertion */\n".format(
            origin_data_tc1['__RESOLVE_TRAP_5_TC1']))
        header_file.write("#define __RESOLVE_TRAP_6_TC1    {}       /* Class 6: System call */\n".format(
            origin_data_tc1['__RESOLVE_TRAP_6_TC1']))
        header_file.write("#define __RESOLVE_TRAP_7_TC1    {}       /* Class 7: Non-maskable interrupt */\n".format(
            origin_data_tc1['__RESOLVE_TRAP_7_TC1']))
        header_file.write("\n")
        header_file.write("#endif /* __NO_CSTART_DEFAULT_CONFIG */\n")
        header_file.write("\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * Control of initialization registers\n")
        header_file.write(" *\n")
        header_file.write(" * The *_VALUE macros define the value of the register\n")
        header_file.write(" * The *_INIT macros must be defined to 0 or 1, specifying whether\n")
        header_file.write(" * or not it will be intialized by the cstart.c code.\n")
        header_file.write(" *\n")
        header_file.write(" * Most registers are not set to be initialized, which means that\n")
        header_file.write(" * the CPU's defaults are used. The bus configuration registers will be\n")
        header_file.write(" * set by running the 'Target Board Configuration' wizard.\n")
        header_file.write(" * The Eclipse environment will automatically apply the CPU default\n")
        header_file.write(" * values to the registers. These defaults are defined in the SFR files\n")
        header_file.write(" * from the include/sfr directory of the product.\n")
        header_file.write(" *\n")
        header_file.write(" */\n")
        header_file.write("#ifndef __NO_CSTART_REGISTER_CONFIG\n")
        header_file.write("\n")
        header_file.write("#define __PCON0_INIT            {}\n".format(origin_data_tc1['__PCON0_INIT']))
        header_file.write("#define __PCON0_VALUE           {}\n".format(origin_data_tc1['__PCON0_VALUE']))
        header_file.write("#define __DCON0_INIT            {}\n".format(origin_data_tc1['__DCON0_INIT']))
        header_file.write("#define __DCON0_VALUE           {}\n".format(origin_data_tc1['__DCON0_VALUE']))
        header_file.write("\n")
        header_file.write("#endif /*__NO_CSTART_REGISTER_CONFIG */\n")
        header_file.write("\n")
        header_file.write("#endif /* CSTART_TC1_H */\n")

    # tc2 header create
    save_file_name = save_file_path + "\\prost_cstart_tc2.h"
    with open(save_file_name, 'wt', encoding='utf-8', newline='') as header_file:
        header_file.write("/**************************************************************************\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  FILE        :  cstart_tc2.h                                           *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  DESCRIPTION :                                                         *\n")
        header_file.write("**      Header file to control the system startup code's general settings *\n")
        header_file.write("**      and register initializations. The cstart__tc2.c file must be part *\n")
        header_file.write("**      of your project to make use of this cstart__tc2.h.                *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**      In the Eclipse environment this file can be modified using the    *\n")
        header_file.write("**      C startup code editor, which provides a GUI to modify the         *\n")
        header_file.write("**      Configuration settings and register initialization.               *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  Copyright 1996-2013 Altium BV                                         *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**************************************************************************/\n")
        header_file.write("\n")
        header_file.write("#ifndef PROST_CSTART_TC2_H\n")
        header_file.write("#define PROST_CSTART_TC2_H\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * These items are shown in Eclipse on the C Start Configuration page\n")
        header_file.write(" */\n")
        header_file.write("\n")
        header_file.write("#ifndef __NO_CSTART_DEFAULT_CONFIG\n")
        header_file.write("\n")
        header_file.write("/* C Startup settings */\n")
        header_file.write(
            "#define __BIV_TC2_INIT          {}       /* Initialize base address of interrupt vector table */\n".format(
                origin_data_tc2['__BIV_TC2_INIT']))
        header_file.write(
            "#define __BIV_SINGLE_TC2_INIT   {}       /* Initialize single entry interrupt vector table */\n".format(
                origin_data_tc2['__BIV_SINGLE_TC2_INIT']))
        header_file.write(
            "#define __BIV_8BYTE_TC2_INIT    {}       /* Initialize 8 byte spacing interrupt vector table */\n".format(
                origin_data_tc2['__BIV_8BYTE_TC2_INIT']))
        header_file.write(
            "#define __BTV_TC2_INIT          {}       /* Initialize base address of trap vector table */\n".format(
                origin_data_tc2['__BTV_TC2_INIT']))
        header_file.write("#define __CSA_TC2_INIT          {}       /* Initialize CSA lists */\n".format(
            origin_data_tc2['__CSA_TC2_INIT']))
        header_file.write("#define __C_TC2_INIT            {}       /* Initialize and clear C variables */\n".format(
            origin_data_tc2['__C_TC2_INIT']))
        header_file.write("#define __USP_TC2_INIT          {}       /* Initialize user stack pointer */\n".format(
            origin_data_tc2['__USP_TC2_INIT']))
        header_file.write("#define __ISP_TC2_INIT          {}       /* Initialize interrupt stack pointer */\n".format(
            origin_data_tc2['__ISP_TC2_INIT']))
        header_file.write(
            "#define __A0A1_TC2_INIT         {}       /* Initialize a0 and a1 for _a0/_a1 addressing */\n".format(
                origin_data_tc2['__A0A1_TC2_INIT']))
        header_file.write(
            "#define __A8A9_TC2_INIT         {}       /* Initialize a8 and a9 for _a8/_a9 addressing (OS support) */\n".format(
                origin_data_tc2['__A8A9_TC2_INIT']))

        header_file.write(
            "#define __USER_STACK_TC2                {}       /* Use the user stack (clear PSW.IS) */\n".format(
                origin_data_tc2['__USER_STACK_TC2']))
        header_file.write(
            "#define __USE_ARGC_ARGV_TC2     {}       /* Enable passing argc/argv to main() */\n".format(
                origin_data_tc2['__USE_ARGC_ARGV_TC2']))
        header_file.write(
            "#define __ARGCV_BUFSIZE_TC2     {}     /* Buffer size for argv */\n".format(
                origin_data_tc2['__ARGCV_BUFSIZE_TC2']))

        header_file.write("\n")
        header_file.write("/* Trap Vectors */\n")
        header_file.write("#define __RESOLVE_TRAP_0_TC2    {}       /* Class 0: MMU */\n".format(
            origin_data_tc2['__RESOLVE_TRAP_0_TC2']))
        header_file.write("#define __RESOLVE_TRAP_1_TC2    {}       /* Class 1: Internal protection */\n".format(
            origin_data_tc2['__RESOLVE_TRAP_1_TC2']))
        header_file.write("#define __RESOLVE_TRAP_2_TC2    {}       /* Class 2: Instruction error */\n".format(
            origin_data_tc2['__RESOLVE_TRAP_2_TC2']))
        header_file.write("#define __RESOLVE_TRAP_3_TC2    {}       /* Class 3: Context management */\n".format(
            origin_data_tc2['__RESOLVE_TRAP_3_TC2']))
        header_file.write(
            "#define __RESOLVE_TRAP_4_TC2    {}       /* Class 4: System bus and peripheral errors */\n".format(
                origin_data_tc2['__RESOLVE_TRAP_4_TC2']))
        header_file.write("#define __RESOLVE_TRAP_5_TC2    {}       /* Class 5: Assertion */\n".format(
            origin_data_tc2['__RESOLVE_TRAP_5_TC2']))
        header_file.write("#define __RESOLVE_TRAP_6_TC2    {}       /* Class 6: System call */\n".format(
            origin_data_tc2['__RESOLVE_TRAP_6_TC2']))
        header_file.write("#define __RESOLVE_TRAP_7_TC2    {}       /* Class 7: Non-maskable interrupt */\n".format(
            origin_data_tc2['__RESOLVE_TRAP_7_TC2']))
        header_file.write("\n")
        header_file.write("#endif /* __NO_CSTART_DEFAULT_CONFIG */\n")
        header_file.write("\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * Control of initialization registers\n")
        header_file.write(" *\n")
        header_file.write(" * The *_VALUE macros define the value of the register\n")
        header_file.write(" * The *_INIT macros must be defined to 0 or 1, specifying whether\n")
        header_file.write(" * or not it will be intialized by the cstart.c code.\n")
        header_file.write(" *\n")
        header_file.write(" * Most registers are not set to be initialized, which means that\n")
        header_file.write(" * the CPU's defaults are used. The bus configuration registers will be\n")
        header_file.write(" * set by running the 'Target Board Configuration' wizard.\n")
        header_file.write(" * The Eclipse environment will automatically apply the CPU default\n")
        header_file.write(" * values to the registers. These defaults are defined in the SFR files\n")
        header_file.write(" * from the include/sfr directory of the product.\n")
        header_file.write(" *\n")
        header_file.write(" */\n")
        header_file.write("#ifndef __NO_CSTART_REGISTER_CONFIG\n")
        header_file.write("\n")
        header_file.write("#define __PCON0_INIT            {}\n".format(origin_data_tc2['__PCON0_INIT']))
        header_file.write("#define __PCON0_VALUE           {}\n".format(origin_data_tc2['__PCON0_VALUE']))
        header_file.write("#define __DCON0_INIT            {}\n".format(origin_data_tc2['__DCON0_INIT']))
        header_file.write("#define __DCON0_VALUE           {}\n".format(origin_data_tc2['__DCON0_VALUE']))
        header_file.write("\n")
        header_file.write("#endif /*__NO_CSTART_REGISTER_CONFIG */\n")
        header_file.write("\n")
        header_file.write("#endif /* CSTART_TC2_H */\n")
        header_file.write("\n")

def tasking_v43_h_default():
    origin_data_tc['__BIV_INIT'] = "0x1"
    origin_data_tc['__BIV_SINGLE_INIT'] = "0x0"
    origin_data_tc['__BIV_8BYTE_INIT'] = "0x0"
    origin_data_tc['__BTV_INIT'] = "0x1"
    origin_data_tc['__CSA_INIT'] = "0x1"
    origin_data_tc['__C_INIT'] = "0x1"
    origin_data_tc['__USP_INIT'] = "0x1"
    origin_data_tc['__ISP_INIT'] = "0x1"
    origin_data_tc['__A0A1_INIT'] = "0x1"
    origin_data_tc['__A8A9_INIT'] = "0x1"
    origin_data_tc['__USER_STACK'] = "0x1"
    origin_data_tc['__WATCHDOG_DISABLE'] = "0x1"
    origin_data_tc['__SAFETY_WATCHDOG_DISABLE'] = "0x1"
    origin_data_tc['__USE_ARGC_ARGV'] = "0x0"
    origin_data_tc['__ARGCV_BUFSIZE'] = "0x100"
    origin_data_tc['__CLOCKS_PER_SEC_INIT'] = "0x0"
    origin_data_tc['__fOSC'] = "0x1312D00"
    origin_data_tc['__PLL_K2_RAMPUP'] = "0x0"
    origin_data_tc['__STADD_INIT_TC1'] = "0x1"
    origin_data_tc['__STADD_INIT_TC2'] = "0x1"
    origin_data_tc['__HALT_INIT_TC1'] = "0x0"
    origin_data_tc['__HALT_INIT_TC2'] = "0x0"
    origin_data_tc['__HALT_VALUE_TC1'] = "0x0"
    origin_data_tc['__HALT_VALUE_TC2'] = "0x0"
    origin_data_tc['__RESOLVE_TRAP_0'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_1'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_2'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_3'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_4'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_5'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_6'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_7'] = "0x1"
    origin_data_tc['__EBU_BOOTCFG_INIT'] = "0x1"
    origin_data_tc['__EBU_BOOTCFG_VALUE'] = "0x800C"
    origin_data_tc['__PMI_CON0_INIT'] = "0x1"
    origin_data_tc['__PMI_CON0_VALUE'] = "0x0"
    origin_data_tc['__PMI_CON1_INIT'] = "0x0"
    origin_data_tc['__PMI_CON1_VALUE'] = "0x0"
    origin_data_tc['__PMI_CON2_INIT'] = "0x1"
    origin_data_tc['__PMI_CON2_VALUE'] = "0x0"
    origin_data_tc['__PMU_EIFCON_INIT'] = "0x0"
    origin_data_tc['__PMU_EIFCON_VALUE'] = "0x0"
    origin_data_tc['__DMI_CON_INIT'] = "0x1"
    origin_data_tc['__DMI_CON_VALUE'] = "0x0"
    origin_data_tc['__PLL_CLC_INIT'] = "0x0"
    origin_data_tc['__PLL_CLC_VALUE'] = "0x0"
    origin_data_tc['__SCU_PLLCON0_INIT'] = "0x0"
    origin_data_tc['__SCU_PLLCON0_VALUE'] = "0x0"
    origin_data_tc['__SCU_PLLCON1_INIT'] = "0x0"
    origin_data_tc['__SCU_PLLCON1_VALUE'] = "0x0"
    origin_data_tc['__SCU_OSCCON_INIT'] = "0x0"
    origin_data_tc['__SCU_OSCCON_VALUE'] = "0x0"
    origin_data_tc['__SCU_CCUCON0_INIT'] = "0x0"
    origin_data_tc['__SCU_CCUCON0_VALUE'] = "0x0"
    origin_data_tc['__SCU_CCUCON1_INIT'] = "0x0"
    origin_data_tc['__SCU_CCUCON1_VALUE'] = "0x0"
    origin_data_tc['__SCU_CCUCON2_INIT'] = "0x0"
    origin_data_tc['__SCU_CCUCON2_VALUE'] = "0x0"
    origin_data_tc['__STM_CLC_INIT'] = "0x0"
    origin_data_tc['__STM_CLC_VALUE'] = "0x0"
    origin_data_tc['__GTM_CLC_INIT'] = "0x1"
    origin_data_tc['__GTM_CLC_VALUE'] = "0x0"
    origin_data_tc['__FLASH0_FCON_INIT'] = "0x0"
    origin_data_tc['__FLASH0_FCON_VALUE'] = "0x0"
    origin_data_tc['__FLASH1_FCON_INIT'] = "0x0"
    origin_data_tc['__FLASH1_FCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL0_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL0_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL1_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL1_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL2_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL2_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL3_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL3_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL4_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL4_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL5_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL5_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL6_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL6_VALUE'] = "0x0"
    origin_data_tc['__EBU_BFCON_INIT'] = "0x0"
    origin_data_tc['__EBU_BFCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP0_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP1_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP2_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP3_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP4_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP4_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP5_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP5_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP6_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP6_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON0_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON1_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON2_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON3_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON4_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON4_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON5_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON5_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON6_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON6_VALUE'] = "0x0"
    origin_data_tc['__EBU_CLC_INIT'] = "0x0"
    origin_data_tc['__EBU_CLC_VALUE'] = "0x0"
    origin_data_tc['__EBU_CON_INIT'] = "0x0"
    origin_data_tc['__EBU_CON_VALUE'] = "0x0"
    origin_data_tc['__EBU_EMUAS_INIT'] = "0x0"
    origin_data_tc['__EBU_EMUAS_VALUE'] = "0x0"
    origin_data_tc['__EBU_EMUBAP_INIT'] = "0x0"
    origin_data_tc['__EBU_EMUBAP_VALUE'] = "0x0"
    origin_data_tc['__EBU_EMUBC_INIT'] = "0x0"
    origin_data_tc['__EBU_EMUBC_VALUE'] = "0x0"
    origin_data_tc['__EBU_EMUCON_INIT'] = "0x0"
    origin_data_tc['__EBU_EMUCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_EMUOVL_INIT'] = "0x0"
    origin_data_tc['__EBU_EMUOVL_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMCON0_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMCON0_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMCON1_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMCON1_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMOD0_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMOD0_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMOD1_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMOD1_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMREF0_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMREF0_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMREF1_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMREF1_VALUE'] = "0x0"
    origin_data_tc['__CBS_MCDBBS_INIT'] = "0x0"
    origin_data_tc['__CBS_MCDBBS_VALUE'] = "0x0"
    origin_data_tc['__SBCU_CON_INIT'] = "0x0"
    origin_data_tc['__SBCU_CON_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSRAP1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRAP1_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSRAP0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRAP0_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSRAP2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRAP2_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSRAP3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRAP3_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSRCON0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRCON0_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSRCON1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRCON1_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSRCON2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRCON2_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSRCON3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRCON3_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSWAP0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWAP0_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSWAP1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWAP1_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSWAP2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWAP2_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSWAP3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWAP3_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSWCON0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWCON0_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSWCON1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWCON1_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSWCON2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWCON2_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSWCON3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWCON3_VALUE'] = "0x0"
    origin_data_tc['__EBU_EXTBOOT_INIT'] = "0x0"
    origin_data_tc['__EBU_EXTBOOT_VALUE'] = "0x0"
    origin_data_tc['__EBU_MODCON_INIT'] = "0x0"
    origin_data_tc['__EBU_MODCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNCON_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNMOD_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNMOD_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNMOD2_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNMOD2_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNPRLD_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNPRLD_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG0_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG0_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG1_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG1_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG2_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG2_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG3_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG3_VALUE'] = "0x0"
    origin_data_tc['__EBU_DLLCON_INIT'] = "0x0"
    origin_data_tc['__EBU_DLLCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMCON_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMOD_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMOD_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMREF_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMREF_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRSTAT_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRSTAT_VALUE'] = "0x0"
    origin_data_tc['__PCON0_INIT'] = "0x1"
    origin_data_tc['__PCON0_VALUE'] = "0x0"
    origin_data_tc['__DCON0_INIT'] = "0x1"
    origin_data_tc['__DCON0_VALUE'] = "0x0"

def tasking_v62_h_default():
    origin_data_tc['__BIV_INIT'] = "0x1"
    origin_data_tc['__BIV_SINGLE_INIT'] = "0x0"
    origin_data_tc['__BIV_8BYTE_INIT'] = "0x0"
    origin_data_tc['__BTV_INIT'] = "0x1"
    origin_data_tc['__CSA_INIT'] = "0x1"
    origin_data_tc['__C_INIT'] = "0x1"
    origin_data_tc['__USP_INIT'] = "0x1"
    origin_data_tc['__ISP_INIT'] = "0x1"
    origin_data_tc['__A0A1_INIT'] = "0x1"
    origin_data_tc['__A8A9_INIT'] = "0x1"
    origin_data_tc['__RM_INIT'] = "0x0"
    origin_data_tc['__RM_VALUE'] = "FE_TONEAREST"
    origin_data_tc['__CDC'] = "0x0"
    origin_data_tc['__USER_STACK'] = "0x1"
    origin_data_tc['__WATCHDOG_DISABLE'] = "0x1"
    origin_data_tc['__SAFETY_WATCHDOG_DISABLE'] = "0x1"
    origin_data_tc['__COMPAT'] = "0xf"
    origin_data_tc['__USE_ARGC_ARGV'] = "0x0"
    origin_data_tc['__ARGCV_BUFSIZE'] = "256"
    origin_data_tc['__CLOCKS_PER_SEC_INIT'] = "0x0"
    origin_data_tc['__fOSC'] = "20000000"
    origin_data_tc['__PLL_K2_RAMPUP'] = "0x0"
    origin_data_tc['__START_INIT_TC1'] = "0x0"
    origin_data_tc['__START_INIT_TC2'] = "0x0"
    origin_data_tc['__START_INIT_TC3'] = "0x0"
    origin_data_tc['__START_INIT_TC4'] = "0x0"
    origin_data_tc['__START_INIT_TC5'] = "0x0"
    origin_data_tc['__RESOLVE_TRAP_0'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_1'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_2'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_3'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_4'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_5'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_6'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_7'] = "0x1"
    origin_data_tc['__XC800_INIT'] = "0x0"
    origin_data_tc['__EBU_BOOTCFG_INIT'] = "0x1"
    origin_data_tc['__EBU_BOOTCFG_VALUE'] = "0x800C"
    origin_data_tc['__PMI_CON0_INIT'] = "0x1"
    origin_data_tc['__PMI_CON0_VALUE'] = "0x0"
    origin_data_tc['__PMI_CON1_INIT'] = "0x0"
    origin_data_tc['__PMI_CON1_VALUE'] = "0x0"
    origin_data_tc['__PMI_CON2_INIT'] = "0x1"
    origin_data_tc['__PMI_CON2_VALUE'] = "0x0"
    origin_data_tc['__PMU_EIFCON_INIT'] = "0x0"
    origin_data_tc['__PMU_EIFCON_VALUE'] = "0x0"
    origin_data_tc['__DMI_CON_INIT'] = "0x1"
    origin_data_tc['__DMI_CON_VALUE'] = "0x0"
    origin_data_tc['__PLL_CLC_INIT'] = "0x0"
    origin_data_tc['__PLL_CLC_VALUE'] = "0x0"
    origin_data_tc['__SCU_PLLCON0_INIT'] = "0x0"
    origin_data_tc['__SCU_PLLCON0_VALUE'] = "0x0"
    origin_data_tc['__SCU_SYSPLLCON0_INIT'] = "0x0"
    origin_data_tc['__SCU_SYSPLLCON0_VALUE'] = "0x0"
    origin_data_tc['__SCU_PLLCON1_INIT'] = "0x0"
    origin_data_tc['__SCU_PLLCON1_VALUE'] = "0x0"
    origin_data_tc['__SCU_SYSPLLCON1_INIT'] = "0x0"
    origin_data_tc['__SCU_SYSPLLCON1_VALUE'] = "0x0"
    origin_data_tc['__SCU_OSCCON_INIT'] = "0x0"
    origin_data_tc['__SCU_OSCCON_VALUE'] = "0x0"
    origin_data_tc['__SCU_CCUCON0_INIT'] = "0x0"
    origin_data_tc['__SCU_CCUCON0_VALUE'] = "0x0"
    origin_data_tc['__SCU_CCUCON1_INIT'] = "0x0"
    origin_data_tc['__SCU_CCUCON1_VALUE'] = "0x0"
    origin_data_tc['__SCU_CCUCON2_INIT'] = "0x0"
    origin_data_tc['__SCU_CCUCON2_VALUE'] = "0x0"
    origin_data_tc['__STM_CLC_INIT'] = "0x0"
    origin_data_tc['__STM_CLC_VALUE'] = "0x0"
    origin_data_tc['__GTM_CLC_INIT'] = "0x1"
    origin_data_tc['__GTM_CLC_VALUE'] = "0x0"
    origin_data_tc['__FLASH0_FCON_INIT'] = "0x0"
    origin_data_tc['__FLASH0_FCON_VALUE'] = "0x0"
    origin_data_tc['__FLASH1_FCON_INIT'] = "0x0"
    origin_data_tc['__FLASH1_FCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL0_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL0_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL1_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL1_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL2_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL2_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL3_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL3_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL4_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL4_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL5_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL5_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL6_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL6_VALUE'] = "0x0"
    origin_data_tc['__EBU_BFCON_INIT'] = "0x0"
    origin_data_tc['__EBU_BFCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP0_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP1_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP2_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP3_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP4_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP4_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP5_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP5_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP6_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP6_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON0_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON1_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON2_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON3_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON4_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON4_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON5_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON5_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON6_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON6_VALUE'] = "0x0"
    origin_data_tc['__EBU_CLC_INIT'] = "0x0"
    origin_data_tc['__EBU_CLC_VALUE'] = "0x0"
    origin_data_tc['__EBU_CON_INIT'] = "0x0"
    origin_data_tc['__EBU_CON_VALUE'] = "0x0"
    origin_data_tc['__EBU_EMUAS_INIT'] = "0x0"
    origin_data_tc['__EBU_EMUAS_VALUE'] = "0x0"
    origin_data_tc['__EBU_EMUBAP_INIT'] = "0x0"
    origin_data_tc['__EBU_EMUBAP_VALUE'] = "0x0"
    origin_data_tc['__EBU_EMUBC_INIT'] = "0x0"
    origin_data_tc['__EBU_EMUBC_VALUE'] = "0x0"
    origin_data_tc['__EBU_EMUCON_INIT'] = "0x0"
    origin_data_tc['__EBU_EMUCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_EMUOVL_INIT'] = "0x0"
    origin_data_tc['__EBU_EMUOVL_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMCON0_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMCON0_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMCON1_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMCON1_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMOD0_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMOD0_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMOD1_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMOD1_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMREF0_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMREF0_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMREF1_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMREF1_VALUE'] = "0x0"
    origin_data_tc['__CBS_MCDBBS_INIT'] = "0x0"
    origin_data_tc['__CBS_MCDBBS_VALUE'] = "0x0"
    origin_data_tc['__SBCU_CON_INIT'] = "0x0"
    origin_data_tc['__SBCU_CON_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSRAP1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRAP1_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSRAP0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRAP0_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSRAP2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRAP2_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSRAP3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRAP3_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSRCON3_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSRCON0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRCON0_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSRCON1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRCON1_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSRCON2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRCON2_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSRCON3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRCON3_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSWAP0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWAP0_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSWAP1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWAP1_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSWAP2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWAP2_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSWAP3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWAP3_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSWCON0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWCON0_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSWCON1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWCON1_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSWCON2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWCON2_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSWCON3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWCON3_VALUE'] = "0x0"
    origin_data_tc['__EBU_EXTBOOT_INIT'] = "0x0"
    origin_data_tc['__EBU_EXTBOOT_VALUE'] = "0x0"
    origin_data_tc['__EBU_MODCON_INIT'] = "0x0"
    origin_data_tc['__EBU_MODCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNCON_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNMOD_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNMOD_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNMOD2_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNMOD2_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNPRLD_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNPRLD_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG0_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG0_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG1_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG1_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG2_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG2_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG3_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG3_VALUE'] = "0x0"
    origin_data_tc['__EBU_DLLCON_INIT'] = "0x0"
    origin_data_tc['__EBU_DLLCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMCON_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMOD_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMOD_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMREF_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMREF_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRSTAT_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRSTAT_VALUE'] = "0x0"
    origin_data_tc['__P24_PDR0_INIT'] = "0x0"
    origin_data_tc['__P24_PDR0_VALUE'] = "0x0"
    origin_data_tc['__P24_PDR1_INIT'] = "0x0"
    origin_data_tc['__P24_PDR1_VALUE'] = "0x0"
    origin_data_tc['__P25_PDR0_INIT'] = "0x0"
    origin_data_tc['__P25_PDR0_VALUE'] = "0x0"
    origin_data_tc['__P25_PDR1_INIT'] = "0x0"
    origin_data_tc['__P25_PDR1_VALUE'] = "0x0"
    origin_data_tc['__P30_PDR0_INIT'] = "0x0"
    origin_data_tc['__P30_PDR0_VALUE'] = "0x0"
    origin_data_tc['__P30_PDR1_INIT'] = "0x0"
    origin_data_tc['__P30_PDR1_VALUE'] = "0x0"
    origin_data_tc['__P31_PDR0_INIT'] = "0x0"
    origin_data_tc['__P31_PDR0_VALUE'] = "0x0"
    origin_data_tc['__P31_PDR1_INIT'] = "0x0"
    origin_data_tc['__P31_PDR1_VALUE'] = "0x0"
    origin_data_tc['__PCON0_INIT'] = "0x1"
    origin_data_tc['__PCON0_VALUE'] = "0x0"
    origin_data_tc['__DCON0_INIT'] = "0x1"
    origin_data_tc['__DCON0_VALUE'] = "0x0"

def tasking_v43(save_file_name):
    with open(save_file_name, 'wt', encoding='utf-8', newline='') as header_file:
        header_file.write("/**************************************************************************\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  FILE        :  cstart.h                                               *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  DESCRIPTION :                                                         *\n")
        header_file.write("**      Header file to control the system startup code's general settings *\n")
        header_file.write("**      and register initializations. The cstart.c file must be part of   *\n")
        header_file.write("**      your project to make use of this cstart.h.                        *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**      In the Eclipse environment this file can be modified using the    *\n")
        header_file.write("**      C startup code editor, which provides a GUI to modify the         *\n")
        header_file.write("**      Configuration settings and register initialization.               *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  Copyright 1996-2014 Altium BV                                         *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**************************************************************************/\n")
        header_file.write("\n")
        header_file.write("#ifndef CSTART_H\n")
        header_file.write("#define CSTART_H\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * These items are shown on in Eclipse on the C Start Configuration page\n")
        header_file.write(" */\n")
        header_file.write("\n")
        header_file.write("#ifndef __NO_CSTART_DEFAULT_CONFIG\n")
        header_file.write("\n")
        header_file.write("/* C Startup settings */\n")
        header_file.write(
            "#define __BIV_INIT              {}       /* Initialize base address of interrupt vector table */\n".format(
                origin_data_tc['__BIV_INIT']))
        header_file.write(
            "#define __BIV_SINGLE_INIT       {}       /* Initialize single entry interrupt vector table */\n".format(
                origin_data_tc['__BIV_SINGLE_INIT']))
        header_file.write(
            "#define __BIV_8BYTE_INIT        {}       /* Initialize 8 byte spacing interrupt vector table */\n".format(
                origin_data_tc['__BIV_8BYTE_INIT']))
        header_file.write(
            "#define __BTV_INIT              {}       /* Initialize base address of trap vector table */\n".format(
                origin_data_tc['__BTV_INIT']))
        header_file.write(
            "#define __CSA_INIT              {}       /* Initialize CSA lists */\n".format(origin_data_tc['__CSA_INIT']))
        header_file.write("#define __C_INIT                {}       /* Initialize and clear C variables */\n".format(
            origin_data_tc['__C_INIT']))
        header_file.write("#define __USP_INIT              {}       /* Initialize user stack pointer */\n".format(
            origin_data_tc['__USP_INIT']))
        header_file.write("#define __ISP_INIT              {}       /* Initialize interrupt stack pointer */\n".format(
            origin_data_tc['__ISP_INIT']))
        header_file.write(
            "#define __A0A1_INIT             {}       /* Initialize a0 and a1 for _a0/_a1 addressing */\n".format(
                origin_data_tc['__A0A1_INIT']))
        header_file.write(
            "#define __A8A9_INIT             {}       /* Initialize a8 and a9 for _a8/_a9 addressing (OS support) */\n".format(
                origin_data_tc['__A8A9_INIT']))
        header_file.write("\n")
        header_file.write("#define __USER_STACK            {}       /* Use the user stack (clear PSW.IS) */\n".format(
            origin_data_tc['__USER_STACK']))
        header_file.write("#define __WATCHDOG_DISABLE      {}       /* Watchdog disable */\n".format(
            origin_data_tc['__WATCHDOG_DISABLE']))
        header_file.write("#define __SAFETY_WATCHDOG_DISABLE {}     /* Safety watchdog disable */\n".format(
            origin_data_tc['__SAFETY_WATCHDOG_DISABLE']))
        header_file.write("#define __USE_ARGC_ARGV         {}       /* Enable passing argc/argv to main() */\n".format(
            origin_data_tc['__USE_ARGC_ARGV']))
        header_file.write("#define __ARGCV_BUFSIZE       {}       /* Buffer size for argv */\n".format(
            origin_data_tc['__ARGCV_BUFSIZE']))
        header_file.write("#define __CLOCKS_PER_SEC_INIT   {}       /* Initialize clocks per sec */\n".format(
            origin_data_tc['__CLOCKS_PER_SEC_INIT']))
        header_file.write(
            "#define __fOSC           {}       /* Oscillator frequency Hz */\n".format(origin_data_tc['__fOSC']))
        header_file.write(
            "#define __PLL_K2_RAMPUP         {}       /* PLL K2 rampup */\n".format(origin_data_tc['__PLL_K2_RAMPUP']))
        header_file.write("#define __STADD_INIT_TC1        {}       /* Initialize start address TC1 */\n".format(
            origin_data_tc['__STADD_INIT_TC1']))
        header_file.write("#define __STADD_INIT_TC2        {}       /* Initialize start address TC2 */\n".format(
            origin_data_tc['__STADD_INIT_TC2']))
        header_file.write("#define __HALT_INIT_TC1         {}       /* Initialize HALT state of TC1 */\n".format(
            origin_data_tc['__HALT_INIT_TC1']))
        header_file.write("#define __HALT_INIT_TC2         {}       /* Initialize HALT state of TC2 */\n".format(
            origin_data_tc['__HALT_INIT_TC2']))
        header_file.write("#define __HALT_VALUE_TC1        {}     /* Set HALT value of TC1 */\n".format(
            origin_data_tc['__HALT_VALUE_TC1']))
        header_file.write("                                        /* 0 R:running W:unchanged\n")
        header_file.write("                                           1 R:halted W:unchanged\n")
        header_file.write("                                           2 R:n.a. W:reset halt\n")
        header_file.write("                                           3 R:n.a. W:set when debug enable\n")
        header_file.write("                                        */\n")
        header_file.write("#define __HALT_VALUE_TC2        {}     /* Set HALT value of TC2 */\n".format(
            origin_data_tc['__HALT_VALUE_TC2']))
        header_file.write("                                        /* 0 R:running W:unchanged\n")
        header_file.write("                                           1 R:halted W:unchanged\n")
        header_file.write("                                           2 R:n.a. W:reset halt\n")
        header_file.write("                                           3 R:n.a. W:set when debug enable\n")
        header_file.write("                                        */\n")
        header_file.write("\n")
        header_file.write("/* Trap Vectors */\n")
        header_file.write(
            "#define __RESOLVE_TRAP_0        {}       /* Class 0: MMU */\n".format(origin_data_tc['__RESOLVE_TRAP_0']))
        header_file.write("#define __RESOLVE_TRAP_1        {}       /* Class 1: Internal protection */\n".format(
            origin_data_tc['__RESOLVE_TRAP_1']))
        header_file.write("#define __RESOLVE_TRAP_2        {}       /* Class 2: Instruction error */\n".format(
            origin_data_tc['__RESOLVE_TRAP_2']))
        header_file.write("#define __RESOLVE_TRAP_3        {}       /* Class 3: Context management */\n".format(
            origin_data_tc['__RESOLVE_TRAP_3']))
        header_file.write(
            "#define __RESOLVE_TRAP_4        {}       /* Class 4: System bus and peripheral errors */\n".format(
                origin_data_tc['__RESOLVE_TRAP_4']))
        header_file.write("#define __RESOLVE_TRAP_5        {}       /* Class 5: Assertion */\n".format(
            origin_data_tc['__RESOLVE_TRAP_5']))
        header_file.write("#define __RESOLVE_TRAP_6        {}       /* Class 6: System call */\n".format(
            origin_data_tc['__RESOLVE_TRAP_6']))
        header_file.write("#define __RESOLVE_TRAP_7        {}       /* Class 7: Non-maskable interrupt */\n".format(
            origin_data_tc['__RESOLVE_TRAP_7']))
        header_file.write("\n")
        header_file.write("\n")
        header_file.write("#endif /* __NO_CSTART_DEFAULT_CONFIG */\n")
        header_file.write("\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * Control of initialization registers\n")
        header_file.write(" *\n")
        header_file.write(" * The *_VALUE macros define the value of the register\n")
        header_file.write(" * The *_INIT macros must be defined to 0 or 1, specifying whether\n")
        header_file.write(" * or not it will be intialized by the cstart.c code.\n")
        header_file.write(" *\n")
        header_file.write(" * Most registers are not set to be initialized, which means that\n")
        header_file.write(" * the CPU's defaults are used. The bus configuration registers will be\n")
        header_file.write(" * set by running the 'Target Board Configuration' wizard.\n")
        header_file.write(" * The Eclipse environment will automatically apply the CPU default\n")
        header_file.write(" * values to the registers. These defaults are defined in the SFR files\n")
        header_file.write(" * from the include/sfr directory of the product.\n")
        header_file.write(" *\n")
        header_file.write(" */\n")
        header_file.write("\n")
        header_file.write("#define __EBU_BOOTCFG_INIT      {}\n".format(origin_data_tc['__EBU_BOOTCFG_INIT']))
        header_file.write("#define __EBU_BOOTCFG_VALUE     {}\n".format(origin_data_tc['__EBU_BOOTCFG_VALUE']))
        header_file.write("\n")
        header_file.write("#ifndef __NO_CSTART_REGISTER_CONFIG\n")
        header_file.write("/* Non-bus configuration: */\n")
        header_file.write("#define __PMI_CON0_INIT         {}\n".format(origin_data_tc['__PMI_CON0_INIT']))
        header_file.write("#define __PMI_CON0_VALUE        {}\n".format(origin_data_tc['__PMI_CON0_VALUE']))
        header_file.write("#define __PMI_CON1_INIT         {}\n".format(origin_data_tc['__PMI_CON1_INIT']))
        header_file.write("#define __PMI_CON1_VALUE        {}\n".format(origin_data_tc['__PMI_CON1_VALUE']))
        header_file.write("#define __PMI_CON2_INIT         {}\n".format(origin_data_tc['__PMI_CON2_INIT']))
        header_file.write("#define __PMI_CON2_VALUE        {}\n".format(origin_data_tc['__PMI_CON2_VALUE']))
        header_file.write("#define __PMU_EIFCON_INIT       {}\n".format(origin_data_tc['__PMU_EIFCON_INIT']))
        header_file.write("#define __PMU_EIFCON_VALUE      {}\n".format(origin_data_tc['__PMU_EIFCON_VALUE']))
        header_file.write("#define __DMI_CON_INIT          {}\n".format(origin_data_tc['__DMI_CON_INIT']))
        header_file.write("#define __DMI_CON_VALUE         {}\n".format(origin_data_tc['__DMI_CON_VALUE']))
        header_file.write("#define __PLL_CLC_INIT          {}\n".format(origin_data_tc['__PLL_CLC_INIT']))
        header_file.write("#define __PLL_CLC_VALUE         {}\n".format(origin_data_tc['__PLL_CLC_VALUE']))
        header_file.write("#define __SCU_PLLCON0_INIT      {}\n".format(origin_data_tc['__SCU_PLLCON0_INIT']))
        header_file.write("#define __SCU_PLLCON0_VALUE     {}\n".format(origin_data_tc['__SCU_PLLCON0_VALUE']))
        header_file.write("#define __SCU_PLLCON1_INIT      {}\n".format(origin_data_tc['__SCU_PLLCON1_INIT']))
        header_file.write("#define __SCU_PLLCON1_VALUE     {}\n".format(origin_data_tc['__SCU_PLLCON1_VALUE']))
        header_file.write("#define __SCU_OSCCON_INIT       {}\n".format(origin_data_tc['__SCU_OSCCON_INIT']))
        header_file.write("#define __SCU_OSCCON_VALUE      {}\n".format(origin_data_tc['__SCU_OSCCON_VALUE']))
        header_file.write("#define __SCU_CCUCON0_INIT      {}\n".format(origin_data_tc['__SCU_CCUCON0_INIT']))
        header_file.write("#define __SCU_CCUCON0_VALUE     {}\n".format(origin_data_tc['__SCU_CCUCON0_VALUE']))
        header_file.write("#define __SCU_CCUCON1_INIT      {}\n".format(origin_data_tc['__SCU_CCUCON1_INIT']))
        header_file.write("#define __SCU_CCUCON1_VALUE     {}\n".format(origin_data_tc['__SCU_CCUCON1_VALUE']))
        header_file.write("#define __SCU_CCUCON2_INIT      {}\n".format(origin_data_tc['__SCU_CCUCON2_INIT']))
        header_file.write("#define __SCU_CCUCON2_VALUE     {}\n".format(origin_data_tc['__SCU_CCUCON2_VALUE']))
        header_file.write("#define __STM_CLC_INIT          {}\n".format(origin_data_tc['__STM_CLC_INIT']))
        header_file.write("#define __STM_CLC_VALUE         {}\n".format(origin_data_tc['__STM_CLC_VALUE']))
        header_file.write("#define __GTM_CLC_INIT          {}\n".format(origin_data_tc['__GTM_CLC_INIT']))
        header_file.write("#define __GTM_CLC_VALUE         {}\n".format(origin_data_tc['__GTM_CLC_VALUE']))
        header_file.write("#define __FLASH0_FCON_INIT      {}\n".format(origin_data_tc['__FLASH0_FCON_INIT']))
        header_file.write("#define __FLASH0_FCON_VALUE     {}\n".format(origin_data_tc['__FLASH0_FCON_VALUE']))
        header_file.write("#define __FLASH1_FCON_INIT      {}\n".format(origin_data_tc['__FLASH1_FCON_INIT']))
        header_file.write("#define __FLASH1_FCON_VALUE     {}\n".format(origin_data_tc['__FLASH1_FCON_VALUE']))
        header_file.write("/* Bus configuration: (set by 'Target Board Configuration' wizard) */\n")
        header_file.write("#define __EBU_ADDRSEL0_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL0_INIT']))
        header_file.write("#define __EBU_ADDRSEL0_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL0_VALUE']))
        header_file.write("#define __EBU_ADDRSEL1_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL1_INIT']))
        header_file.write("#define __EBU_ADDRSEL1_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL1_VALUE']))
        header_file.write("#define __EBU_ADDRSEL2_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL2_INIT']))
        header_file.write("#define __EBU_ADDRSEL2_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL2_VALUE']))
        header_file.write("#define __EBU_ADDRSEL3_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL3_INIT']))
        header_file.write("#define __EBU_ADDRSEL3_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL3_VALUE']))
        header_file.write("#define __EBU_ADDRSEL4_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL4_INIT']))
        header_file.write("#define __EBU_ADDRSEL4_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL4_VALUE']))
        header_file.write("#define __EBU_ADDRSEL5_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL5_INIT']))
        header_file.write("#define __EBU_ADDRSEL5_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL5_VALUE']))
        header_file.write("#define __EBU_ADDRSEL6_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL6_INIT']))
        header_file.write("#define __EBU_ADDRSEL6_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL6_VALUE']))
        header_file.write("#define __EBU_BFCON_INIT        {}\n".format(origin_data_tc['__EBU_BFCON_INIT']))
        header_file.write("#define __EBU_BFCON_VALUE       {}\n".format(origin_data_tc['__EBU_BFCON_VALUE']))
        header_file.write("#define __EBU_BUSAP0_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP0_INIT']))
        header_file.write("#define __EBU_BUSAP0_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP0_VALUE']))
        header_file.write("#define __EBU_BUSAP1_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP1_INIT']))
        header_file.write("#define __EBU_BUSAP1_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP1_VALUE']))
        header_file.write("#define __EBU_BUSAP2_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP2_INIT']))
        header_file.write("#define __EBU_BUSAP2_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP2_VALUE']))
        header_file.write("#define __EBU_BUSAP3_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP3_INIT']))
        header_file.write("#define __EBU_BUSAP3_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP3_VALUE']))
        header_file.write("#define __EBU_BUSAP4_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP4_INIT']))
        header_file.write("#define __EBU_BUSAP4_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP4_VALUE']))
        header_file.write("#define __EBU_BUSAP5_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP5_INIT']))
        header_file.write("#define __EBU_BUSAP5_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP5_VALUE']))
        header_file.write("#define __EBU_BUSAP6_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP6_INIT']))
        header_file.write("#define __EBU_BUSAP6_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP6_VALUE']))
        header_file.write("#define __EBU_BUSCON0_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON0_INIT']))
        header_file.write("#define __EBU_BUSCON0_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON0_VALUE']))
        header_file.write("#define __EBU_BUSCON1_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON1_INIT']))
        header_file.write("#define __EBU_BUSCON1_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON1_VALUE']))
        header_file.write("#define __EBU_BUSCON2_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON2_INIT']))
        header_file.write("#define __EBU_BUSCON2_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON2_VALUE']))
        header_file.write("#define __EBU_BUSCON3_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON3_INIT']))
        header_file.write("#define __EBU_BUSCON3_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON3_VALUE']))
        header_file.write("#define __EBU_BUSCON4_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON4_INIT']))
        header_file.write("#define __EBU_BUSCON4_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON4_VALUE']))
        header_file.write("#define __EBU_BUSCON5_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON5_INIT']))
        header_file.write("#define __EBU_BUSCON5_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON5_VALUE']))
        header_file.write("#define __EBU_BUSCON6_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON6_INIT']))
        header_file.write("#define __EBU_BUSCON6_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON6_VALUE']))
        header_file.write("#define __EBU_CLC_INIT          {}\n".format(origin_data_tc['__EBU_CLC_INIT']))
        header_file.write("#define __EBU_CLC_VALUE         {}\n".format(origin_data_tc['__EBU_CLC_VALUE']))
        header_file.write("#define __EBU_CON_INIT          {}\n".format(origin_data_tc['__EBU_CON_INIT']))
        header_file.write("#define __EBU_CON_VALUE         {}\n".format(origin_data_tc['__EBU_CON_VALUE']))
        header_file.write("#define __EBU_EMUAS_INIT        {}\n".format(origin_data_tc['__EBU_EMUAS_INIT']))
        header_file.write("#define __EBU_EMUAS_VALUE       {}\n".format(origin_data_tc['__EBU_EMUAS_VALUE']))
        header_file.write("#define __EBU_EMUBAP_INIT       {}\n".format(origin_data_tc['__EBU_EMUBAP_INIT']))
        header_file.write("#define __EBU_EMUBAP_VALUE      {}\n".format(origin_data_tc['__EBU_EMUBAP_VALUE']))
        header_file.write("#define __EBU_EMUBC_INIT        {}\n".format(origin_data_tc['__EBU_EMUBC_INIT']))
        header_file.write("#define __EBU_EMUBC_VALUE       {}\n".format(origin_data_tc['__EBU_EMUBC_VALUE']))
        header_file.write("#define __EBU_EMUCON_INIT       {}\n".format(origin_data_tc['__EBU_EMUCON_INIT']))
        header_file.write("#define __EBU_EMUCON_VALUE      {}\n".format(origin_data_tc['__EBU_EMUCON_VALUE']))
        header_file.write("#define __EBU_EMUOVL_INIT       {}\n".format(origin_data_tc['__EBU_EMUOVL_INIT']))
        header_file.write("#define __EBU_EMUOVL_VALUE      {}\n".format(origin_data_tc['__EBU_EMUOVL_VALUE']))
        header_file.write("#define __EBU_SDRMCON0_INIT     {}\n".format(origin_data_tc['__EBU_SDRMCON0_INIT']))
        header_file.write("#define __EBU_SDRMCON0_VALUE    {}\n".format(origin_data_tc['__EBU_SDRMCON0_VALUE']))
        header_file.write("#define __EBU_SDRMCON1_INIT     {}\n".format(origin_data_tc['__EBU_SDRMCON1_INIT']))
        header_file.write("#define __EBU_SDRMCON1_VALUE    {}\n".format(origin_data_tc['__EBU_SDRMCON1_VALUE']))
        header_file.write("#define __EBU_SDRMOD0_INIT      {}\n".format(origin_data_tc['__EBU_SDRMOD0_INIT']))
        header_file.write("#define __EBU_SDRMOD0_VALUE     {}\n".format(origin_data_tc['__EBU_SDRMOD0_VALUE']))
        header_file.write("#define __EBU_SDRMOD1_INIT      {}\n".format(origin_data_tc['__EBU_SDRMOD1_INIT']))
        header_file.write("#define __EBU_SDRMOD1_VALUE     {}\n".format(origin_data_tc['__EBU_SDRMOD1_VALUE']))
        header_file.write("#define __EBU_SDRMREF0_INIT     {}\n".format(origin_data_tc['__EBU_SDRMREF0_INIT']))
        header_file.write("#define __EBU_SDRMREF0_VALUE    {}\n".format(origin_data_tc['__EBU_SDRMREF0_VALUE']))
        header_file.write("#define __EBU_SDRMREF1_INIT     {}\n".format(origin_data_tc['__EBU_SDRMREF1_INIT']))
        header_file.write("#define __EBU_SDRMREF1_VALUE    {}\n".format(origin_data_tc['__EBU_SDRMREF1_VALUE']))
        header_file.write("#define __CBS_MCDBBS_INIT       {}\n".format(origin_data_tc['__CBS_MCDBBS_INIT']))
        header_file.write("#define __CBS_MCDBBS_VALUE      {}\n".format(origin_data_tc['__CBS_MCDBBS_VALUE']))
        header_file.write("#define __SBCU_CON_INIT         {}\n".format(origin_data_tc['__SBCU_CON_INIT']))
        header_file.write("#define __SBCU_CON_VALUE        {}\n".format(origin_data_tc['__SBCU_CON_VALUE']))
        header_file.write("#define __EBU_BUSRAP1_INIT      {}\n".format(origin_data_tc['__EBU_BUSRAP1_INIT']))
        header_file.write("#define __EBU_BUSRAP1_VALUE     {}\n".format(origin_data_tc['__EBU_BUSRAP1_VALUE']))
        header_file.write("#define __EBU_BUSRAP0_INIT      {}\n".format(origin_data_tc['__EBU_BUSRAP0_INIT']))
        header_file.write("#define __EBU_BUSRAP0_VALUE     {}\n".format(origin_data_tc['__EBU_BUSRAP0_VALUE']))
        header_file.write("#define __EBU_BUSRAP2_INIT      {}\n".format(origin_data_tc['__EBU_BUSRAP2_INIT']))
        header_file.write("#define __EBU_BUSRAP2_VALUE     {}\n".format(origin_data_tc['__EBU_BUSRAP2_VALUE']))
        header_file.write("#define __EBU_BUSRAP3_INIT      {}\n".format(origin_data_tc['__EBU_BUSRAP3_INIT']))
        header_file.write("#define __EBU_BUSRAP3_VALUE     {}\n".format(origin_data_tc['__EBU_BUSRAP3_VALUE']))
        header_file.write("#define __EBU_BUSRCON0_INIT     {}\n".format(origin_data_tc['__EBU_BUSRCON0_INIT']))
        header_file.write("#define __EBU_BUSRCON0_VALUE    {}\n".format(origin_data_tc['__EBU_BUSRCON0_VALUE']))
        header_file.write("#define __EBU_BUSRCON1_INIT     {}\n".format(origin_data_tc['__EBU_BUSRCON1_INIT']))
        header_file.write("#define __EBU_BUSRCON1_VALUE    {}\n".format(origin_data_tc['__EBU_BUSRCON1_VALUE']))
        header_file.write("#define __EBU_BUSRCON2_INIT     {}\n".format(origin_data_tc['__EBU_BUSRCON2_INIT']))
        header_file.write("#define __EBU_BUSRCON2_VALUE    {}\n".format(origin_data_tc['__EBU_BUSRCON2_VALUE']))
        header_file.write("#define __EBU_BUSRCON3_INIT     {}\n".format(origin_data_tc['__EBU_BUSRCON3_INIT']))
        header_file.write("#define __EBU_BUSRCON3_VALUE    {}\n".format(origin_data_tc['__EBU_BUSRCON3_VALUE']))
        header_file.write("#define __EBU_BUSWAP0_INIT      {}\n".format(origin_data_tc['__EBU_BUSWAP0_INIT']))
        header_file.write("#define __EBU_BUSWAP0_VALUE     {}\n".format(origin_data_tc['__EBU_BUSWAP0_VALUE']))
        header_file.write("#define __EBU_BUSWAP1_INIT      {}\n".format(origin_data_tc['__EBU_BUSWAP1_INIT']))
        header_file.write("#define __EBU_BUSWAP1_VALUE     {}\n".format(origin_data_tc['__EBU_BUSWAP1_VALUE']))
        header_file.write("#define __EBU_BUSWAP2_INIT      {}\n".format(origin_data_tc['__EBU_BUSWAP2_INIT']))
        header_file.write("#define __EBU_BUSWAP2_VALUE     {}\n".format(origin_data_tc['__EBU_BUSWAP2_VALUE']))
        header_file.write("#define __EBU_BUSWAP3_INIT      {}\n".format(origin_data_tc['__EBU_BUSWAP3_INIT']))
        header_file.write("#define __EBU_BUSWAP3_VALUE     {}\n".format(origin_data_tc['__EBU_BUSWAP3_VALUE']))
        header_file.write("#define __EBU_BUSWCON0_INIT     {}\n".format(origin_data_tc['__EBU_BUSWCON0_INIT']))
        header_file.write("#define __EBU_BUSWCON0_VALUE    {}\n".format(origin_data_tc['__EBU_BUSWCON0_VALUE']))
        header_file.write("#define __EBU_BUSWCON1_INIT     {}\n".format(origin_data_tc['__EBU_BUSWCON1_INIT']))
        header_file.write("#define __EBU_BUSWCON1_VALUE    {}\n".format(origin_data_tc['__EBU_BUSWCON1_VALUE']))
        header_file.write("#define __EBU_BUSWCON2_INIT     {}\n".format(origin_data_tc['__EBU_BUSWCON2_INIT']))
        header_file.write("#define __EBU_BUSWCON2_VALUE    {}\n".format(origin_data_tc['__EBU_BUSWCON2_VALUE']))
        header_file.write("#define __EBU_BUSWCON3_INIT     {}\n".format(origin_data_tc['__EBU_BUSWCON3_INIT']))
        header_file.write("#define __EBU_BUSWCON3_VALUE    {}\n".format(origin_data_tc['__EBU_BUSWCON3_VALUE']))
        header_file.write("#define __EBU_EXTBOOT_INIT      {}\n".format(origin_data_tc['__EBU_EXTBOOT_INIT']))
        header_file.write("#define __EBU_EXTBOOT_VALUE     {}\n".format(origin_data_tc['__EBU_EXTBOOT_VALUE']))
        header_file.write("#define __EBU_MODCON_INIT       {}\n".format(origin_data_tc['__EBU_MODCON_INIT']))
        header_file.write("#define __EBU_MODCON_VALUE      {}\n".format(origin_data_tc['__EBU_MODCON_VALUE']))
        header_file.write("#define __EBU_DDRNCON_INIT      {}\n".format(origin_data_tc['__EBU_DDRNCON_INIT']))
        header_file.write("#define __EBU_DDRNCON_VALUE     {}\n".format(origin_data_tc['__EBU_DDRNCON_VALUE']))
        header_file.write("#define __EBU_DDRNMOD_INIT      {}\n".format(origin_data_tc['__EBU_DDRNMOD_INIT']))
        header_file.write("#define __EBU_DDRNMOD_VALUE     {}\n".format(origin_data_tc['__EBU_DDRNMOD_VALUE']))
        header_file.write("#define __EBU_DDRNMOD2_INIT     {}\n".format(origin_data_tc['__EBU_DDRNMOD2_INIT']))
        header_file.write("#define __EBU_DDRNMOD2_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNMOD2_VALUE']))
        header_file.write("#define __EBU_DDRNPRLD_INIT     {}\n".format(origin_data_tc['__EBU_DDRNPRLD_INIT']))
        header_file.write("#define __EBU_DDRNPRLD_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNPRLD_VALUE']))
        header_file.write("#define __EBU_DDRNTAG0_INIT     {}\n".format(origin_data_tc['__EBU_DDRNTAG0_INIT']))
        header_file.write("#define __EBU_DDRNTAG0_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNTAG0_VALUE']))
        header_file.write("#define __EBU_DDRNTAG1_INIT     {}\n".format(origin_data_tc['__EBU_DDRNTAG1_INIT']))
        header_file.write("#define __EBU_DDRNTAG1_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNTAG1_VALUE']))
        header_file.write("#define __EBU_DDRNTAG2_INIT     {}\n".format(origin_data_tc['__EBU_DDRNTAG2_INIT']))
        header_file.write("#define __EBU_DDRNTAG2_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNTAG2_VALUE']))
        header_file.write("#define __EBU_DDRNTAG3_INIT     {}\n".format(origin_data_tc['__EBU_DDRNTAG3_INIT']))
        header_file.write("#define __EBU_DDRNTAG3_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNTAG3_VALUE']))
        header_file.write("#define __EBU_DLLCON_INIT       {}\n".format(origin_data_tc['__EBU_DLLCON_INIT']))
        header_file.write("#define __EBU_DLLCON_VALUE      {}\n".format(origin_data_tc['__EBU_DLLCON_VALUE']))
        header_file.write("#define __EBU_SDRMCON_INIT      {}\n".format(origin_data_tc['__EBU_SDRMCON_INIT']))
        header_file.write("#define __EBU_SDRMCON_VALUE     {}\n".format(origin_data_tc['__EBU_SDRMCON_VALUE']))
        header_file.write("#define __EBU_SDRMOD_INIT       {}\n".format(origin_data_tc['__EBU_SDRMOD_INIT']))
        header_file.write("#define __EBU_SDRMOD_VALUE      {}\n".format(origin_data_tc['__EBU_SDRMOD_VALUE']))
        header_file.write("#define __EBU_SDRMREF_INIT      {}\n".format(origin_data_tc['__EBU_SDRMREF_INIT']))
        header_file.write("#define __EBU_SDRMREF_VALUE     {}\n".format(origin_data_tc['__EBU_SDRMREF_VALUE']))
        header_file.write("#define __EBU_SDRSTAT_INIT      {}\n".format(origin_data_tc['__EBU_SDRSTAT_INIT']))
        header_file.write("#define __EBU_SDRSTAT_VALUE     {}\n".format(origin_data_tc['__EBU_SDRSTAT_VALUE']))
        header_file.write("#define __PCON0_INIT            {}\n".format(origin_data_tc['__PCON0_INIT']))
        header_file.write("#define __PCON0_VALUE           {}\n".format(origin_data_tc['__PCON0_VALUE']))
        header_file.write("#define __DCON0_INIT            {}\n".format(origin_data_tc['__DCON0_INIT']))
        header_file.write("#define __DCON0_VALUE           {}\n".format(origin_data_tc['__DCON0_VALUE']))
        header_file.write("\n")
        header_file.write("#endif /*__NO_CSTART_REGISTER_CONFIG */\n")
        header_file.write("\n")
        header_file.write("#endif /* CSTART_H */\n")

# skc 220210
def tasking_v62_tc38x_h_default(dic_project_info):
    # tc0 header
    origin_data_tc['__BIV_INIT'] = "0x1"
    origin_data_tc['__BIV_SINGLE_INIT'] = "0x0"
    origin_data_tc['__BIV_8BYTE_INIT'] = "0x0"
    origin_data_tc['__BTV_INIT'] = "0x1"
    origin_data_tc['__CSA_INIT'] = "0x1"
    origin_data_tc['__C_INIT'] = "0x1"
    origin_data_tc['__USP_INIT'] = "0x1"
    origin_data_tc['__ISP_INIT'] = "0x1"
    origin_data_tc['__A0A1_INIT'] = "0x1"
    origin_data_tc['__A8A9_INIT'] = "0x1"
    origin_data_tc['__RM_INIT'] = "0x0"
    origin_data_tc['__RM_VALUE'] = "FE_TONEAREST"
    origin_data_tc['__CDC'] = "0x0"
    origin_data_tc['__USER_STACK'] = "0x1"
    origin_data_tc['__WATCHDOG_DISABLE'] = "0x1"
    origin_data_tc['__SAFETY_WATCHDOG_DISABLE'] = "0x1"
    origin_data_tc['__COMPAT'] = "0xf"
    origin_data_tc['__USE_ARGC_ARGV'] = "0x0"
    origin_data_tc['__ARGCV_BUFSIZE'] = "0x100"
    origin_data_tc['__CLOCKS_PER_SEC_INIT'] = "0x0"
    origin_data_tc['__fOSC'] = dic_project_info['Test_Env']['CPU_Clock']
    origin_data_tc['__PLL_K2_RAMPUP'] = "0x0"
    origin_data_tc['__START_INIT_TC1'] = "0x1"
    origin_data_tc['__START_INIT_TC2'] = "0x1"
    origin_data_tc['__START_INIT_TC3'] = "0x1"
    origin_data_tc['__START_INIT_TC4'] = "0x1"
    origin_data_tc['__START_INIT_TC5'] = "0x1"

    origin_data_tc['__RESOLVE_TRAP_0'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_1'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_2'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_3'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_4'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_5'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_6'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_7'] = "0x1"
    origin_data_tc['__XC800_INIT'] = "0x0"
    origin_data_tc['__EBU_BOOTCFG_INIT'] = "0x1"
    origin_data_tc['__EBU_BOOTCFG_VALUE'] = "0x800C"
    origin_data_tc['__PMI_CON0_INIT'] = "0x1"
    origin_data_tc['__PMI_CON0_VALUE'] = "0x0"
    origin_data_tc['__PMI_CON1_INIT'] = "0x0"
    origin_data_tc['__PMI_CON1_VALUE'] = "0x0"
    origin_data_tc['__PMI_CON2_INIT'] = "0x1"
    origin_data_tc['__PMI_CON2_VALUE'] = "0x0"
    origin_data_tc['__PMU_EIFCON_INIT'] = "0x0"
    origin_data_tc['__PMU_EIFCON_VALUE'] = "0x0"
    origin_data_tc['__DMI_CON_INIT'] = "0x1"
    origin_data_tc['__DMI_CON_VALUE'] = "0x0"
    origin_data_tc['__PLL_CLC_INIT'] = "0x0"
    origin_data_tc['__PLL_CLC_VALUE'] = "0x0"
    origin_data_tc['__SCU_PLLCON0_INIT'] = "0x0"
    origin_data_tc['__SCU_PLLCON0_VALUE'] = "0x00000000"
    origin_data_tc['__SCU_SYSPLLCON0_INIT'] = "0x0"
    origin_data_tc['__SCU_SYSPLLCON0_VALUE'] = "0x40003a00"
    origin_data_tc['__SCU_PLLCON1_INIT'] = "0x0"
    origin_data_tc['__SCU_PLLCON1_VALUE'] = "0x00000000"
    origin_data_tc['__SCU_SYSPLLCON1_INIT'] = "0x00000000"
    origin_data_tc['__SCU_SYSPLLCON1_VALUE'] = "0x00000005"
    origin_data_tc['__SCU_OSCCON_INIT'] = "1"               #skc###
    origin_data_tc['__SCU_OSCCON_VALUE'] = "0x00070018"     #skc###
    origin_data_tc['__SCU_CCUCON0_INIT'] = "1"              #skc###
    origin_data_tc['__SCU_CCUCON0_VALUE'] = "0x05120112"    #skc###
    origin_data_tc['__SCU_CCUCON1_INIT'] = "1"              #skc###
    origin_data_tc['__SCU_CCUCON1_VALUE'] = "0x11100002"    #skc###
    origin_data_tc['__SCU_CCUCON2_INIT'] = "0x0"
    origin_data_tc['__SCU_CCUCON2_VALUE'] = "0x07000101"    #skc###
    origin_data_tc['__STM_CLC_INIT'] = "0x0"
    origin_data_tc['__STM_CLC_VALUE'] = "0x0"
    origin_data_tc['__GTM_CLC_INIT'] = "0x1"
    origin_data_tc['__GTM_CLC_VALUE'] = "0x0"
    origin_data_tc['__FLASH0_FCON_INIT'] = "0x0"
    origin_data_tc['__FLASH0_FCON_VALUE'] = "0x00000000"
    origin_data_tc['__FLASH1_FCON_INIT'] = "0x0"
    origin_data_tc['__FLASH1_FCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL0_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL0_VALUE'] = "0x00000000"   #skc###
    origin_data_tc['__EBU_ADDRSEL1_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL1_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL2_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL2_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL3_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL3_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL4_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL4_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL5_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL5_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL6_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL6_VALUE'] = "0x0"
    origin_data_tc['__EBU_BFCON_INIT'] = "0x0"
    origin_data_tc['__EBU_BFCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP0_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP1_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP2_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP3_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP4_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP4_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP5_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP5_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP6_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP6_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON0_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON1_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON2_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON3_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON4_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON4_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON5_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON5_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON6_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON6_VALUE'] = "0x0"
    origin_data_tc['__EBU_CLC_INIT'] = "0x0"
    origin_data_tc['__EBU_CLC_VALUE'] = "0x00000000"        #skc###
    origin_data_tc['__EBU_CON_INIT'] = "0x0"
    origin_data_tc['__EBU_CON_VALUE'] = "0x0"
    origin_data_tc['__EBU_EMUAS_INIT'] = "0x0"
    origin_data_tc['__EBU_EMUAS_VALUE'] = "0x0"
    origin_data_tc['__EBU_EMUBAP_INIT'] = "0x0"
    origin_data_tc['__EBU_EMUBAP_VALUE'] = "0x0"
    origin_data_tc['__EBU_EMUBC_INIT'] = "0x0"
    origin_data_tc['__EBU_EMUBC_VALUE'] = "0x0"
    origin_data_tc['__EBU_EMUCON_INIT'] = "0x0"
    origin_data_tc['__EBU_EMUCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_EMUOVL_INIT'] = "0x0"
    origin_data_tc['__EBU_EMUOVL_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMCON0_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMCON0_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMCON1_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMCON1_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMOD0_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMOD0_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMOD1_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMOD1_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMREF0_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMREF0_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMREF1_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMREF1_VALUE'] = "0x0"
    origin_data_tc['__CBS_MCDBBS_INIT'] = "0x0"
    origin_data_tc['__CBS_MCDBBS_VALUE'] = "0x0"
    origin_data_tc['__SBCU_CON_INIT'] = "0x0"
    origin_data_tc['__SBCU_CON_VALUE'] = "0xff09ffff"
    origin_data_tc['__EBU_BUSRAP1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRAP1_VALUE'] = "0x00000000"        #skc###
    origin_data_tc['__EBU_BUSRAP0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRAP0_VALUE'] = "0x00000000"        #skc###
    origin_data_tc['__EBU_BUSRAP2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRAP2_VALUE'] = "0x00000000"        #skc###
    origin_data_tc['__EBU_BUSRAP3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRAP3_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSRCON0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRCON0_VALUE'] = "0x00000000"       #skc###
    origin_data_tc['__EBU_BUSRCON1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRCON1_VALUE'] = "0x00000000"       #skc###
    origin_data_tc['__EBU_BUSRCON2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRCON2_VALUE'] = "0x00000000"       #skc###
    origin_data_tc['__EBU_BUSRCON3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRCON3_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSWAP0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWAP0_VALUE'] = "0x00000000"        #skc###
    origin_data_tc['__EBU_BUSWAP1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWAP1_VALUE'] = "0x00000000"        #skc###
    origin_data_tc['__EBU_BUSWAP2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWAP2_VALUE'] = "0x00000000"        #skc###
    origin_data_tc['__EBU_BUSWAP3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWAP3_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSWCON0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWCON0_VALUE'] = "0x00000000"       #skc###
    origin_data_tc['__EBU_BUSWCON1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWCON1_VALUE'] = "0x00000000"       #skc###
    origin_data_tc['__EBU_BUSWCON2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWCON2_VALUE'] = "0x00000000"       #skc###
    origin_data_tc['__EBU_BUSWCON3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWCON3_VALUE'] = "0x0"
    origin_data_tc['__EBU_EXTBOOT_INIT'] = "0x0"
    origin_data_tc['__EBU_EXTBOOT_VALUE'] = "0x00000000"        #skc###
    origin_data_tc['__EBU_MODCON_INIT'] = "0x0"
    origin_data_tc['__EBU_MODCON_VALUE'] = "0x00000000"         #skc###
    origin_data_tc['__EBU_DDRNCON_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNMOD_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNMOD_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNMOD2_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNMOD2_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNPRLD_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNPRLD_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG0_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG0_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG1_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG1_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG2_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG2_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG3_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG3_VALUE'] = "0x0"
    origin_data_tc['__EBU_DLLCON_INIT'] = "0x0"
    origin_data_tc['__EBU_DLLCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMCON_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMCON_VALUE'] = "0x00000000"        #skc###
    origin_data_tc['__EBU_SDRMOD_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMOD_VALUE'] = "0x00000000"         #skc###
    origin_data_tc['__EBU_SDRMREF_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMREF_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRSTAT_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRSTAT_VALUE'] = "0x0"
    origin_data_tc['__P24_PDR0_INIT'] = "0x0"
    origin_data_tc['__P24_PDR0_VALUE'] = "0x00000000"           #skc###
    origin_data_tc['__P24_PDR1_INIT'] = "0x0"
    origin_data_tc['__P24_PDR1_VALUE'] = "0x00000000"           #skc###
    origin_data_tc['__P25_PDR0_INIT'] = "0x0"
    origin_data_tc['__P25_PDR0_VALUE'] = "0x00000000"           #skc###
    origin_data_tc['__P25_PDR1_INIT'] = "0x0"
    origin_data_tc['__P25_PDR1_VALUE'] = "0x00000000"           #skc###
    origin_data_tc['__P30_PDR0_INIT'] = "0x0"
    origin_data_tc['__P30_PDR0_VALUE'] = "0x00000000"           #skc###
    origin_data_tc['__P30_PDR1_INIT'] = "0x0"
    origin_data_tc['__P30_PDR1_VALUE'] = "0x00000000"           #skc###
    origin_data_tc['__P31_PDR0_INIT'] = "0x0"
    origin_data_tc['__P31_PDR0_VALUE'] = "0x00000000"           #skc###
    origin_data_tc['__P31_PDR1_INIT'] = "0x0"
    origin_data_tc['__P31_PDR1_VALUE'] = "0x00000000"           #skc###
    origin_data_tc['__PCON0_INIT'] = dic_project_info['Test_Env']['Pcache']
    origin_data_tc['__PCON0_VALUE'] = "0x0"
    origin_data_tc['__DCON0_INIT'] = dic_project_info['Test_Env']['Dcache']
    origin_data_tc['__DCON0_VALUE'] = "0x0"

    #tc1 header
    origin_data_tc1['__BIV_TC1_INIT'] = "0x1"
    origin_data_tc1['__BIV_SINGLE_TC1_INIT'] = "0x0"
    origin_data_tc1['__BIV_8BYTE_TC1_INIT'] = "0x0"
    origin_data_tc1['__BTV_TC1_INIT'] = "0x1"
    origin_data_tc1['__CSA_TC1_INIT'] = "0x1"
    origin_data_tc1['__C_TC1_INIT'] = "0x1"
    origin_data_tc1['__USP_TC1_INIT'] = "0x1"
    origin_data_tc1['__ISP_TC1_INIT'] = "0x1"
    origin_data_tc1['__A0A1_TC1_INIT'] = "0x1"
    origin_data_tc1['__A8A9_TC1_INIT'] = "0x1"
    origin_data_tc1['__RM_TC1_INIT'] = "0x0"
    origin_data_tc1['__RM_TC1_VALUE'] = "FE_TONEAREST"
    origin_data_tc1['__CDC_TC1'] = "0x0"
    origin_data_tc1['__USER_STACK_TC1'] = "0x1"
    origin_data_tc1['__COMPAT_TC1'] = "0xf"
    origin_data_tc1['__USE_ARGC_ARGV_TC1'] = "0x0"
    origin_data_tc1['__ARGCV_BUFSIZE_TC1'] = "0x100"
    origin_data_tc1['__RESOLVE_TRAP_0_TC1'] = "0x1"
    origin_data_tc1['__RESOLVE_TRAP_1_TC1'] = "0x1"
    origin_data_tc1['__RESOLVE_TRAP_2_TC1'] = "0x1"
    origin_data_tc1['__RESOLVE_TRAP_3_TC1'] = "0x1"
    origin_data_tc1['__RESOLVE_TRAP_4_TC1'] = "0x1"
    origin_data_tc1['__RESOLVE_TRAP_5_TC1'] = "0x1"
    origin_data_tc1['__RESOLVE_TRAP_6_TC1'] = "0x1"
    origin_data_tc1['__RESOLVE_TRAP_7_TC1'] = "0x1"
    origin_data_tc1['__PCON0_INIT'] = dic_project_info['Test_Env']['Pcache']
    origin_data_tc1['__PCON0_VALUE'] = "0x0"
    origin_data_tc1['__DCON0_INIT'] = dic_project_info['Test_Env']['Dcache']
    origin_data_tc1['__DCON0_VALUE'] = "0x0"

    # tc2 header
    origin_data_tc2['__BIV_TC2_INIT'] = "0x1"
    origin_data_tc2['__BIV_SINGLE_TC2_INIT'] = "0x0"
    origin_data_tc2['__BIV_8BYTE_TC2_INIT'] = "0x0"
    origin_data_tc2['__BTV_TC2_INIT'] = "0x1"
    origin_data_tc2['__CSA_TC2_INIT'] = "0x1"
    origin_data_tc2['__C_TC2_INIT'] = "0x1"
    origin_data_tc2['__USP_TC2_INIT'] = "0x1"
    origin_data_tc2['__ISP_TC2_INIT'] = "0x1"
    origin_data_tc2['__A0A1_TC2_INIT'] = "0x1"
    origin_data_tc2['__A8A9_TC2_INIT'] = "0x1"
    origin_data_tc2['__RM_TC2_INIT'] = "0x0"
    origin_data_tc2['__RM_TC2_VALUE'] = "FE_TONEAREST"
    origin_data_tc2['__CDC_TC2'] = "0x0"
    origin_data_tc2['__USER_STACK_TC2'] = "0x1"
    origin_data_tc2['__COMPAT_TC2'] = "0xf"
    origin_data_tc2['__USE_ARGC_ARGV_TC2'] = "0x0"
    origin_data_tc2['__ARGCV_BUFSIZE_TC2'] = "0x100"
    origin_data_tc2['__RESOLVE_TRAP_0_TC2'] = "0x1"
    origin_data_tc2['__RESOLVE_TRAP_1_TC2'] = "0x1"
    origin_data_tc2['__RESOLVE_TRAP_2_TC2'] = "0x1"
    origin_data_tc2['__RESOLVE_TRAP_3_TC2'] = "0x1"
    origin_data_tc2['__RESOLVE_TRAP_4_TC2'] = "0x1"
    origin_data_tc2['__RESOLVE_TRAP_5_TC2'] = "0x1"
    origin_data_tc2['__RESOLVE_TRAP_6_TC2'] = "0x1"
    origin_data_tc2['__RESOLVE_TRAP_7_TC2'] = "0x1"
    origin_data_tc2['__PCON0_INIT'] = dic_project_info['Test_Env']['Pcache']
    origin_data_tc2['__PCON0_VALUE'] = "0x0"
    origin_data_tc2['__DCON0_INIT'] = dic_project_info['Test_Env']['Dcache']
    origin_data_tc2['__DCON0_VALUE'] = "0x0"

    # tc3 header
    origin_data_tc3['__BIV_TC3_INIT'] = "0x1"
    origin_data_tc3['__BIV_SINGLE_TC3_INIT'] = "0x0"
    origin_data_tc3['__BIV_8BYTE_TC3_INIT'] = "0x0"
    origin_data_tc3['__BTV_TC3_INIT'] = "0x1"
    origin_data_tc3['__CSA_TC3_INIT'] = "0x1"
    origin_data_tc3['__C_TC3_INIT'] = "0x1"
    origin_data_tc3['__USP_TC3_INIT'] = "0x1"
    origin_data_tc3['__ISP_TC3_INIT'] = "0x1"
    origin_data_tc3['__A0A1_TC3_INIT'] = "0x1"
    origin_data_tc3['__A8A9_TC3_INIT'] = "0x1"
    origin_data_tc3['__RM_TC3_INIT'] = "0x0"
    origin_data_tc3['__RM_TC3_VALUE'] = "FE_TONEAREST"
    origin_data_tc3['__CDC_TC3'] = "0x0"
    origin_data_tc3['__USER_STACK_TC3'] = "0x1"
    origin_data_tc3['__COMPAT_TC3'] = "0xf"
    origin_data_tc3['__USE_ARGC_ARGV_TC3'] = "0x0"
    origin_data_tc3['__ARGCV_BUFSIZE_TC3'] = "0x100"
    origin_data_tc3['__RESOLVE_TRAP_0_TC3'] = "0x1"
    origin_data_tc3['__RESOLVE_TRAP_1_TC3'] = "0x1"
    origin_data_tc3['__RESOLVE_TRAP_2_TC3'] = "0x1"
    origin_data_tc3['__RESOLVE_TRAP_3_TC3'] = "0x1"
    origin_data_tc3['__RESOLVE_TRAP_4_TC3'] = "0x1"
    origin_data_tc3['__RESOLVE_TRAP_5_TC3'] = "0x1"
    origin_data_tc3['__RESOLVE_TRAP_6_TC3'] = "0x1"
    origin_data_tc3['__RESOLVE_TRAP_7_TC3'] = "0x1"
    origin_data_tc3['__PCON0_INIT'] = dic_project_info['Test_Env']['Pcache']
    origin_data_tc3['__PCON0_VALUE'] = "0x0"
    origin_data_tc3['__DCON0_INIT'] = dic_project_info['Test_Env']['Dcache']
    origin_data_tc3['__DCON0_VALUE'] = "0x0"

def tasking_v62_tc38x_h_modify_save(save_file_path):
    save_file_name = save_file_path + "\\prost_cstart.h"
    with open(save_file_name, 'wt', encoding='utf-8', newline='') as header_file:
        header_file.write("/**************************************************************************\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  FILE        :  cstart.h                                               *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  DESCRIPTION :                                                         *\n")
        header_file.write("**      Header file to control the system startup code's general settings *\n")
        header_file.write("**      and register initializations. The cstart.c file must be part of   *\n")
        header_file.write("**      your project to make use of this cstart.h.                        *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**      In the Eclipse environment this file can be modified using the    *\n")
        header_file.write("**      C startup code editor, which provides a GUI to modify the         *\n")
        header_file.write("**      Configuration settings and register initialization.               *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  Copyright 1996-2018 TASKING BV                                        *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**************************************************************************/\n")
        header_file.write("\n")
        header_file.write("#ifndef PROST_CSTART_H\n")
        header_file.write("#define PROST_CSTART_H\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * These items are shown on in Eclipse on the C Start Configuration page\n")
        header_file.write(" */\n")
        header_file.write("\n")
        header_file.write("#ifndef __NO_CSTART_DEFAULT_CONFIG\n")
        header_file.write("\n")
        header_file.write("/* C Startup settings */\n")
        header_file.write(
            "#define __BIV_INIT              {}       /* Initialize base address of interrupt vector table */\n".format(
                origin_data_tc['__BIV_INIT']))
        header_file.write(
            "#define __BIV_SINGLE_INIT       {}       /* Initialize single entry interrupt vector table */\n".format(
                origin_data_tc['__BIV_SINGLE_INIT']))
        header_file.write(
            "#define __BIV_8BYTE_INIT        {}       /* Initialize 8 byte spacing interrupt vector table */\n".format(
                origin_data_tc['__BIV_8BYTE_INIT']))
        header_file.write(
            "#define __BTV_INIT              {}       /* Initialize base address of trap vector table */\n".format(
                origin_data_tc['__BTV_INIT']))
        header_file.write(
            "#define __CSA_INIT              {}       /* Initialize CSA lists */\n".format(origin_data_tc['__CSA_INIT']))
        header_file.write("#define __C_INIT                {}       /* Initialize and clear C variables */\n".format(
            origin_data_tc['__C_INIT']))
        header_file.write("#define __USP_INIT              {}       /* Initialize user stack pointer */\n".format(
            origin_data_tc['__USP_INIT']))
        header_file.write("#define __ISP_INIT              {}       /* Initialize interrupt stack pointer */\n".format(
            origin_data_tc['__ISP_INIT']))
        header_file.write(
            "#define __A0A1_INIT             {}       /* Initialize a0 and a1 for _a0/_a1 addressing */\n".format(
                origin_data_tc['__A0A1_INIT']))
        header_file.write(
            "#define __A8A9_INIT             {}       /* Initialize a8 and a9 for _a8/_a9 addressing (OS support) */\n".format(
                origin_data_tc['__A8A9_INIT']))
        header_file.write("#define __RM_INIT               {}       /* Initialize rounding mode */\n".format(
            origin_data_tc['__RM_INIT']))
        header_file.write("#define __RM_VALUE              {}  /* FE_TONEAREST, FE_UPWARD, FE_DOWNWARD or FE_TOWARDZERO */\n".format(
            origin_data_tc['__RM_VALUE']))
        header_file.write(
            "#define __CDC                   {}     /* Call Depth Counter (set PSW.CDC) */\n".format(
                origin_data_tc['__CDC']))
        header_file.write("\n")
        header_file.write("#define __USER_STACK            {}       /* Use the user stack (clear PSW.IS) */\n".format(
            origin_data_tc['__USER_STACK']))
        header_file.write("#define __WATCHDOG_DISABLE      {}       /* Watchdog disable */\n".format(
            origin_data_tc['__WATCHDOG_DISABLE']))
        header_file.write("#define __SAFETY_WATCHDOG_DISABLE {}     /* Safety watchdog disable */\n".format(
            origin_data_tc['__SAFETY_WATCHDOG_DISABLE']))
        header_file.write("#define __COMPAT                {}     /* Compatibility mode */\n".format(
            origin_data_tc['__COMPAT']))
        header_file.write("#define __USE_ARGC_ARGV         {}       /* Enable passing argc/argv to main() */\n".format(
            origin_data_tc['__USE_ARGC_ARGV']))
        header_file.write("#define __ARGCV_BUFSIZE       {}       /* Buffer size for argv */\n".format(
            origin_data_tc['__ARGCV_BUFSIZE']))
        header_file.write("#define __CLOCKS_PER_SEC_INIT   {}       /* Initialize clocks per sec */\n".format(
            origin_data_tc['__CLOCKS_PER_SEC_INIT']))
        header_file.write(
            "#define __fOSC           {}       /* Oscillator frequency Hz */\n".format(origin_data_tc['__fOSC']))
        header_file.write(
            "#define __PLL_K2_RAMPUP         {}       /* PLL K2 rampup */\n".format(origin_data_tc['__PLL_K2_RAMPUP']))
        header_file.write(
            "#define __START_INIT_TC1        {}       /* Start TC1 */\n".format(origin_data_tc['__START_INIT_TC1']))
        header_file.write(
            "#define __START_INIT_TC2        {}       /* Start TC2 */\n".format(origin_data_tc['__START_INIT_TC2']))
        header_file.write(
            "#define __START_INIT_TC3        {}       /* Start TC3 */\n".format(origin_data_tc['__START_INIT_TC3']))
        header_file.write(
            "#define __START_INIT_TC4        {}       /* Start TC4 */\n".format(origin_data_tc['__START_INIT_TC4']))
        header_file.write(
            "#define __START_INIT_TC5        {}       /* Start TC5 */\n".format(origin_data_tc['__START_INIT_TC5']))

        header_file.write("\n")
        header_file.write("/* Trap Vectors */\n")
        header_file.write(
            "#define __RESOLVE_TRAP_0        {}       /* Class 0: MMU */\n".format(origin_data_tc['__RESOLVE_TRAP_0']))
        header_file.write("#define __RESOLVE_TRAP_1        {}       /* Class 1: Internal protection */\n".format(
            origin_data_tc['__RESOLVE_TRAP_1']))
        header_file.write("#define __RESOLVE_TRAP_2        {}       /* Class 2: Instruction error */\n".format(
            origin_data_tc['__RESOLVE_TRAP_2']))
        header_file.write("#define __RESOLVE_TRAP_3        {}       /* Class 3: Context management */\n".format(
            origin_data_tc['__RESOLVE_TRAP_3']))
        header_file.write(
            "#define __RESOLVE_TRAP_4        {}       /* Class 4: System bus and peripheral errors */\n".format(
                origin_data_tc['__RESOLVE_TRAP_4']))
        header_file.write("#define __RESOLVE_TRAP_5        {}       /* Class 5: Assertion */\n".format(
            origin_data_tc['__RESOLVE_TRAP_5']))
        header_file.write("#define __RESOLVE_TRAP_6        {}       /* Class 6: System call */\n".format(
            origin_data_tc['__RESOLVE_TRAP_6']))
        header_file.write("#define __RESOLVE_TRAP_7        {}       /* Class 7: Non-maskable interrupt */\n".format(
            origin_data_tc['__RESOLVE_TRAP_7']))
        header_file.write("#define __XC800_INIT            0       /* Download XC800 image to XRAM */\n".format(
            origin_data_tc['__XC800_INIT']))
        header_file.write("\n")
        header_file.write("\n")
        header_file.write("#endif /* __NO_CSTART_DEFAULT_CONFIG */\n")
        header_file.write("\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * Control of initialization registers\n")
        header_file.write(" *\n")
        header_file.write(" * The *_VALUE macros define the value of the register\n")
        header_file.write(" * The *_INIT macros must be defined to 0 or 1, specifying whether\n")
        header_file.write(" * or not it will be intialized by the cstart.c code.\n")
        header_file.write(" *\n")
        header_file.write(" * Most registers are not set to be initialized, which means that\n")
        header_file.write(" * the CPU's defaults are used. The bus configuration registers will be\n")
        header_file.write(" * set by running the 'Target Board Configuration' wizard.\n")
        header_file.write(" * The Eclipse environment will automatically apply the CPU default\n")
        header_file.write(" * values to the registers. These defaults are defined in the SFR files\n")
        header_file.write(" * from the include/sfr directory of the product.\n")
        header_file.write(" *\n")
        header_file.write(" */\n")
        header_file.write("\n")
        header_file.write("#define __EBU_BOOTCFG_INIT      {}\n".format(origin_data_tc['__EBU_BOOTCFG_INIT']))
        header_file.write("#define __EBU_BOOTCFG_VALUE     {}\n".format(origin_data_tc['__EBU_BOOTCFG_VALUE']))
        header_file.write("\n")
        header_file.write("#ifndef __NO_CSTART_REGISTER_CONFIG\n")
        header_file.write("/* Non-bus configuration: */\n")
        header_file.write("#define __PMI_CON0_INIT         {}\n".format(origin_data_tc['__PMI_CON0_INIT']))
        header_file.write("#define __PMI_CON0_VALUE        {}\n".format(origin_data_tc['__PMI_CON0_VALUE']))
        header_file.write("#define __PMI_CON1_INIT         {}\n".format(origin_data_tc['__PMI_CON1_INIT']))
        header_file.write("#define __PMI_CON1_VALUE        {}\n".format(origin_data_tc['__PMI_CON1_VALUE']))
        header_file.write("#define __PMI_CON2_INIT         {}\n".format(origin_data_tc['__PMI_CON2_INIT']))
        header_file.write("#define __PMI_CON2_VALUE        {}\n".format(origin_data_tc['__PMI_CON2_VALUE']))
        header_file.write("#define __PMU_EIFCON_INIT       {}\n".format(origin_data_tc['__PMU_EIFCON_INIT']))
        header_file.write("#define __PMU_EIFCON_VALUE      {}\n".format(origin_data_tc['__PMU_EIFCON_VALUE']))
        header_file.write("#define __DMI_CON_INIT          {}\n".format(origin_data_tc['__DMI_CON_INIT']))
        header_file.write("#define __DMI_CON_VALUE         {}\n".format(origin_data_tc['__DMI_CON_VALUE']))
        header_file.write("#define __PLL_CLC_INIT          {}\n".format(origin_data_tc['__PLL_CLC_INIT']))
        header_file.write("#define __PLL_CLC_VALUE         {}\n".format(origin_data_tc['__PLL_CLC_VALUE']))
        header_file.write("#define __SCU_PLLCON0_INIT      {}\n".format(origin_data_tc['__SCU_PLLCON0_INIT']))
        header_file.write("#define __SCU_PLLCON0_VALUE     {}\n".format(origin_data_tc['__SCU_PLLCON0_VALUE']))
        header_file.write("#define __SCU_SYSPLLCON0_INIT   {}\n".format(origin_data_tc['__SCU_SYSPLLCON0_INIT']))
        header_file.write("#define __SCU_SYSPLLCON0_VALUE  {}\n".format(origin_data_tc['__SCU_SYSPLLCON0_VALUE']))
        header_file.write("#define __SCU_PLLCON1_INIT      {}\n".format(origin_data_tc['__SCU_PLLCON1_INIT']))
        header_file.write("#define __SCU_PLLCON1_VALUE     {}\n".format(origin_data_tc['__SCU_PLLCON1_VALUE']))
        header_file.write("#define __SCU_SYSPLLCON1_INIT   {}\n".format(origin_data_tc['__SCU_SYSPLLCON1_INIT']))
        header_file.write("#define __SCU_SYSPLLCON1_VALUE  {}\n".format(origin_data_tc['__SCU_SYSPLLCON1_VALUE']))
        header_file.write("#define __SCU_OSCCON_INIT       {}\n".format(origin_data_tc['__SCU_OSCCON_INIT']))
        header_file.write("#define __SCU_OSCCON_VALUE      {}\n".format(origin_data_tc['__SCU_OSCCON_VALUE']))
        header_file.write("#define __SCU_CCUCON0_INIT      {}\n".format(origin_data_tc['__SCU_CCUCON0_INIT']))
        header_file.write("#define __SCU_CCUCON0_VALUE     {}\n".format(origin_data_tc['__SCU_CCUCON0_VALUE']))
        header_file.write("#define __SCU_CCUCON1_INIT      {}\n".format(origin_data_tc['__SCU_CCUCON1_INIT']))
        header_file.write("#define __SCU_CCUCON1_VALUE     {}\n".format(origin_data_tc['__SCU_CCUCON1_VALUE']))
        header_file.write("#define __SCU_CCUCON2_INIT      {}\n".format(origin_data_tc['__SCU_CCUCON2_INIT']))
        header_file.write("#define __SCU_CCUCON2_VALUE     {}\n".format(origin_data_tc['__SCU_CCUCON2_VALUE']))
        header_file.write("#define __STM_CLC_INIT          {}\n".format(origin_data_tc['__STM_CLC_INIT']))
        header_file.write("#define __STM_CLC_VALUE         {}\n".format(origin_data_tc['__STM_CLC_VALUE']))
        header_file.write("#define __GTM_CLC_INIT          {}\n".format(origin_data_tc['__GTM_CLC_INIT']))
        header_file.write("#define __GTM_CLC_VALUE         {}\n".format(origin_data_tc['__GTM_CLC_VALUE']))
        header_file.write("#define __FLASH0_FCON_INIT      {}\n".format(origin_data_tc['__FLASH0_FCON_INIT']))
        header_file.write("#define __FLASH0_FCON_VALUE     {}\n".format(origin_data_tc['__FLASH0_FCON_VALUE']))
        header_file.write("#define __FLASH1_FCON_INIT      {}\n".format(origin_data_tc['__FLASH1_FCON_INIT']))
        header_file.write("#define __FLASH1_FCON_VALUE     {}\n".format(origin_data_tc['__FLASH1_FCON_VALUE']))
        header_file.write("/* Bus configuration: (set by 'Target Board Configuration' wizard) */\n")
        header_file.write("#define __EBU_ADDRSEL0_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL0_INIT']))
        header_file.write("#define __EBU_ADDRSEL0_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL0_VALUE']))
        header_file.write("#define __EBU_ADDRSEL1_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL1_INIT']))
        header_file.write("#define __EBU_ADDRSEL1_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL1_VALUE']))
        header_file.write("#define __EBU_ADDRSEL2_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL2_INIT']))
        header_file.write("#define __EBU_ADDRSEL2_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL2_VALUE']))
        header_file.write("#define __EBU_ADDRSEL3_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL3_INIT']))
        header_file.write("#define __EBU_ADDRSEL3_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL3_VALUE']))
        header_file.write("#define __EBU_ADDRSEL4_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL4_INIT']))
        header_file.write("#define __EBU_ADDRSEL4_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL4_VALUE']))
        header_file.write("#define __EBU_ADDRSEL5_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL5_INIT']))
        header_file.write("#define __EBU_ADDRSEL5_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL5_VALUE']))
        header_file.write("#define __EBU_ADDRSEL6_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL6_INIT']))
        header_file.write("#define __EBU_ADDRSEL6_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL6_VALUE']))
        header_file.write("#define __EBU_BFCON_INIT        {}\n".format(origin_data_tc['__EBU_BFCON_INIT']))
        header_file.write("#define __EBU_BFCON_VALUE       {}\n".format(origin_data_tc['__EBU_BFCON_VALUE']))
        header_file.write("#define __EBU_BUSAP0_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP0_INIT']))
        header_file.write("#define __EBU_BUSAP0_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP0_VALUE']))
        header_file.write("#define __EBU_BUSAP1_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP1_INIT']))
        header_file.write("#define __EBU_BUSAP1_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP1_VALUE']))
        header_file.write("#define __EBU_BUSAP2_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP2_INIT']))
        header_file.write("#define __EBU_BUSAP2_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP2_VALUE']))
        header_file.write("#define __EBU_BUSAP3_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP3_INIT']))
        header_file.write("#define __EBU_BUSAP3_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP3_VALUE']))
        header_file.write("#define __EBU_BUSAP4_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP4_INIT']))
        header_file.write("#define __EBU_BUSAP4_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP4_VALUE']))
        header_file.write("#define __EBU_BUSAP5_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP5_INIT']))
        header_file.write("#define __EBU_BUSAP5_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP5_VALUE']))
        header_file.write("#define __EBU_BUSAP6_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP6_INIT']))
        header_file.write("#define __EBU_BUSAP6_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP6_VALUE']))
        header_file.write("#define __EBU_BUSCON0_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON0_INIT']))
        header_file.write("#define __EBU_BUSCON0_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON0_VALUE']))
        header_file.write("#define __EBU_BUSCON1_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON1_INIT']))
        header_file.write("#define __EBU_BUSCON1_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON1_VALUE']))
        header_file.write("#define __EBU_BUSCON2_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON2_INIT']))
        header_file.write("#define __EBU_BUSCON2_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON2_VALUE']))
        header_file.write("#define __EBU_BUSCON3_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON3_INIT']))
        header_file.write("#define __EBU_BUSCON3_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON3_VALUE']))
        header_file.write("#define __EBU_BUSCON4_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON4_INIT']))
        header_file.write("#define __EBU_BUSCON4_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON4_VALUE']))
        header_file.write("#define __EBU_BUSCON5_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON5_INIT']))
        header_file.write("#define __EBU_BUSCON5_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON5_VALUE']))
        header_file.write("#define __EBU_BUSCON6_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON6_INIT']))
        header_file.write("#define __EBU_BUSCON6_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON6_VALUE']))
        header_file.write("#define __EBU_CLC_INIT          {}\n".format(origin_data_tc['__EBU_CLC_INIT']))
        header_file.write("#define __EBU_CLC_VALUE         {}\n".format(origin_data_tc['__EBU_CLC_VALUE']))
        header_file.write("#define __EBU_CON_INIT          {}\n".format(origin_data_tc['__EBU_CON_INIT']))
        header_file.write("#define __EBU_CON_VALUE         {}\n".format(origin_data_tc['__EBU_CON_VALUE']))
        header_file.write("#define __EBU_EMUAS_INIT        {}\n".format(origin_data_tc['__EBU_EMUAS_INIT']))
        header_file.write("#define __EBU_EMUAS_VALUE       {}\n".format(origin_data_tc['__EBU_EMUAS_VALUE']))
        header_file.write("#define __EBU_EMUBAP_INIT       {}\n".format(origin_data_tc['__EBU_EMUBAP_INIT']))
        header_file.write("#define __EBU_EMUBAP_VALUE      {}\n".format(origin_data_tc['__EBU_EMUBAP_VALUE']))
        header_file.write("#define __EBU_EMUBC_INIT        {}\n".format(origin_data_tc['__EBU_EMUBC_INIT']))
        header_file.write("#define __EBU_EMUBC_VALUE       {}\n".format(origin_data_tc['__EBU_EMUBC_VALUE']))
        header_file.write("#define __EBU_EMUCON_INIT       {}\n".format(origin_data_tc['__EBU_EMUCON_INIT']))
        header_file.write("#define __EBU_EMUCON_VALUE      {}\n".format(origin_data_tc['__EBU_EMUCON_VALUE']))
        header_file.write("#define __EBU_EMUOVL_INIT       {}\n".format(origin_data_tc['__EBU_EMUOVL_INIT']))
        header_file.write("#define __EBU_EMUOVL_VALUE      {}\n".format(origin_data_tc['__EBU_EMUOVL_VALUE']))
        header_file.write("#define __EBU_SDRMCON0_INIT     {}\n".format(origin_data_tc['__EBU_SDRMCON0_INIT']))
        header_file.write("#define __EBU_SDRMCON0_VALUE    {}\n".format(origin_data_tc['__EBU_SDRMCON0_VALUE']))
        header_file.write("#define __EBU_SDRMCON1_INIT     {}\n".format(origin_data_tc['__EBU_SDRMCON1_INIT']))
        header_file.write("#define __EBU_SDRMCON1_VALUE    {}\n".format(origin_data_tc['__EBU_SDRMCON1_VALUE']))
        header_file.write("#define __EBU_SDRMOD0_INIT      {}\n".format(origin_data_tc['__EBU_SDRMOD0_INIT']))
        header_file.write("#define __EBU_SDRMOD0_VALUE     {}\n".format(origin_data_tc['__EBU_SDRMOD0_VALUE']))
        header_file.write("#define __EBU_SDRMOD1_INIT      {}\n".format(origin_data_tc['__EBU_SDRMOD1_INIT']))
        header_file.write("#define __EBU_SDRMOD1_VALUE     {}\n".format(origin_data_tc['__EBU_SDRMOD1_VALUE']))
        header_file.write("#define __EBU_SDRMREF0_INIT     {}\n".format(origin_data_tc['__EBU_SDRMREF0_INIT']))
        header_file.write("#define __EBU_SDRMREF0_VALUE    {}\n".format(origin_data_tc['__EBU_SDRMREF0_VALUE']))
        header_file.write("#define __EBU_SDRMREF1_INIT     {}\n".format(origin_data_tc['__EBU_SDRMREF1_INIT']))
        header_file.write("#define __EBU_SDRMREF1_VALUE    {}\n".format(origin_data_tc['__EBU_SDRMREF1_VALUE']))
        header_file.write("#define __CBS_MCDBBS_INIT       {}\n".format(origin_data_tc['__CBS_MCDBBS_INIT']))
        header_file.write("#define __CBS_MCDBBS_VALUE      {}\n".format(origin_data_tc['__CBS_MCDBBS_VALUE']))
        header_file.write("#define __SBCU_CON_INIT         {}\n".format(origin_data_tc['__SBCU_CON_INIT']))
        header_file.write("#define __SBCU_CON_VALUE        {}\n".format(origin_data_tc['__SBCU_CON_VALUE']))
        header_file.write("#define __EBU_BUSRAP1_INIT      {}\n".format(origin_data_tc['__EBU_BUSRAP1_INIT']))
        header_file.write("#define __EBU_BUSRAP1_VALUE     {}\n".format(origin_data_tc['__EBU_BUSRAP1_VALUE']))
        header_file.write("#define __EBU_BUSRAP0_INIT      {}\n".format(origin_data_tc['__EBU_BUSRAP0_INIT']))
        header_file.write("#define __EBU_BUSRAP0_VALUE     {}\n".format(origin_data_tc['__EBU_BUSRAP0_VALUE']))
        header_file.write("#define __EBU_BUSRAP2_INIT      {}\n".format(origin_data_tc['__EBU_BUSRAP2_INIT']))
        header_file.write("#define __EBU_BUSRAP2_VALUE     {}\n".format(origin_data_tc['__EBU_BUSRAP2_VALUE']))
        header_file.write("#define __EBU_BUSRAP3_INIT      {}\n".format(origin_data_tc['__EBU_BUSRAP3_INIT']))
        header_file.write("#define __EBU_BUSRAP3_VALUE     {}\n".format(origin_data_tc['__EBU_BUSRAP3_VALUE']))
        header_file.write("#define __EBU_BUSRCON0_INIT     {}\n".format(origin_data_tc['__EBU_BUSRCON0_INIT']))
        header_file.write("#define __EBU_BUSRCON0_VALUE    {}\n".format(origin_data_tc['__EBU_BUSRCON0_VALUE']))
        header_file.write("#define __EBU_BUSRCON1_INIT     {}\n".format(origin_data_tc['__EBU_BUSRCON1_INIT']))
        header_file.write("#define __EBU_BUSRCON1_VALUE    {}\n".format(origin_data_tc['__EBU_BUSRCON1_VALUE']))
        header_file.write("#define __EBU_BUSRCON2_INIT     {}\n".format(origin_data_tc['__EBU_BUSRCON2_INIT']))
        header_file.write("#define __EBU_BUSRCON2_VALUE    {}\n".format(origin_data_tc['__EBU_BUSRCON2_VALUE']))
        header_file.write("#define __EBU_BUSRCON3_INIT     {}\n".format(origin_data_tc['__EBU_BUSRCON3_INIT']))
        header_file.write("#define __EBU_BUSRCON3_VALUE    {}\n".format(origin_data_tc['__EBU_BUSRCON3_VALUE']))
        header_file.write("#define __EBU_BUSWAP0_INIT      {}\n".format(origin_data_tc['__EBU_BUSWAP0_INIT']))
        header_file.write("#define __EBU_BUSWAP0_VALUE     {}\n".format(origin_data_tc['__EBU_BUSWAP0_VALUE']))
        header_file.write("#define __EBU_BUSWAP1_INIT      {}\n".format(origin_data_tc['__EBU_BUSWAP1_INIT']))
        header_file.write("#define __EBU_BUSWAP1_VALUE     {}\n".format(origin_data_tc['__EBU_BUSWAP1_VALUE']))
        header_file.write("#define __EBU_BUSWAP2_INIT      {}\n".format(origin_data_tc['__EBU_BUSWAP2_INIT']))
        header_file.write("#define __EBU_BUSWAP2_VALUE     {}\n".format(origin_data_tc['__EBU_BUSWAP2_VALUE']))
        header_file.write("#define __EBU_BUSWAP3_INIT      {}\n".format(origin_data_tc['__EBU_BUSWAP3_INIT']))
        header_file.write("#define __EBU_BUSWAP3_VALUE     {}\n".format(origin_data_tc['__EBU_BUSWAP3_VALUE']))
        header_file.write("#define __EBU_BUSWCON0_INIT     {}\n".format(origin_data_tc['__EBU_BUSWCON0_INIT']))
        header_file.write("#define __EBU_BUSWCON0_VALUE    {}\n".format(origin_data_tc['__EBU_BUSWCON0_VALUE']))
        header_file.write("#define __EBU_BUSWCON1_INIT     {}\n".format(origin_data_tc['__EBU_BUSWCON1_INIT']))
        header_file.write("#define __EBU_BUSWCON1_VALUE    {}\n".format(origin_data_tc['__EBU_BUSWCON1_VALUE']))
        header_file.write("#define __EBU_BUSWCON2_INIT     {}\n".format(origin_data_tc['__EBU_BUSWCON2_INIT']))
        header_file.write("#define __EBU_BUSWCON2_VALUE    {}\n".format(origin_data_tc['__EBU_BUSWCON2_VALUE']))
        header_file.write("#define __EBU_BUSWCON3_INIT     {}\n".format(origin_data_tc['__EBU_BUSWCON3_INIT']))
        header_file.write("#define __EBU_BUSWCON3_VALUE    {}\n".format(origin_data_tc['__EBU_BUSWCON3_VALUE']))
        header_file.write("#define __EBU_EXTBOOT_INIT      {}\n".format(origin_data_tc['__EBU_EXTBOOT_INIT']))
        header_file.write("#define __EBU_EXTBOOT_VALUE     {}\n".format(origin_data_tc['__EBU_EXTBOOT_VALUE']))
        header_file.write("#define __EBU_MODCON_INIT       {}\n".format(origin_data_tc['__EBU_MODCON_INIT']))
        header_file.write("#define __EBU_MODCON_VALUE      {}\n".format(origin_data_tc['__EBU_MODCON_VALUE']))
        header_file.write("#define __EBU_DDRNCON_INIT      {}\n".format(origin_data_tc['__EBU_DDRNCON_INIT']))
        header_file.write("#define __EBU_DDRNCON_VALUE     {}\n".format(origin_data_tc['__EBU_DDRNCON_VALUE']))
        header_file.write("#define __EBU_DDRNMOD_INIT      {}\n".format(origin_data_tc['__EBU_DDRNMOD_INIT']))
        header_file.write("#define __EBU_DDRNMOD_VALUE     {}\n".format(origin_data_tc['__EBU_DDRNMOD_VALUE']))
        header_file.write("#define __EBU_DDRNMOD2_INIT     {}\n".format(origin_data_tc['__EBU_DDRNMOD2_INIT']))
        header_file.write("#define __EBU_DDRNMOD2_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNMOD2_VALUE']))
        header_file.write("#define __EBU_DDRNPRLD_INIT     {}\n".format(origin_data_tc['__EBU_DDRNPRLD_INIT']))
        header_file.write("#define __EBU_DDRNPRLD_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNPRLD_VALUE']))
        header_file.write("#define __EBU_DDRNTAG0_INIT     {}\n".format(origin_data_tc['__EBU_DDRNTAG0_INIT']))
        header_file.write("#define __EBU_DDRNTAG0_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNTAG0_VALUE']))
        header_file.write("#define __EBU_DDRNTAG1_INIT     {}\n".format(origin_data_tc['__EBU_DDRNTAG1_INIT']))
        header_file.write("#define __EBU_DDRNTAG1_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNTAG1_VALUE']))
        header_file.write("#define __EBU_DDRNTAG2_INIT     {}\n".format(origin_data_tc['__EBU_DDRNTAG2_INIT']))
        header_file.write("#define __EBU_DDRNTAG2_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNTAG2_VALUE']))
        header_file.write("#define __EBU_DDRNTAG3_INIT     {}\n".format(origin_data_tc['__EBU_DDRNTAG3_INIT']))
        header_file.write("#define __EBU_DDRNTAG3_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNTAG3_VALUE']))
        header_file.write("#define __EBU_DLLCON_INIT       {}\n".format(origin_data_tc['__EBU_DLLCON_INIT']))
        header_file.write("#define __EBU_DLLCON_VALUE      {}\n".format(origin_data_tc['__EBU_DLLCON_VALUE']))
        header_file.write("#define __EBU_SDRMCON_INIT      {}\n".format(origin_data_tc['__EBU_SDRMCON_INIT']))
        header_file.write("#define __EBU_SDRMCON_VALUE     {}\n".format(origin_data_tc['__EBU_SDRMCON_VALUE']))
        header_file.write("#define __EBU_SDRMOD_INIT       {}\n".format(origin_data_tc['__EBU_SDRMOD_INIT']))
        header_file.write("#define __EBU_SDRMOD_VALUE      {}\n".format(origin_data_tc['__EBU_SDRMOD_VALUE']))
        header_file.write("#define __EBU_SDRMREF_INIT      {}\n".format(origin_data_tc['__EBU_SDRMREF_INIT']))
        header_file.write("#define __EBU_SDRMREF_VALUE     {}\n".format(origin_data_tc['__EBU_SDRMREF_VALUE']))
        header_file.write("#define __EBU_SDRSTAT_INIT      {}\n".format(origin_data_tc['__EBU_SDRSTAT_INIT']))
        header_file.write("#define __EBU_SDRSTAT_VALUE     {}\n".format(origin_data_tc['__EBU_SDRSTAT_VALUE']))
        header_file.write("#define __P24_PDR0_INIT     {}\n".format(origin_data_tc['__P24_PDR0_INIT']))
        header_file.write("#define __P24_PDR0_VALUE    {}\n".format(origin_data_tc['__P24_PDR0_VALUE']))
        header_file.write("#define __P24_PDR1_INIT     {}\n".format(origin_data_tc['__P24_PDR1_INIT']))
        header_file.write("#define __P24_PDR1_VALUE    {}\n".format(origin_data_tc['__P24_PDR1_VALUE']))
        header_file.write("#define __P25_PDR0_INIT     {}\n".format(origin_data_tc['__P25_PDR0_INIT']))
        header_file.write("#define __P25_PDR0_VALUE    {}\n".format(origin_data_tc['__P25_PDR0_VALUE']))
        header_file.write("#define __P25_PDR1_INIT     {}\n".format(origin_data_tc['__P25_PDR1_INIT']))
        header_file.write("#define __P25_PDR1_VALUE    {}\n".format(origin_data_tc['__P25_PDR1_VALUE']))
        header_file.write("#define __P30_PDR0_INIT     {}\n".format(origin_data_tc['__P30_PDR0_INIT']))
        header_file.write("#define __P30_PDR0_VALUE    {}\n".format(origin_data_tc['__P30_PDR0_VALUE']))
        header_file.write("#define __P30_PDR1_INIT     {}\n".format(origin_data_tc['__P30_PDR1_INIT']))
        header_file.write("#define __P30_PDR1_VALUE    {}\n".format(origin_data_tc['__P30_PDR1_VALUE']))
        header_file.write("#define __P31_PDR0_INIT     {}\n".format(origin_data_tc['__P31_PDR0_INIT']))
        header_file.write("#define __P31_PDR0_VALUE    {}\n".format(origin_data_tc['__P31_PDR0_VALUE']))
        header_file.write("#define __P31_PDR1_INIT     {}\n".format(origin_data_tc['__P31_PDR1_INIT']))
        header_file.write("#define __P31_PDR1_VALUE    {}\n".format(origin_data_tc['__P31_PDR1_VALUE']))
        header_file.write("#define __PCON0_INIT            {}\n".format(origin_data_tc['__PCON0_INIT']))
        header_file.write("#define __PCON0_VALUE           {}\n".format(origin_data_tc['__PCON0_VALUE']))
        header_file.write("#define __DCON0_INIT            {}\n".format(origin_data_tc['__DCON0_INIT']))
        header_file.write("#define __DCON0_VALUE           {}\n".format(origin_data_tc['__DCON0_VALUE']))
        header_file.write("\n")
        header_file.write("#endif /*__NO_CSTART_REGISTER_CONFIG */\n")
        header_file.write("\n")
        header_file.write("#endif /* PROST_CSTART_H */\n")

    # tc1 header create
    save_file_name = save_file_path + "\\prost_cstart_tc1.h"
    with open(save_file_name, 'wt', encoding='utf-8', newline='') as header_file:
        header_file.write("/**************************************************************************\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  FILE        :  cstart_tc1.h                                           *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  DESCRIPTION :                                                         *\n")
        header_file.write("**      Header file to control the system startup code's general settings *\n")
        header_file.write("**      and register initializations. The cstart__tc1.c file must be part *\n")
        header_file.write("**      of your project to make use of this cstart__tc1.h.                *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**      In the Eclipse environment this file can be modified using the    *\n")
        header_file.write("**      C startup code editor, which provides a GUI to modify the         *\n")
        header_file.write("**      Configuration settings and register initialization.               *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  Copyright 1996-2018 TASKING BV                                        *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**************************************************************************/\n")
        header_file.write("\n")
        header_file.write("#ifndef PROST_CSTART_TC1_H\n")
        header_file.write("#define PROST_CSTART_TC1_H\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * These items are shown in Eclipse on the C Start Configuration page\n")
        header_file.write(" */\n")
        header_file.write("\n")
        header_file.write("#ifndef __NO_CSTART_DEFAULT_CONFIG\n")
        header_file.write("\n")
        header_file.write("/* C Startup settings */\n")
        header_file.write(
            "#define __BIV_TC1_INIT          {}       /* Initialize base address of interrupt vector table */\n".format(
                origin_data_tc1['__BIV_TC1_INIT']))
        header_file.write(
            "#define __BIV_SINGLE_TC1_INIT   {}       /* Initialize single entry interrupt vector table */\n".format(
                origin_data_tc1['__BIV_SINGLE_TC1_INIT']))
        header_file.write(
            "#define __BIV_8BYTE_TC1_INIT    {}       /* Initialize 8 byte spacing interrupt vector table */\n".format(
                origin_data_tc1['__BIV_8BYTE_TC1_INIT']))
        header_file.write(
            "#define __BTV_TC1_INIT          {}       /* Initialize base address of trap vector table */\n".format(
                origin_data_tc1['__BTV_TC1_INIT']))
        header_file.write("#define __CSA_TC1_INIT          {}       /* Initialize CSA lists */\n".format(
            origin_data_tc1['__CSA_TC1_INIT']))
        header_file.write("#define __C_TC1_INIT            {}       /* Initialize and clear C variables */\n".format(
            origin_data_tc1['__C_TC1_INIT']))
        header_file.write("#define __USP_TC1_INIT          {}       /* Initialize user stack pointer */\n".format(
            origin_data_tc1['__USP_TC1_INIT']))
        header_file.write("#define __ISP_TC1_INIT          {}       /* Initialize interrupt stack pointer */\n".format(
            origin_data_tc1['__ISP_TC1_INIT']))
        header_file.write(
            "#define __A0A1_TC1_INIT         {}       /* Initialize a0 and a1 for _a0/_a1 addressing */\n".format(
                origin_data_tc1['__A0A1_TC1_INIT']))
        header_file.write(
            "#define __A8A9_TC1_INIT         {}       /* Initialize a8 and a9 for _a8/_a9 addressing (OS support) */\n".format(
                origin_data_tc1['__A8A9_TC1_INIT']))
        header_file.write(
            "#define __RM_TC1_INIT           {}       /* Initialize rounding mode */\n".format(
                origin_data_tc1['__RM_TC1_INIT']))
        header_file.write(
            "#define __CDC_TC1                       {}     /* Call Depth Counter (set PSW.CDC) */\n".format(
                origin_data_tc1['__CDC_TC1']))
        header_file.write(
            "#define __RM_TC1_VALUE          {}  /* FE_TONEAREST, FE_UPWARD, FE_DOWNWARD or FE_TOWARDZERO */\n".format(
                origin_data_tc1['__RM_TC1_VALUE']))

        header_file.write(
            "#define __USER_STACK_TC1                {}       /* Use the user stack (clear PSW.IS) */\n".format(
                origin_data_tc1['__USER_STACK_TC1']))
        header_file.write(
            "#define __COMPAT_TC1            {}     /* Compatibility mode */\n".format(
                origin_data_tc1['__COMPAT_TC1']))
        header_file.write(
            "#define __USE_ARGC_ARGV_TC1     {}       /* Enable passing argc/argv to main() */\n".format(
                origin_data_tc1['__USE_ARGC_ARGV_TC1']))
        header_file.write(
            "#define __ARGCV_BUFSIZE_TC1     {}     /* Buffer size for argv */\n".format(
                origin_data_tc1['__ARGCV_BUFSIZE_TC1']))
        header_file.write("\n")
        header_file.write("\n")
        header_file.write("/* Trap Vectors */\n")
        header_file.write("#define __RESOLVE_TRAP_0_TC1    {}       /* Class 0: MMU */\n".format(
            origin_data_tc1['__RESOLVE_TRAP_0_TC1']))
        header_file.write("#define __RESOLVE_TRAP_1_TC1    {}       /* Class 1: Internal protection */\n".format(
            origin_data_tc1['__RESOLVE_TRAP_1_TC1']))
        header_file.write("#define __RESOLVE_TRAP_2_TC1    {}       /* Class 2: Instruction error */\n".format(
            origin_data_tc1['__RESOLVE_TRAP_2_TC1']))
        header_file.write("#define __RESOLVE_TRAP_3_TC1    {}       /* Class 3: Context management */\n".format(
            origin_data_tc1['__RESOLVE_TRAP_3_TC1']))
        header_file.write(
            "#define __RESOLVE_TRAP_4_TC1    {}       /* Class 4: System bus and peripheral errors */\n".format(
                origin_data_tc1['__RESOLVE_TRAP_4_TC1']))
        header_file.write("#define __RESOLVE_TRAP_5_TC1    {}       /* Class 5: Assertion */\n".format(
            origin_data_tc1['__RESOLVE_TRAP_5_TC1']))
        header_file.write("#define __RESOLVE_TRAP_6_TC1    {}       /* Class 6: System call */\n".format(
            origin_data_tc1['__RESOLVE_TRAP_6_TC1']))
        header_file.write("#define __RESOLVE_TRAP_7_TC1    {}       /* Class 7: Non-maskable interrupt */\n".format(
            origin_data_tc1['__RESOLVE_TRAP_7_TC1']))
        header_file.write("\n")
        header_file.write("#endif /* __NO_CSTART_DEFAULT_CONFIG */\n")
        header_file.write("\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * Control of initialization registers\n")
        header_file.write(" *\n")
        header_file.write(" * The *_VALUE macros define the value of the register\n")
        header_file.write(" * The *_INIT macros must be defined to 0 or 1, specifying whether\n")
        header_file.write(" * or not it will be intialized by the cstart.c code.\n")
        header_file.write(" *\n")
        header_file.write(" * Most registers are not set to be initialized, which means that\n")
        header_file.write(" * the CPU's defaults are used. The bus configuration registers will be\n")
        header_file.write(" * set by running the 'Target Board Configuration' wizard.\n")
        header_file.write(" * The Eclipse environment will automatically apply the CPU default\n")
        header_file.write(" * values to the registers. These defaults are defined in the SFR files\n")
        header_file.write(" * from the include/sfr directory of the product.\n")
        header_file.write(" *\n")
        header_file.write(" */\n")
        header_file.write("#ifndef __NO_CSTART_REGISTER_CONFIG\n")
        header_file.write("\n")
        header_file.write("#define __PCON0_INIT            {}\n".format(origin_data_tc1['__PCON0_INIT']))
        header_file.write("#define __PCON0_VALUE           {}\n".format(origin_data_tc1['__PCON0_VALUE']))
        header_file.write("#define __DCON0_INIT            {}\n".format(origin_data_tc1['__DCON0_INIT']))
        header_file.write("#define __DCON0_VALUE           {}\n".format(origin_data_tc1['__DCON0_VALUE']))
        header_file.write("\n")
        header_file.write("#endif /*__NO_CSTART_REGISTER_CONFIG */\n")
        header_file.write("\n")
        header_file.write("#endif /* PROST_CSTART_TC1_H */\n")

    # tc2 header create
    save_file_name = save_file_path + "\\prost_cstart_tc2.h"
    with open(save_file_name, 'wt', encoding='utf-8', newline='') as header_file:
        header_file.write("/**************************************************************************\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  FILE        :  cstart_tc2.h                                           *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  DESCRIPTION :                                                         *\n")
        header_file.write("**      Header file to control the system startup code's general settings *\n")
        header_file.write("**      and register initializations. The cstart__tc2.c file must be part *\n")
        header_file.write("**      of your project to make use of this cstart__tc2.h.                *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**      In the Eclipse environment this file can be modified using the    *\n")
        header_file.write("**      C startup code editor, which provides a GUI to modify the         *\n")
        header_file.write("**      Configuration settings and register initialization.               *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  Copyright 1996-2018 TASKING BV                                        *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**************************************************************************/\n")
        header_file.write("\n")
        header_file.write("#ifndef PROST_CSTART_TC2_H\n")
        header_file.write("#define PROST_CSTART_TC2_H\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * These items are shown in Eclipse on the C Start Configuration page\n")
        header_file.write(" */\n")
        header_file.write("\n")
        header_file.write("#ifndef __NO_CSTART_DEFAULT_CONFIG\n")
        header_file.write("\n")
        header_file.write("/* C Startup settings */\n")
        header_file.write(
            "#define __BIV_TC2_INIT          {}       /* Initialize base address of interrupt vector table */\n".format(
                origin_data_tc2['__BIV_TC2_INIT']))
        header_file.write(
            "#define __BIV_SINGLE_TC2_INIT   {}       /* Initialize single entry interrupt vector table */\n".format(
                origin_data_tc2['__BIV_SINGLE_TC2_INIT']))
        header_file.write(
            "#define __BIV_8BYTE_TC2_INIT    {}       /* Initialize 8 byte spacing interrupt vector table */\n".format(
                origin_data_tc2['__BIV_8BYTE_TC2_INIT']))
        header_file.write(
            "#define __BTV_TC2_INIT          {}       /* Initialize base address of trap vector table */\n".format(
                origin_data_tc2['__BTV_TC2_INIT']))
        header_file.write("#define __CSA_TC2_INIT          {}       /* Initialize CSA lists */\n".format(
            origin_data_tc2['__CSA_TC2_INIT']))
        header_file.write("#define __C_TC2_INIT            {}       /* Initialize and clear C variables */\n".format(
            origin_data_tc2['__C_TC2_INIT']))
        header_file.write("#define __USP_TC2_INIT          {}       /* Initialize user stack pointer */\n".format(
            origin_data_tc2['__USP_TC2_INIT']))
        header_file.write("#define __ISP_TC2_INIT          {}       /* Initialize interrupt stack pointer */\n".format(
            origin_data_tc2['__ISP_TC2_INIT']))
        header_file.write(
            "#define __A0A1_TC2_INIT         {}       /* Initialize a0 and a1 for _a0/_a1 addressing */\n".format(
                origin_data_tc2['__A0A1_TC2_INIT']))
        header_file.write(
            "#define __A8A9_TC2_INIT         {}       /* Initialize a8 and a9 for _a8/_a9 addressing (OS support) */\n".format(
                origin_data_tc2['__A8A9_TC2_INIT']))
        header_file.write(
            "#define __RM_TC2_INIT           {}       /* Initialize rounding mode */\n".format(
                origin_data_tc2['__RM_TC2_INIT']))
        header_file.write(
            "#define __RM_TC2_VALUE          {}  /* FE_TONEAREST, FE_UPWARD, FE_DOWNWARD or FE_TOWARDZERO */\n".format(
                origin_data_tc2['__RM_TC2_VALUE']))
        header_file.write(
            "#define __CDC_TC2                       {}     /* Call Depth Counter (set PSW.CDC) */\n".format(
                origin_data_tc2['__CDC_TC2']))

        header_file.write(
            "#define __USER_STACK_TC2                {}       /* Use the user stack (clear PSW.IS) */\n".format(
                origin_data_tc2['__USER_STACK_TC2']))
        header_file.write(
            "#define __COMPAT_TC2            {}     /* Compatibility mode */\n".format(
                origin_data_tc2['__COMPAT_TC2']))
        header_file.write(
            "#define __USE_ARGC_ARGV_TC2     {}       /* Enable passing argc/argv to main() */\n".format(
                origin_data_tc2['__USE_ARGC_ARGV_TC2']))
        header_file.write(
            "#define __ARGCV_BUFSIZE_TC2     {}     /* Buffer size for argv */\n".format(
                origin_data_tc2['__ARGCV_BUFSIZE_TC2']))

        header_file.write("\n")
        header_file.write("/* Trap Vectors */\n")
        header_file.write("#define __RESOLVE_TRAP_0_TC2    {}       /* Class 0: MMU */\n".format(
            origin_data_tc2['__RESOLVE_TRAP_0_TC2']))
        header_file.write("#define __RESOLVE_TRAP_1_TC2    {}       /* Class 1: Internal protection */\n".format(
            origin_data_tc2['__RESOLVE_TRAP_1_TC2']))
        header_file.write("#define __RESOLVE_TRAP_2_TC2    {}       /* Class 2: Instruction error */\n".format(
            origin_data_tc2['__RESOLVE_TRAP_2_TC2']))
        header_file.write("#define __RESOLVE_TRAP_3_TC2    {}       /* Class 3: Context management */\n".format(
            origin_data_tc2['__RESOLVE_TRAP_3_TC2']))
        header_file.write(
            "#define __RESOLVE_TRAP_4_TC2    {}       /* Class 4: System bus and peripheral errors */\n".format(
                origin_data_tc2['__RESOLVE_TRAP_4_TC2']))
        header_file.write("#define __RESOLVE_TRAP_5_TC2    {}       /* Class 5: Assertion */\n".format(
            origin_data_tc2['__RESOLVE_TRAP_5_TC2']))
        header_file.write("#define __RESOLVE_TRAP_6_TC2    {}       /* Class 6: System call */\n".format(
            origin_data_tc2['__RESOLVE_TRAP_6_TC2']))
        header_file.write("#define __RESOLVE_TRAP_7_TC2    {}       /* Class 7: Non-maskable interrupt */\n".format(
            origin_data_tc2['__RESOLVE_TRAP_7_TC2']))
        header_file.write("\n")
        header_file.write("#endif /* __NO_CSTART_DEFAULT_CONFIG */\n")
        header_file.write("\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * Control of initialization registers\n")
        header_file.write(" *\n")
        header_file.write(" * The *_VALUE macros define the value of the register\n")
        header_file.write(" * The *_INIT macros must be defined to 0 or 1, specifying whether\n")
        header_file.write(" * or not it will be intialized by the cstart.c code.\n")
        header_file.write(" *\n")
        header_file.write(" * Most registers are not set to be initialized, which means that\n")
        header_file.write(" * the CPU's defaults are used. The bus configuration registers will be\n")
        header_file.write(" * set by running the 'Target Board Configuration' wizard.\n")
        header_file.write(" * The Eclipse environment will automatically apply the CPU default\n")
        header_file.write(" * values to the registers. These defaults are defined in the SFR files\n")
        header_file.write(" * from the include/sfr directory of the product.\n")
        header_file.write(" *\n")
        header_file.write(" */\n")
        header_file.write("#ifndef __NO_CSTART_REGISTER_CONFIG\n")
        header_file.write("\n")
        header_file.write("#define __PCON0_INIT            {}\n".format(origin_data_tc2['__PCON0_INIT']))
        header_file.write("#define __PCON0_VALUE           {}\n".format(origin_data_tc2['__PCON0_VALUE']))
        header_file.write("#define __DCON0_INIT            {}\n".format(origin_data_tc2['__DCON0_INIT']))
        header_file.write("#define __DCON0_VALUE           {}\n".format(origin_data_tc2['__DCON0_VALUE']))
        header_file.write("\n")
        header_file.write("#endif /*__NO_CSTART_REGISTER_CONFIG */\n")
        header_file.write("\n")
        header_file.write("#endif /* PROST_CSTART_TC2_H */\n")
        header_file.write("\n")

    # tc3 header create
    save_file_name = save_file_path + "\\prost_cstart_tc3.h"
    with open(save_file_name, 'wt', encoding='utf-8', newline='') as header_file:
        header_file.write("/**************************************************************************\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  FILE        :  cstart_tc3.h                                           *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  DESCRIPTION :                                                         *\n")
        header_file.write("**      Header file to control the system startup code's general settings *\n")
        header_file.write("**      and register initializations. The cstart__tc3.c file must be part *\n")
        header_file.write("**      of your project to make use of this cstart__tc3.h.                *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**      In the Eclipse environment this file can be modified using the    *\n")
        header_file.write("**      C startup code editor, which provides a GUI to modify the         *\n")
        header_file.write("**      Configuration settings and register initialization.               *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  Copyright 1996-2018 TASKING BV                                        *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**************************************************************************/\n")
        header_file.write("\n")
        header_file.write("#ifndef PROST_CSTART_TC3_H\n")
        header_file.write("#define PROST_CSTART_TC3_H\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * These items are shown in Eclipse on the C Start Configuration page\n")
        header_file.write(" */\n")
        header_file.write("\n")
        header_file.write("#ifndef __NO_CSTART_DEFAULT_CONFIG\n")
        header_file.write("\n")
        header_file.write("/* C Startup settings */\n")
        header_file.write(
            "#define __BIV_TC3_INIT          {}       /* Initialize base address of interrupt vector table */\n".format(
                origin_data_tc3['__BIV_TC3_INIT']))
        header_file.write(
            "#define __BIV_SINGLE_TC3_INIT   {}       /* Initialize single entry interrupt vector table */\n".format(
                origin_data_tc3['__BIV_SINGLE_TC3_INIT']))
        header_file.write(
            "#define __BIV_8BYTE_TC3_INIT    {}       /* Initialize 8 byte spacing interrupt vector table */\n".format(
                origin_data_tc3['__BIV_8BYTE_TC3_INIT']))
        header_file.write(
            "#define __BTV_TC3_INIT          {}       /* Initialize base address of trap vector table */\n".format(
                origin_data_tc3['__BTV_TC3_INIT']))
        header_file.write("#define __CSA_TC3_INIT          {}       /* Initialize CSA lists */\n".format(
            origin_data_tc3['__CSA_TC3_INIT']))
        header_file.write("#define __C_TC3_INIT            {}       /* Initialize and clear C variables */\n".format(
            origin_data_tc3['__C_TC3_INIT']))
        header_file.write("#define __USP_TC3_INIT          {}       /* Initialize user stack pointer */\n".format(
            origin_data_tc3['__USP_TC3_INIT']))
        header_file.write("#define __ISP_TC3_INIT          {}       /* Initialize interrupt stack pointer */\n".format(
            origin_data_tc3['__ISP_TC3_INIT']))
        header_file.write(
            "#define __A0A1_TC3_INIT         {}       /* Initialize a0 and a1 for _a0/_a1 addressing */\n".format(
                origin_data_tc3['__A0A1_TC3_INIT']))
        header_file.write(
            "#define __A8A9_TC3_INIT         {}       /* Initialize a8 and a9 for _a8/_a9 addressing (OS support) */\n".format(
                origin_data_tc3['__A8A9_TC3_INIT']))
        header_file.write(
            "#define __RM_TC3_INIT           {}       /* Initialize rounding mode */\n".format(
                origin_data_tc3['__RM_TC3_INIT']))
        header_file.write(
            "#define __RM_TC3_VALUE          {}  /* FE_TONEAREST, FE_UPWARD, FE_DOWNWARD or FE_TOWARDZERO */\n".format(
                origin_data_tc3['__RM_TC3_VALUE']))
        header_file.write(
            "#define __CDC_TC3                       {}     /* Call Depth Counter (set PSW.CDC) */\n".format(
                origin_data_tc3['__CDC_TC3']))

        header_file.write(
            "#define __USER_STACK_TC3                {}       /* Use the user stack (clear PSW.IS) */\n".format(
                origin_data_tc3['__USER_STACK_TC3']))
        header_file.write(
            "#define __COMPAT_TC3            {}     /* Compatibility mode */\n".format(
                origin_data_tc3['__COMPAT_TC3']))
        header_file.write(
            "#define __USE_ARGC_ARGV_TC3     {}       /* Enable passing argc/argv to main() */\n".format(
                origin_data_tc3['__USE_ARGC_ARGV_TC3']))
        header_file.write(
            "#define __ARGCV_BUFSIZE_TC3     {}     /* Buffer size for argv */\n".format(
                origin_data_tc3['__ARGCV_BUFSIZE_TC3']))

        header_file.write("\n")
        header_file.write("/* Trap Vectors */\n")
        header_file.write("#define __RESOLVE_TRAP_0_TC3    {}       /* Class 0: MMU */\n".format(
            origin_data_tc3['__RESOLVE_TRAP_0_TC3']))
        header_file.write("#define __RESOLVE_TRAP_1_TC3    {}       /* Class 1: Internal protection */\n".format(
            origin_data_tc3['__RESOLVE_TRAP_1_TC3']))
        header_file.write("#define __RESOLVE_TRAP_2_TC3    {}       /* Class 2: Instruction error */\n".format(
            origin_data_tc3['__RESOLVE_TRAP_2_TC3']))
        header_file.write("#define __RESOLVE_TRAP_3_TC3    {}       /* Class 3: Context management */\n".format(
            origin_data_tc3['__RESOLVE_TRAP_3_TC3']))
        header_file.write(
            "#define __RESOLVE_TRAP_4_TC3    {}       /* Class 4: System bus and peripheral errors */\n".format(
                origin_data_tc3['__RESOLVE_TRAP_4_TC3']))
        header_file.write("#define __RESOLVE_TRAP_5_TC3    {}       /* Class 5: Assertion */\n".format(
            origin_data_tc3['__RESOLVE_TRAP_5_TC3']))
        header_file.write("#define __RESOLVE_TRAP_6_TC3    {}       /* Class 6: System call */\n".format(
            origin_data_tc3['__RESOLVE_TRAP_6_TC3']))
        header_file.write("#define __RESOLVE_TRAP_7_TC3    {}       /* Class 7: Non-maskable interrupt */\n".format(
            origin_data_tc3['__RESOLVE_TRAP_7_TC3']))
        header_file.write("\n")
        header_file.write("#endif /* __NO_CSTART_DEFAULT_CONFIG */\n")
        header_file.write("\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * Control of initialization registers\n")
        header_file.write(" *\n")
        header_file.write(" * The *_VALUE macros define the value of the register\n")
        header_file.write(" * The *_INIT macros must be defined to 0 or 1, specifying whether\n")
        header_file.write(" * or not it will be intialized by the cstart.c code.\n")
        header_file.write(" *\n")
        header_file.write(" * Most registers are not set to be initialized, which means that\n")
        header_file.write(" * the CPU's defaults are used. The bus configuration registers will be\n")
        header_file.write(" * set by running the 'Target Board Configuration' wizard.\n")
        header_file.write(" * The Eclipse environment will automatically apply the CPU default\n")
        header_file.write(" * values to the registers. These defaults are defined in the SFR files\n")
        header_file.write(" * from the include/sfr directory of the product.\n")
        header_file.write(" *\n")
        header_file.write(" */\n")
        header_file.write("#ifndef __NO_CSTART_REGISTER_CONFIG\n")
        header_file.write("\n")
        header_file.write("#define __PCON0_INIT            {}\n".format(origin_data_tc3['__PCON0_INIT']))
        header_file.write("#define __PCON0_VALUE           {}\n".format(origin_data_tc3['__PCON0_VALUE']))
        header_file.write("#define __DCON0_INIT            {}\n".format(origin_data_tc3['__DCON0_INIT']))
        header_file.write("#define __DCON0_VALUE           {}\n".format(origin_data_tc3['__DCON0_VALUE']))
        header_file.write("\n")
        header_file.write("#endif /*__NO_CSTART_REGISTER_CONFIG */\n")
        header_file.write("\n")
        header_file.write("#endif /* PROST_CSTART_TC3_H */\n")
        header_file.write("\n")
# skc 220210

def tasking_v62_tc39x_h_default(dic_project_info):
    # tc0 header
    origin_data_tc['__BIV_INIT'] = "0x1"
    origin_data_tc['__BIV_SINGLE_INIT'] = "0x0"
    origin_data_tc['__BIV_8BYTE_INIT'] = "0x0"
    origin_data_tc['__BTV_INIT'] = "0x1"
    origin_data_tc['__CSA_INIT'] = "0x1"
    origin_data_tc['__C_INIT'] = "0x1"
    origin_data_tc['__USP_INIT'] = "0x1"
    origin_data_tc['__ISP_INIT'] = "0x1"
    origin_data_tc['__A0A1_INIT'] = "0x1"
    origin_data_tc['__A8A9_INIT'] = "0x1"
    origin_data_tc['__RM_INIT'] = "0x0"
    origin_data_tc['__RM_VALUE'] = "FE_TONEAREST"
    origin_data_tc['__CDC'] = "0x0"
    origin_data_tc['__USER_STACK'] = "0x1"
    origin_data_tc['__WATCHDOG_DISABLE'] = "0x1"
    origin_data_tc['__SAFETY_WATCHDOG_DISABLE'] = "0x1"
    origin_data_tc['__COMPAT'] = "0xf"
    origin_data_tc['__USE_ARGC_ARGV'] = "0x0"
    origin_data_tc['__ARGCV_BUFSIZE'] = "0x100"
    origin_data_tc['__CLOCKS_PER_SEC_INIT'] = "0x0"
    origin_data_tc['__fOSC'] = dic_project_info['Test_Env']['CPU_Clock']
    origin_data_tc['__PLL_K2_RAMPUP'] = "0x0"
    origin_data_tc['__START_INIT_TC1'] = "0x1"
    origin_data_tc['__START_INIT_TC2'] = "0x1"
    origin_data_tc['__START_INIT_TC3'] = "0x1"
    origin_data_tc['__START_INIT_TC4'] = "0x1"
    origin_data_tc['__START_INIT_TC5'] = "0x1"

    origin_data_tc['__RESOLVE_TRAP_0'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_1'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_2'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_3'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_4'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_5'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_6'] = "0x1"
    origin_data_tc['__RESOLVE_TRAP_7'] = "0x1"
    origin_data_tc['__XC800_INIT'] = "0x0"
    origin_data_tc['__EBU_BOOTCFG_INIT'] = "0x1"
    origin_data_tc['__EBU_BOOTCFG_VALUE'] = "0x800C"
    origin_data_tc['__PMI_CON0_INIT'] = "0x1"
    origin_data_tc['__PMI_CON0_VALUE'] = "0x0"
    origin_data_tc['__PMI_CON1_INIT'] = "0x0"
    origin_data_tc['__PMI_CON1_VALUE'] = "0x0"
    origin_data_tc['__PMI_CON2_INIT'] = "0x1"
    origin_data_tc['__PMI_CON2_VALUE'] = "0x0"
    origin_data_tc['__PMU_EIFCON_INIT'] = "0x0"
    origin_data_tc['__PMU_EIFCON_VALUE'] = "0x0"
    origin_data_tc['__DMI_CON_INIT'] = "0x1"
    origin_data_tc['__DMI_CON_VALUE'] = "0x0"
    origin_data_tc['__PLL_CLC_INIT'] = "0x0"
    origin_data_tc['__PLL_CLC_VALUE'] = "0x0"
    origin_data_tc['__SCU_PLLCON0_INIT'] = "0x0"
    origin_data_tc['__SCU_PLLCON0_VALUE'] = "0x00000000"
    origin_data_tc['__SCU_SYSPLLCON0_INIT'] = "0x0"
    origin_data_tc['__SCU_SYSPLLCON0_VALUE'] = "0x40003a00"
    origin_data_tc['__SCU_PLLCON1_INIT'] = "0x0"
    origin_data_tc['__SCU_PLLCON1_VALUE'] = "0x00000000"
    origin_data_tc['__SCU_SYSPLLCON1_INIT'] = "0x00000000"
    origin_data_tc['__SCU_SYSPLLCON1_VALUE'] = "0x00000005"
    origin_data_tc['__SCU_OSCCON_INIT'] = "0x0"
    origin_data_tc['__SCU_OSCCON_VALUE'] = "0x0000005c"
    origin_data_tc['__SCU_CCUCON0_INIT'] = "0x0"
    origin_data_tc['__SCU_CCUCON0_VALUE'] = "0x03130113"
    origin_data_tc['__SCU_CCUCON1_INIT'] = "0x0"
    origin_data_tc['__SCU_CCUCON1_VALUE'] = "0x10100002"
    origin_data_tc['__SCU_CCUCON2_INIT'] = "0x0"
    origin_data_tc['__SCU_CCUCON2_VALUE'] = "0x00000101"
    origin_data_tc['__STM_CLC_INIT'] = "0x0"
    origin_data_tc['__STM_CLC_VALUE'] = "0x0"
    origin_data_tc['__GTM_CLC_INIT'] = "0x1"
    origin_data_tc['__GTM_CLC_VALUE'] = "0x0"
    origin_data_tc['__FLASH0_FCON_INIT'] = "0x0"
    origin_data_tc['__FLASH0_FCON_VALUE'] = "0x00000000"
    origin_data_tc['__FLASH1_FCON_INIT'] = "0x0"
    origin_data_tc['__FLASH1_FCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL0_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL0_VALUE'] = "0xa0000001"
    origin_data_tc['__EBU_ADDRSEL1_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL1_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL2_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL2_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL3_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL3_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL4_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL4_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL5_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL5_VALUE'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL6_INIT'] = "0x0"
    origin_data_tc['__EBU_ADDRSEL6_VALUE'] = "0x0"
    origin_data_tc['__EBU_BFCON_INIT'] = "0x0"
    origin_data_tc['__EBU_BFCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP0_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP1_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP2_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP3_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP4_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP4_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP5_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP5_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSAP6_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSAP6_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON0_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON1_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON2_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON3_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON4_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON4_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON5_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON5_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSCON6_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSCON6_VALUE'] = "0x0"
    origin_data_tc['__EBU_CLC_INIT'] = "0x0"
    origin_data_tc['__EBU_CLC_VALUE'] = "0x00550000"
    origin_data_tc['__EBU_CON_INIT'] = "0x0"
    origin_data_tc['__EBU_CON_VALUE'] = "0x0"
    origin_data_tc['__EBU_EMUAS_INIT'] = "0x0"
    origin_data_tc['__EBU_EMUAS_VALUE'] = "0x0"
    origin_data_tc['__EBU_EMUBAP_INIT'] = "0x0"
    origin_data_tc['__EBU_EMUBAP_VALUE'] = "0x0"
    origin_data_tc['__EBU_EMUBC_INIT'] = "0x0"
    origin_data_tc['__EBU_EMUBC_VALUE'] = "0x0"
    origin_data_tc['__EBU_EMUCON_INIT'] = "0x0"
    origin_data_tc['__EBU_EMUCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_EMUOVL_INIT'] = "0x0"
    origin_data_tc['__EBU_EMUOVL_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMCON0_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMCON0_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMCON1_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMCON1_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMOD0_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMOD0_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMOD1_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMOD1_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMREF0_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMREF0_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMREF1_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMREF1_VALUE'] = "0x0"
    origin_data_tc['__CBS_MCDBBS_INIT'] = "0x0"
    origin_data_tc['__CBS_MCDBBS_VALUE'] = "0x0"
    origin_data_tc['__SBCU_CON_INIT'] = "0x0"
    origin_data_tc['__SBCU_CON_VALUE'] = "0xff09ffff"
    origin_data_tc['__EBU_BUSRAP1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRAP1_VALUE'] = "0xffffffff"
    origin_data_tc['__EBU_BUSRAP0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRAP0_VALUE'] = "0xffffffff"
    origin_data_tc['__EBU_BUSRAP2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRAP2_VALUE'] = "0xffffffff"
    origin_data_tc['__EBU_BUSRAP3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRAP3_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSRCON0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRCON0_VALUE'] = "0x00d30040"
    origin_data_tc['__EBU_BUSRCON1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRCON1_VALUE'] = "0x00d30040"
    origin_data_tc['__EBU_BUSRCON2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRCON2_VALUE'] = "0x00d30040"
    origin_data_tc['__EBU_BUSRCON3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSRCON3_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSWAP0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWAP0_VALUE'] = "0xffffffff"
    origin_data_tc['__EBU_BUSWAP1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWAP1_VALUE'] = "0xffffffff"
    origin_data_tc['__EBU_BUSWAP2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWAP2_VALUE'] = "0xffffffff"
    origin_data_tc['__EBU_BUSWAP3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWAP3_VALUE'] = "0x0"
    origin_data_tc['__EBU_BUSWCON0_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWCON0_VALUE'] = "0x00d30000"
    origin_data_tc['__EBU_BUSWCON1_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWCON1_VALUE'] = "0x00d30000"
    origin_data_tc['__EBU_BUSWCON2_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWCON2_VALUE'] = "0x00d30000"
    origin_data_tc['__EBU_BUSWCON3_INIT'] = "0x0"
    origin_data_tc['__EBU_BUSWCON3_VALUE'] = "0x0"
    origin_data_tc['__EBU_EXTBOOT_INIT'] = "0x0"
    origin_data_tc['__EBU_EXTBOOT_VALUE'] = "0x00000001"
    origin_data_tc['__EBU_MODCON_INIT'] = "0x0"
    origin_data_tc['__EBU_MODCON_VALUE'] = "0x00000020"
    origin_data_tc['__EBU_DDRNCON_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNMOD_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNMOD_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNMOD2_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNMOD2_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNPRLD_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNPRLD_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG0_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG0_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG1_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG1_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG2_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG2_VALUE'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG3_INIT'] = "0x0"
    origin_data_tc['__EBU_DDRNTAG3_VALUE'] = "0x0"
    origin_data_tc['__EBU_DLLCON_INIT'] = "0x0"
    origin_data_tc['__EBU_DLLCON_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRMCON_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMCON_VALUE'] = "0x10000000"
    origin_data_tc['__EBU_SDRMOD_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMOD_VALUE'] = "0x00000020"
    origin_data_tc['__EBU_SDRMREF_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRMREF_VALUE'] = "0x0"
    origin_data_tc['__EBU_SDRSTAT_INIT'] = "0x0"
    origin_data_tc['__EBU_SDRSTAT_VALUE'] = "0x0"
    origin_data_tc['__P24_PDR0_INIT'] = "0x0"
    origin_data_tc['__P24_PDR0_VALUE'] = "0x33333333"
    origin_data_tc['__P24_PDR1_INIT'] = "0x0"
    origin_data_tc['__P24_PDR1_VALUE'] = "0x33333333"
    origin_data_tc['__P25_PDR0_INIT'] = "0x0"
    origin_data_tc['__P25_PDR0_VALUE'] = "0x33333333"
    origin_data_tc['__P25_PDR1_INIT'] = "0x0"
    origin_data_tc['__P25_PDR1_VALUE'] = "0x33333333"
    origin_data_tc['__P30_PDR0_INIT'] = "0x0"
    origin_data_tc['__P30_PDR0_VALUE'] = "0x33333333"
    origin_data_tc['__P30_PDR1_INIT'] = "0x0"
    origin_data_tc['__P30_PDR1_VALUE'] = "0x33333333"
    origin_data_tc['__P31_PDR0_INIT'] = "0x0"
    origin_data_tc['__P31_PDR0_VALUE'] = "0x33333333"
    origin_data_tc['__P31_PDR1_INIT'] = "0x0"
    origin_data_tc['__P31_PDR1_VALUE'] = "0x33333333"
    origin_data_tc['__PCON0_INIT'] = dic_project_info['Test_Env']['Pcache']
    origin_data_tc['__PCON0_VALUE'] = "0x0"
    origin_data_tc['__DCON0_INIT'] = dic_project_info['Test_Env']['Dcache']
    origin_data_tc['__DCON0_VALUE'] = "0x0"

    #tc1 header
    origin_data_tc1['__BIV_TC1_INIT'] = "0x1"
    origin_data_tc1['__BIV_SINGLE_TC1_INIT'] = "0x0"
    origin_data_tc1['__BIV_8BYTE_TC1_INIT'] = "0x0"
    origin_data_tc1['__BTV_TC1_INIT'] = "0x1"
    origin_data_tc1['__CSA_TC1_INIT'] = "0x1"
    origin_data_tc1['__C_TC1_INIT'] = "0x1"
    origin_data_tc1['__USP_TC1_INIT'] = "0x1"
    origin_data_tc1['__ISP_TC1_INIT'] = "0x1"
    origin_data_tc1['__A0A1_TC1_INIT'] = "0x1"
    origin_data_tc1['__A8A9_TC1_INIT'] = "0x1"
    origin_data_tc1['__RM_TC1_INIT'] = "0x0"
    origin_data_tc1['__RM_TC1_VALUE'] = "FE_TONEAREST"
    origin_data_tc1['__CDC_TC1'] = "0x0"
    origin_data_tc1['__USER_STACK_TC1'] = "0x1"
    origin_data_tc1['__COMPAT_TC1'] = "0xf"
    origin_data_tc1['__USE_ARGC_ARGV_TC1'] = "0x0"
    origin_data_tc1['__ARGCV_BUFSIZE_TC1'] = "0x100"
    origin_data_tc1['__RESOLVE_TRAP_0_TC1'] = "0x1"
    origin_data_tc1['__RESOLVE_TRAP_1_TC1'] = "0x1"
    origin_data_tc1['__RESOLVE_TRAP_2_TC1'] = "0x1"
    origin_data_tc1['__RESOLVE_TRAP_3_TC1'] = "0x1"
    origin_data_tc1['__RESOLVE_TRAP_4_TC1'] = "0x1"
    origin_data_tc1['__RESOLVE_TRAP_5_TC1'] = "0x1"
    origin_data_tc1['__RESOLVE_TRAP_6_TC1'] = "0x1"
    origin_data_tc1['__RESOLVE_TRAP_7_TC1'] = "0x1"
    origin_data_tc1['__PCON0_INIT'] = dic_project_info['Test_Env']['Pcache']
    origin_data_tc1['__PCON0_VALUE'] = "0x0"
    origin_data_tc1['__DCON0_INIT'] = dic_project_info['Test_Env']['Dcache']
    origin_data_tc1['__DCON0_VALUE'] = "0x0"

    # tc2 header
    origin_data_tc2['__BIV_TC2_INIT'] = "0x1"
    origin_data_tc2['__BIV_SINGLE_TC2_INIT'] = "0x0"
    origin_data_tc2['__BIV_8BYTE_TC2_INIT'] = "0x0"
    origin_data_tc2['__BTV_TC2_INIT'] = "0x1"
    origin_data_tc2['__CSA_TC2_INIT'] = "0x1"
    origin_data_tc2['__C_TC2_INIT'] = "0x1"
    origin_data_tc2['__USP_TC2_INIT'] = "0x1"
    origin_data_tc2['__ISP_TC2_INIT'] = "0x1"
    origin_data_tc2['__A0A1_TC2_INIT'] = "0x1"
    origin_data_tc2['__A8A9_TC2_INIT'] = "0x1"
    origin_data_tc2['__RM_TC2_INIT'] = "0x0"
    origin_data_tc2['__RM_TC2_VALUE'] = "FE_TONEAREST"
    origin_data_tc2['__CDC_TC2'] = "0x0"
    origin_data_tc2['__USER_STACK_TC2'] = "0x1"
    origin_data_tc2['__COMPAT_TC2'] = "0xf"
    origin_data_tc2['__USE_ARGC_ARGV_TC2'] = "0x0"
    origin_data_tc2['__ARGCV_BUFSIZE_TC2'] = "0x100"
    origin_data_tc2['__RESOLVE_TRAP_0_TC2'] = "0x1"
    origin_data_tc2['__RESOLVE_TRAP_1_TC2'] = "0x1"
    origin_data_tc2['__RESOLVE_TRAP_2_TC2'] = "0x1"
    origin_data_tc2['__RESOLVE_TRAP_3_TC2'] = "0x1"
    origin_data_tc2['__RESOLVE_TRAP_4_TC2'] = "0x1"
    origin_data_tc2['__RESOLVE_TRAP_5_TC2'] = "0x1"
    origin_data_tc2['__RESOLVE_TRAP_6_TC2'] = "0x1"
    origin_data_tc2['__RESOLVE_TRAP_7_TC2'] = "0x1"
    origin_data_tc2['__PCON0_INIT'] = dic_project_info['Test_Env']['Pcache']
    origin_data_tc2['__PCON0_VALUE'] = "0x0"
    origin_data_tc2['__DCON0_INIT'] = dic_project_info['Test_Env']['Dcache']
    origin_data_tc2['__DCON0_VALUE'] = "0x0"

    # tc3 header
    origin_data_tc3['__BIV_TC3_INIT'] = "0x1"
    origin_data_tc3['__BIV_SINGLE_TC3_INIT'] = "0x0"
    origin_data_tc3['__BIV_8BYTE_TC3_INIT'] = "0x0"
    origin_data_tc3['__BTV_TC3_INIT'] = "0x1"
    origin_data_tc3['__CSA_TC3_INIT'] = "0x1"
    origin_data_tc3['__C_TC3_INIT'] = "0x1"
    origin_data_tc3['__USP_TC3_INIT'] = "0x1"
    origin_data_tc3['__ISP_TC3_INIT'] = "0x1"
    origin_data_tc3['__A0A1_TC3_INIT'] = "0x1"
    origin_data_tc3['__A8A9_TC3_INIT'] = "0x1"
    origin_data_tc3['__RM_TC3_INIT'] = "0x0"
    origin_data_tc3['__RM_TC3_VALUE'] = "FE_TONEAREST"
    origin_data_tc3['__CDC_TC3'] = "0x0"
    origin_data_tc3['__USER_STACK_TC3'] = "0x1"
    origin_data_tc3['__COMPAT_TC3'] = "0xf"
    origin_data_tc3['__USE_ARGC_ARGV_TC3'] = "0x0"
    origin_data_tc3['__ARGCV_BUFSIZE_TC3'] = "0x100"
    origin_data_tc3['__RESOLVE_TRAP_0_TC3'] = "0x1"
    origin_data_tc3['__RESOLVE_TRAP_1_TC3'] = "0x1"
    origin_data_tc3['__RESOLVE_TRAP_2_TC3'] = "0x1"
    origin_data_tc3['__RESOLVE_TRAP_3_TC3'] = "0x1"
    origin_data_tc3['__RESOLVE_TRAP_4_TC3'] = "0x1"
    origin_data_tc3['__RESOLVE_TRAP_5_TC3'] = "0x1"
    origin_data_tc3['__RESOLVE_TRAP_6_TC3'] = "0x1"
    origin_data_tc3['__RESOLVE_TRAP_7_TC3'] = "0x1"
    origin_data_tc3['__PCON0_INIT'] = dic_project_info['Test_Env']['Pcache']
    origin_data_tc3['__PCON0_VALUE'] = "0x0"
    origin_data_tc3['__DCON0_INIT'] = dic_project_info['Test_Env']['Dcache']
    origin_data_tc3['__DCON0_VALUE'] = "0x0"

    # tc4 header
    origin_data_tc4['__BIV_TC4_INIT'] = "0x1"
    origin_data_tc4['__BIV_SINGLE_TC4_INIT'] = "0x0"
    origin_data_tc4['__BIV_8BYTE_TC4_INIT'] = "0x0"
    origin_data_tc4['__BTV_TC4_INIT'] = "0x1"
    origin_data_tc4['__CSA_TC4_INIT'] = "0x1"
    origin_data_tc4['__C_TC4_INIT'] = "0x1"
    origin_data_tc4['__USP_TC4_INIT'] = "0x1"
    origin_data_tc4['__ISP_TC4_INIT'] = "0x1"
    origin_data_tc4['__A0A1_TC4_INIT'] = "0x1"
    origin_data_tc4['__A8A9_TC4_INIT'] = "0x1"
    origin_data_tc4['__RM_TC4_INIT'] = "0x0"
    origin_data_tc4['__RM_TC4_VALUE'] = "FE_TONEAREST"
    origin_data_tc4['__CDC_TC4'] = "0x0"
    origin_data_tc4['__USER_STACK_TC4'] = "0x1"
    origin_data_tc4['__COMPAT_TC4'] = "0xf"
    origin_data_tc4['__USE_ARGC_ARGV_TC4'] = "0x0"
    origin_data_tc4['__ARGCV_BUFSIZE_TC4'] = "0x100"
    origin_data_tc4['__RESOLVE_TRAP_0_TC4'] = "0x1"
    origin_data_tc4['__RESOLVE_TRAP_1_TC4'] = "0x1"
    origin_data_tc4['__RESOLVE_TRAP_2_TC4'] = "0x1"
    origin_data_tc4['__RESOLVE_TRAP_3_TC4'] = "0x1"
    origin_data_tc4['__RESOLVE_TRAP_4_TC4'] = "0x1"
    origin_data_tc4['__RESOLVE_TRAP_5_TC4'] = "0x1"
    origin_data_tc4['__RESOLVE_TRAP_6_TC4'] = "0x1"
    origin_data_tc4['__RESOLVE_TRAP_7_TC4'] = "0x1"
    origin_data_tc4['__PCON0_INIT'] = dic_project_info['Test_Env']['Pcache']
    origin_data_tc4['__PCON0_VALUE'] = "0x0"
    origin_data_tc4['__DCON0_INIT'] = dic_project_info['Test_Env']['Dcache']
    origin_data_tc4['__DCON0_VALUE'] = "0x0"

    # tc5 header
    origin_data_tc5['__BIV_TC5_INIT'] = "0x1"
    origin_data_tc5['__BIV_SINGLE_TC5_INIT'] = "0x0"
    origin_data_tc5['__BIV_8BYTE_TC5_INIT'] = "0x0"
    origin_data_tc5['__BTV_TC5_INIT'] = "0x1"
    origin_data_tc5['__CSA_TC5_INIT'] = "0x1"
    origin_data_tc5['__C_TC5_INIT'] = "0x1"
    origin_data_tc5['__USP_TC5_INIT'] = "0x1"
    origin_data_tc5['__ISP_TC5_INIT'] = "0x1"
    origin_data_tc5['__A0A1_TC5_INIT'] = "0x1"
    origin_data_tc5['__A8A9_TC5_INIT'] = "0x1"
    origin_data_tc5['__RM_TC5_INIT'] = "0x0"
    origin_data_tc5['__RM_TC5_VALUE'] = "FE_TONEAREST"
    origin_data_tc5['__CDC_TC5'] = "0x0"
    origin_data_tc5['__USER_STACK_TC5'] = "0x1"
    origin_data_tc5['__COMPAT_TC5'] = "0xf"
    origin_data_tc5['__USE_ARGC_ARGV_TC5'] = "0x0"
    origin_data_tc5['__ARGCV_BUFSIZE_TC5'] = "0x100"
    origin_data_tc5['__RESOLVE_TRAP_0_TC5'] = "0x1"
    origin_data_tc5['__RESOLVE_TRAP_1_TC5'] = "0x1"
    origin_data_tc5['__RESOLVE_TRAP_2_TC5'] = "0x1"
    origin_data_tc5['__RESOLVE_TRAP_3_TC5'] = "0x1"
    origin_data_tc5['__RESOLVE_TRAP_4_TC5'] = "0x1"
    origin_data_tc5['__RESOLVE_TRAP_5_TC5'] = "0x1"
    origin_data_tc5['__RESOLVE_TRAP_6_TC5'] = "0x1"
    origin_data_tc5['__RESOLVE_TRAP_7_TC5'] = "0x1"
    origin_data_tc5['__PCON0_INIT'] = dic_project_info['Test_Env']['Pcache']
    origin_data_tc5['__PCON0_VALUE'] = "0x0"
    origin_data_tc5['__DCON0_INIT'] = dic_project_info['Test_Env']['Dcache']
    origin_data_tc5['__DCON0_VALUE'] = "0x0"

def tasking_v62_tc39x_h_modify_save(save_file_path):
    # tc0 header create
    save_file_name = save_file_path + "\\prost_cstart.h"
    with open(save_file_name, 'wt', encoding='utf-8', newline='') as header_file:
        header_file.write("/**************************************************************************\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  FILE        :  cstart.h                                               *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  DESCRIPTION :                                                         *\n")
        header_file.write("**      Header file to control the system startup code's general settings *\n")
        header_file.write("**      and register initializations. The cstart.c file must be part of   *\n")
        header_file.write("**      your project to make use of this cstart.h.                        *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**      In the Eclipse environment this file can be modified using the    *\n")
        header_file.write("**      C startup code editor, which provides a GUI to modify the         *\n")
        header_file.write("**      Configuration settings and register initialization.               *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  Copyright 1996-2018 TASKING BV                                        *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**************************************************************************/\n")
        header_file.write("\n")
        header_file.write("#ifndef PROST_CSTART_H\n")
        header_file.write("#define PROST_CSTART_H\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * These items are shown on in Eclipse on the C Start Configuration page\n")
        header_file.write(" */\n")
        header_file.write("\n")
        header_file.write("#ifndef __NO_CSTART_DEFAULT_CONFIG\n")
        header_file.write("\n")
        header_file.write("/* C Startup settings */\n")
        header_file.write(
            "#define __BIV_INIT              {}       /* Initialize base address of interrupt vector table */\n".format(
                origin_data_tc['__BIV_INIT']))
        header_file.write(
            "#define __BIV_SINGLE_INIT       {}       /* Initialize single entry interrupt vector table */\n".format(
                origin_data_tc['__BIV_SINGLE_INIT']))
        header_file.write(
            "#define __BIV_8BYTE_INIT        {}       /* Initialize 8 byte spacing interrupt vector table */\n".format(
                origin_data_tc['__BIV_8BYTE_INIT']))
        header_file.write(
            "#define __BTV_INIT              {}       /* Initialize base address of trap vector table */\n".format(
                origin_data_tc['__BTV_INIT']))
        header_file.write(
            "#define __CSA_INIT              {}       /* Initialize CSA lists */\n".format(origin_data_tc['__CSA_INIT']))
        header_file.write("#define __C_INIT                {}       /* Initialize and clear C variables */\n".format(
            origin_data_tc['__C_INIT']))
        header_file.write("#define __USP_INIT              {}       /* Initialize user stack pointer */\n".format(
            origin_data_tc['__USP_INIT']))
        header_file.write("#define __ISP_INIT              {}       /* Initialize interrupt stack pointer */\n".format(
            origin_data_tc['__ISP_INIT']))
        header_file.write(
            "#define __A0A1_INIT             {}       /* Initialize a0 and a1 for _a0/_a1 addressing */\n".format(
                origin_data_tc['__A0A1_INIT']))
        header_file.write(
            "#define __A8A9_INIT             {}       /* Initialize a8 and a9 for _a8/_a9 addressing (OS support) */\n".format(
                origin_data_tc['__A8A9_INIT']))
        header_file.write("#define __RM_INIT               {}       /* Initialize rounding mode */\n".format(
            origin_data_tc['__RM_INIT']))
        header_file.write("#define __RM_VALUE              {}  /* FE_TONEAREST, FE_UPWARD, FE_DOWNWARD or FE_TOWARDZERO */\n".format(
            origin_data_tc['__RM_VALUE']))
        header_file.write(
            "#define __CDC                   {}     /* Call Depth Counter (set PSW.CDC) */\n".format(
                origin_data_tc['__CDC']))
        header_file.write("\n")
        header_file.write("#define __USER_STACK            {}       /* Use the user stack (clear PSW.IS) */\n".format(
            origin_data_tc['__USER_STACK']))
        header_file.write("#define __WATCHDOG_DISABLE      {}       /* Watchdog disable */\n".format(
            origin_data_tc['__WATCHDOG_DISABLE']))
        header_file.write("#define __SAFETY_WATCHDOG_DISABLE {}     /* Safety watchdog disable */\n".format(
            origin_data_tc['__SAFETY_WATCHDOG_DISABLE']))
        header_file.write("#define __COMPAT                {}     /* Compatibility mode */\n".format(
            origin_data_tc['__COMPAT']))
        header_file.write("#define __USE_ARGC_ARGV         {}       /* Enable passing argc/argv to main() */\n".format(
            origin_data_tc['__USE_ARGC_ARGV']))
        header_file.write("#define __ARGCV_BUFSIZE       {}       /* Buffer size for argv */\n".format(
            origin_data_tc['__ARGCV_BUFSIZE']))
        header_file.write("#define __CLOCKS_PER_SEC_INIT   {}       /* Initialize clocks per sec */\n".format(
            origin_data_tc['__CLOCKS_PER_SEC_INIT']))
        header_file.write(
            "#define __fOSC           {}       /* Oscillator frequency Hz */\n".format(origin_data_tc['__fOSC']))
        header_file.write(
            "#define __PLL_K2_RAMPUP         {}       /* PLL K2 rampup */\n".format(origin_data_tc['__PLL_K2_RAMPUP']))
        header_file.write(
            "#define __START_INIT_TC1        {}       /* Start TC1 */\n".format(origin_data_tc['__START_INIT_TC1']))
        header_file.write(
            "#define __START_INIT_TC2        {}       /* Start TC2 */\n".format(origin_data_tc['__START_INIT_TC2']))
        header_file.write(
            "#define __START_INIT_TC3        {}       /* Start TC3 */\n".format(origin_data_tc['__START_INIT_TC3']))
        header_file.write(
            "#define __START_INIT_TC4        {}       /* Start TC4 */\n".format(origin_data_tc['__START_INIT_TC4']))
        header_file.write(
            "#define __START_INIT_TC5        {}       /* Start TC5 */\n".format(origin_data_tc['__START_INIT_TC5']))

        header_file.write("\n")
        header_file.write("/* Trap Vectors */\n")
        header_file.write(
            "#define __RESOLVE_TRAP_0        {}       /* Class 0: MMU */\n".format(origin_data_tc['__RESOLVE_TRAP_0']))
        header_file.write("#define __RESOLVE_TRAP_1        {}       /* Class 1: Internal protection */\n".format(
            origin_data_tc['__RESOLVE_TRAP_1']))
        header_file.write("#define __RESOLVE_TRAP_2        {}       /* Class 2: Instruction error */\n".format(
            origin_data_tc['__RESOLVE_TRAP_2']))
        header_file.write("#define __RESOLVE_TRAP_3        {}       /* Class 3: Context management */\n".format(
            origin_data_tc['__RESOLVE_TRAP_3']))
        header_file.write(
            "#define __RESOLVE_TRAP_4        {}       /* Class 4: System bus and peripheral errors */\n".format(
                origin_data_tc['__RESOLVE_TRAP_4']))
        header_file.write("#define __RESOLVE_TRAP_5        {}       /* Class 5: Assertion */\n".format(
            origin_data_tc['__RESOLVE_TRAP_5']))
        header_file.write("#define __RESOLVE_TRAP_6        {}       /* Class 6: System call */\n".format(
            origin_data_tc['__RESOLVE_TRAP_6']))
        header_file.write("#define __RESOLVE_TRAP_7        {}       /* Class 7: Non-maskable interrupt */\n".format(
            origin_data_tc['__RESOLVE_TRAP_7']))
        header_file.write("#define __XC800_INIT            0       /* Download XC800 image to XRAM */\n".format(
            origin_data_tc['__XC800_INIT']))
        header_file.write("\n")
        header_file.write("\n")
        header_file.write("#endif /* __NO_CSTART_DEFAULT_CONFIG */\n")
        header_file.write("\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * Control of initialization registers\n")
        header_file.write(" *\n")
        header_file.write(" * The *_VALUE macros define the value of the register\n")
        header_file.write(" * The *_INIT macros must be defined to 0 or 1, specifying whether\n")
        header_file.write(" * or not it will be intialized by the cstart.c code.\n")
        header_file.write(" *\n")
        header_file.write(" * Most registers are not set to be initialized, which means that\n")
        header_file.write(" * the CPU's defaults are used. The bus configuration registers will be\n")
        header_file.write(" * set by running the 'Target Board Configuration' wizard.\n")
        header_file.write(" * The Eclipse environment will automatically apply the CPU default\n")
        header_file.write(" * values to the registers. These defaults are defined in the SFR files\n")
        header_file.write(" * from the include/sfr directory of the product.\n")
        header_file.write(" *\n")
        header_file.write(" */\n")
        header_file.write("\n")
        header_file.write("#define __EBU_BOOTCFG_INIT      {}\n".format(origin_data_tc['__EBU_BOOTCFG_INIT']))
        header_file.write("#define __EBU_BOOTCFG_VALUE     {}\n".format(origin_data_tc['__EBU_BOOTCFG_VALUE']))
        header_file.write("\n")
        header_file.write("#ifndef __NO_CSTART_REGISTER_CONFIG\n")
        header_file.write("/* Non-bus configuration: */\n")
        header_file.write("#define __PMI_CON0_INIT         {}\n".format(origin_data_tc['__PMI_CON0_INIT']))
        header_file.write("#define __PMI_CON0_VALUE        {}\n".format(origin_data_tc['__PMI_CON0_VALUE']))
        header_file.write("#define __PMI_CON1_INIT         {}\n".format(origin_data_tc['__PMI_CON1_INIT']))
        header_file.write("#define __PMI_CON1_VALUE        {}\n".format(origin_data_tc['__PMI_CON1_VALUE']))
        header_file.write("#define __PMI_CON2_INIT         {}\n".format(origin_data_tc['__PMI_CON2_INIT']))
        header_file.write("#define __PMI_CON2_VALUE        {}\n".format(origin_data_tc['__PMI_CON2_VALUE']))
        header_file.write("#define __PMU_EIFCON_INIT       {}\n".format(origin_data_tc['__PMU_EIFCON_INIT']))
        header_file.write("#define __PMU_EIFCON_VALUE      {}\n".format(origin_data_tc['__PMU_EIFCON_VALUE']))
        header_file.write("#define __DMI_CON_INIT          {}\n".format(origin_data_tc['__DMI_CON_INIT']))
        header_file.write("#define __DMI_CON_VALUE         {}\n".format(origin_data_tc['__DMI_CON_VALUE']))
        header_file.write("#define __PLL_CLC_INIT          {}\n".format(origin_data_tc['__PLL_CLC_INIT']))
        header_file.write("#define __PLL_CLC_VALUE         {}\n".format(origin_data_tc['__PLL_CLC_VALUE']))
        header_file.write("#define __SCU_PLLCON0_INIT      {}\n".format(origin_data_tc['__SCU_PLLCON0_INIT']))
        header_file.write("#define __SCU_PLLCON0_VALUE     {}\n".format(origin_data_tc['__SCU_PLLCON0_VALUE']))
        header_file.write("#define __SCU_SYSPLLCON0_INIT   {}\n".format(origin_data_tc['__SCU_SYSPLLCON0_INIT']))
        header_file.write("#define __SCU_SYSPLLCON0_VALUE  {}\n".format(origin_data_tc['__SCU_SYSPLLCON0_VALUE']))
        header_file.write("#define __SCU_PLLCON1_INIT      {}\n".format(origin_data_tc['__SCU_PLLCON1_INIT']))
        header_file.write("#define __SCU_PLLCON1_VALUE     {}\n".format(origin_data_tc['__SCU_PLLCON1_VALUE']))
        header_file.write("#define __SCU_SYSPLLCON1_INIT   {}\n".format(origin_data_tc['__SCU_SYSPLLCON1_INIT']))
        header_file.write("#define __SCU_SYSPLLCON1_VALUE  {}\n".format(origin_data_tc['__SCU_SYSPLLCON1_VALUE']))
        header_file.write("#define __SCU_OSCCON_INIT       {}\n".format(origin_data_tc['__SCU_OSCCON_INIT']))
        header_file.write("#define __SCU_OSCCON_VALUE      {}\n".format(origin_data_tc['__SCU_OSCCON_VALUE']))
        header_file.write("#define __SCU_CCUCON0_INIT      {}\n".format(origin_data_tc['__SCU_CCUCON0_INIT']))
        header_file.write("#define __SCU_CCUCON0_VALUE     {}\n".format(origin_data_tc['__SCU_CCUCON0_VALUE']))
        header_file.write("#define __SCU_CCUCON1_INIT      {}\n".format(origin_data_tc['__SCU_CCUCON1_INIT']))
        header_file.write("#define __SCU_CCUCON1_VALUE     {}\n".format(origin_data_tc['__SCU_CCUCON1_VALUE']))
        header_file.write("#define __SCU_CCUCON2_INIT      {}\n".format(origin_data_tc['__SCU_CCUCON2_INIT']))
        header_file.write("#define __SCU_CCUCON2_VALUE     {}\n".format(origin_data_tc['__SCU_CCUCON2_VALUE']))
        header_file.write("#define __STM_CLC_INIT          {}\n".format(origin_data_tc['__STM_CLC_INIT']))
        header_file.write("#define __STM_CLC_VALUE         {}\n".format(origin_data_tc['__STM_CLC_VALUE']))
        header_file.write("#define __GTM_CLC_INIT          {}\n".format(origin_data_tc['__GTM_CLC_INIT']))
        header_file.write("#define __GTM_CLC_VALUE         {}\n".format(origin_data_tc['__GTM_CLC_VALUE']))
        header_file.write("#define __FLASH0_FCON_INIT      {}\n".format(origin_data_tc['__FLASH0_FCON_INIT']))
        header_file.write("#define __FLASH0_FCON_VALUE     {}\n".format(origin_data_tc['__FLASH0_FCON_VALUE']))
        header_file.write("#define __FLASH1_FCON_INIT      {}\n".format(origin_data_tc['__FLASH1_FCON_INIT']))
        header_file.write("#define __FLASH1_FCON_VALUE     {}\n".format(origin_data_tc['__FLASH1_FCON_VALUE']))
        header_file.write("/* Bus configuration: (set by 'Target Board Configuration' wizard) */\n")
        header_file.write("#define __EBU_ADDRSEL0_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL0_INIT']))
        header_file.write("#define __EBU_ADDRSEL0_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL0_VALUE']))
        header_file.write("#define __EBU_ADDRSEL1_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL1_INIT']))
        header_file.write("#define __EBU_ADDRSEL1_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL1_VALUE']))
        header_file.write("#define __EBU_ADDRSEL2_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL2_INIT']))
        header_file.write("#define __EBU_ADDRSEL2_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL2_VALUE']))
        header_file.write("#define __EBU_ADDRSEL3_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL3_INIT']))
        header_file.write("#define __EBU_ADDRSEL3_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL3_VALUE']))
        header_file.write("#define __EBU_ADDRSEL4_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL4_INIT']))
        header_file.write("#define __EBU_ADDRSEL4_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL4_VALUE']))
        header_file.write("#define __EBU_ADDRSEL5_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL5_INIT']))
        header_file.write("#define __EBU_ADDRSEL5_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL5_VALUE']))
        header_file.write("#define __EBU_ADDRSEL6_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL6_INIT']))
        header_file.write("#define __EBU_ADDRSEL6_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL6_VALUE']))
        header_file.write("#define __EBU_BFCON_INIT        {}\n".format(origin_data_tc['__EBU_BFCON_INIT']))
        header_file.write("#define __EBU_BFCON_VALUE       {}\n".format(origin_data_tc['__EBU_BFCON_VALUE']))
        header_file.write("#define __EBU_BUSAP0_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP0_INIT']))
        header_file.write("#define __EBU_BUSAP0_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP0_VALUE']))
        header_file.write("#define __EBU_BUSAP1_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP1_INIT']))
        header_file.write("#define __EBU_BUSAP1_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP1_VALUE']))
        header_file.write("#define __EBU_BUSAP2_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP2_INIT']))
        header_file.write("#define __EBU_BUSAP2_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP2_VALUE']))
        header_file.write("#define __EBU_BUSAP3_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP3_INIT']))
        header_file.write("#define __EBU_BUSAP3_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP3_VALUE']))
        header_file.write("#define __EBU_BUSAP4_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP4_INIT']))
        header_file.write("#define __EBU_BUSAP4_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP4_VALUE']))
        header_file.write("#define __EBU_BUSAP5_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP5_INIT']))
        header_file.write("#define __EBU_BUSAP5_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP5_VALUE']))
        header_file.write("#define __EBU_BUSAP6_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP6_INIT']))
        header_file.write("#define __EBU_BUSAP6_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP6_VALUE']))
        header_file.write("#define __EBU_BUSCON0_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON0_INIT']))
        header_file.write("#define __EBU_BUSCON0_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON0_VALUE']))
        header_file.write("#define __EBU_BUSCON1_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON1_INIT']))
        header_file.write("#define __EBU_BUSCON1_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON1_VALUE']))
        header_file.write("#define __EBU_BUSCON2_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON2_INIT']))
        header_file.write("#define __EBU_BUSCON2_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON2_VALUE']))
        header_file.write("#define __EBU_BUSCON3_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON3_INIT']))
        header_file.write("#define __EBU_BUSCON3_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON3_VALUE']))
        header_file.write("#define __EBU_BUSCON4_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON4_INIT']))
        header_file.write("#define __EBU_BUSCON4_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON4_VALUE']))
        header_file.write("#define __EBU_BUSCON5_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON5_INIT']))
        header_file.write("#define __EBU_BUSCON5_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON5_VALUE']))
        header_file.write("#define __EBU_BUSCON6_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON6_INIT']))
        header_file.write("#define __EBU_BUSCON6_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON6_VALUE']))
        header_file.write("#define __EBU_CLC_INIT          {}\n".format(origin_data_tc['__EBU_CLC_INIT']))
        header_file.write("#define __EBU_CLC_VALUE         {}\n".format(origin_data_tc['__EBU_CLC_VALUE']))
        header_file.write("#define __EBU_CON_INIT          {}\n".format(origin_data_tc['__EBU_CON_INIT']))
        header_file.write("#define __EBU_CON_VALUE         {}\n".format(origin_data_tc['__EBU_CON_VALUE']))
        header_file.write("#define __EBU_EMUAS_INIT        {}\n".format(origin_data_tc['__EBU_EMUAS_INIT']))
        header_file.write("#define __EBU_EMUAS_VALUE       {}\n".format(origin_data_tc['__EBU_EMUAS_VALUE']))
        header_file.write("#define __EBU_EMUBAP_INIT       {}\n".format(origin_data_tc['__EBU_EMUBAP_INIT']))
        header_file.write("#define __EBU_EMUBAP_VALUE      {}\n".format(origin_data_tc['__EBU_EMUBAP_VALUE']))
        header_file.write("#define __EBU_EMUBC_INIT        {}\n".format(origin_data_tc['__EBU_EMUBC_INIT']))
        header_file.write("#define __EBU_EMUBC_VALUE       {}\n".format(origin_data_tc['__EBU_EMUBC_VALUE']))
        header_file.write("#define __EBU_EMUCON_INIT       {}\n".format(origin_data_tc['__EBU_EMUCON_INIT']))
        header_file.write("#define __EBU_EMUCON_VALUE      {}\n".format(origin_data_tc['__EBU_EMUCON_VALUE']))
        header_file.write("#define __EBU_EMUOVL_INIT       {}\n".format(origin_data_tc['__EBU_EMUOVL_INIT']))
        header_file.write("#define __EBU_EMUOVL_VALUE      {}\n".format(origin_data_tc['__EBU_EMUOVL_VALUE']))
        header_file.write("#define __EBU_SDRMCON0_INIT     {}\n".format(origin_data_tc['__EBU_SDRMCON0_INIT']))
        header_file.write("#define __EBU_SDRMCON0_VALUE    {}\n".format(origin_data_tc['__EBU_SDRMCON0_VALUE']))
        header_file.write("#define __EBU_SDRMCON1_INIT     {}\n".format(origin_data_tc['__EBU_SDRMCON1_INIT']))
        header_file.write("#define __EBU_SDRMCON1_VALUE    {}\n".format(origin_data_tc['__EBU_SDRMCON1_VALUE']))
        header_file.write("#define __EBU_SDRMOD0_INIT      {}\n".format(origin_data_tc['__EBU_SDRMOD0_INIT']))
        header_file.write("#define __EBU_SDRMOD0_VALUE     {}\n".format(origin_data_tc['__EBU_SDRMOD0_VALUE']))
        header_file.write("#define __EBU_SDRMOD1_INIT      {}\n".format(origin_data_tc['__EBU_SDRMOD1_INIT']))
        header_file.write("#define __EBU_SDRMOD1_VALUE     {}\n".format(origin_data_tc['__EBU_SDRMOD1_VALUE']))
        header_file.write("#define __EBU_SDRMREF0_INIT     {}\n".format(origin_data_tc['__EBU_SDRMREF0_INIT']))
        header_file.write("#define __EBU_SDRMREF0_VALUE    {}\n".format(origin_data_tc['__EBU_SDRMREF0_VALUE']))
        header_file.write("#define __EBU_SDRMREF1_INIT     {}\n".format(origin_data_tc['__EBU_SDRMREF1_INIT']))
        header_file.write("#define __EBU_SDRMREF1_VALUE    {}\n".format(origin_data_tc['__EBU_SDRMREF1_VALUE']))
        header_file.write("#define __CBS_MCDBBS_INIT       {}\n".format(origin_data_tc['__CBS_MCDBBS_INIT']))
        header_file.write("#define __CBS_MCDBBS_VALUE      {}\n".format(origin_data_tc['__CBS_MCDBBS_VALUE']))
        header_file.write("#define __SBCU_CON_INIT         {}\n".format(origin_data_tc['__SBCU_CON_INIT']))
        header_file.write("#define __SBCU_CON_VALUE        {}\n".format(origin_data_tc['__SBCU_CON_VALUE']))
        header_file.write("#define __EBU_BUSRAP1_INIT      {}\n".format(origin_data_tc['__EBU_BUSRAP1_INIT']))
        header_file.write("#define __EBU_BUSRAP1_VALUE     {}\n".format(origin_data_tc['__EBU_BUSRAP1_VALUE']))
        header_file.write("#define __EBU_BUSRAP0_INIT      {}\n".format(origin_data_tc['__EBU_BUSRAP0_INIT']))
        header_file.write("#define __EBU_BUSRAP0_VALUE     {}\n".format(origin_data_tc['__EBU_BUSRAP0_VALUE']))
        header_file.write("#define __EBU_BUSRAP2_INIT      {}\n".format(origin_data_tc['__EBU_BUSRAP2_INIT']))
        header_file.write("#define __EBU_BUSRAP2_VALUE     {}\n".format(origin_data_tc['__EBU_BUSRAP2_VALUE']))
        header_file.write("#define __EBU_BUSRAP3_INIT      {}\n".format(origin_data_tc['__EBU_BUSRAP3_INIT']))
        header_file.write("#define __EBU_BUSRAP3_VALUE     {}\n".format(origin_data_tc['__EBU_BUSRAP3_VALUE']))
        header_file.write("#define __EBU_BUSRCON0_INIT     {}\n".format(origin_data_tc['__EBU_BUSRCON0_INIT']))
        header_file.write("#define __EBU_BUSRCON0_VALUE    {}\n".format(origin_data_tc['__EBU_BUSRCON0_VALUE']))
        header_file.write("#define __EBU_BUSRCON1_INIT     {}\n".format(origin_data_tc['__EBU_BUSRCON1_INIT']))
        header_file.write("#define __EBU_BUSRCON1_VALUE    {}\n".format(origin_data_tc['__EBU_BUSRCON1_VALUE']))
        header_file.write("#define __EBU_BUSRCON2_INIT     {}\n".format(origin_data_tc['__EBU_BUSRCON2_INIT']))
        header_file.write("#define __EBU_BUSRCON2_VALUE    {}\n".format(origin_data_tc['__EBU_BUSRCON2_VALUE']))
        header_file.write("#define __EBU_BUSRCON3_INIT     {}\n".format(origin_data_tc['__EBU_BUSRCON3_INIT']))
        header_file.write("#define __EBU_BUSRCON3_VALUE    {}\n".format(origin_data_tc['__EBU_BUSRCON3_VALUE']))
        header_file.write("#define __EBU_BUSWAP0_INIT      {}\n".format(origin_data_tc['__EBU_BUSWAP0_INIT']))
        header_file.write("#define __EBU_BUSWAP0_VALUE     {}\n".format(origin_data_tc['__EBU_BUSWAP0_VALUE']))
        header_file.write("#define __EBU_BUSWAP1_INIT      {}\n".format(origin_data_tc['__EBU_BUSWAP1_INIT']))
        header_file.write("#define __EBU_BUSWAP1_VALUE     {}\n".format(origin_data_tc['__EBU_BUSWAP1_VALUE']))
        header_file.write("#define __EBU_BUSWAP2_INIT      {}\n".format(origin_data_tc['__EBU_BUSWAP2_INIT']))
        header_file.write("#define __EBU_BUSWAP2_VALUE     {}\n".format(origin_data_tc['__EBU_BUSWAP2_VALUE']))
        header_file.write("#define __EBU_BUSWAP3_INIT      {}\n".format(origin_data_tc['__EBU_BUSWAP3_INIT']))
        header_file.write("#define __EBU_BUSWAP3_VALUE     {}\n".format(origin_data_tc['__EBU_BUSWAP3_VALUE']))
        header_file.write("#define __EBU_BUSWCON0_INIT     {}\n".format(origin_data_tc['__EBU_BUSWCON0_INIT']))
        header_file.write("#define __EBU_BUSWCON0_VALUE    {}\n".format(origin_data_tc['__EBU_BUSWCON0_VALUE']))
        header_file.write("#define __EBU_BUSWCON1_INIT     {}\n".format(origin_data_tc['__EBU_BUSWCON1_INIT']))
        header_file.write("#define __EBU_BUSWCON1_VALUE    {}\n".format(origin_data_tc['__EBU_BUSWCON1_VALUE']))
        header_file.write("#define __EBU_BUSWCON2_INIT     {}\n".format(origin_data_tc['__EBU_BUSWCON2_INIT']))
        header_file.write("#define __EBU_BUSWCON2_VALUE    {}\n".format(origin_data_tc['__EBU_BUSWCON2_VALUE']))
        header_file.write("#define __EBU_BUSWCON3_INIT     {}\n".format(origin_data_tc['__EBU_BUSWCON3_INIT']))
        header_file.write("#define __EBU_BUSWCON3_VALUE    {}\n".format(origin_data_tc['__EBU_BUSWCON3_VALUE']))
        header_file.write("#define __EBU_EXTBOOT_INIT      {}\n".format(origin_data_tc['__EBU_EXTBOOT_INIT']))
        header_file.write("#define __EBU_EXTBOOT_VALUE     {}\n".format(origin_data_tc['__EBU_EXTBOOT_VALUE']))
        header_file.write("#define __EBU_MODCON_INIT       {}\n".format(origin_data_tc['__EBU_MODCON_INIT']))
        header_file.write("#define __EBU_MODCON_VALUE      {}\n".format(origin_data_tc['__EBU_MODCON_VALUE']))
        header_file.write("#define __EBU_DDRNCON_INIT      {}\n".format(origin_data_tc['__EBU_DDRNCON_INIT']))
        header_file.write("#define __EBU_DDRNCON_VALUE     {}\n".format(origin_data_tc['__EBU_DDRNCON_VALUE']))
        header_file.write("#define __EBU_DDRNMOD_INIT      {}\n".format(origin_data_tc['__EBU_DDRNMOD_INIT']))
        header_file.write("#define __EBU_DDRNMOD_VALUE     {}\n".format(origin_data_tc['__EBU_DDRNMOD_VALUE']))
        header_file.write("#define __EBU_DDRNMOD2_INIT     {}\n".format(origin_data_tc['__EBU_DDRNMOD2_INIT']))
        header_file.write("#define __EBU_DDRNMOD2_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNMOD2_VALUE']))
        header_file.write("#define __EBU_DDRNPRLD_INIT     {}\n".format(origin_data_tc['__EBU_DDRNPRLD_INIT']))
        header_file.write("#define __EBU_DDRNPRLD_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNPRLD_VALUE']))
        header_file.write("#define __EBU_DDRNTAG0_INIT     {}\n".format(origin_data_tc['__EBU_DDRNTAG0_INIT']))
        header_file.write("#define __EBU_DDRNTAG0_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNTAG0_VALUE']))
        header_file.write("#define __EBU_DDRNTAG1_INIT     {}\n".format(origin_data_tc['__EBU_DDRNTAG1_INIT']))
        header_file.write("#define __EBU_DDRNTAG1_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNTAG1_VALUE']))
        header_file.write("#define __EBU_DDRNTAG2_INIT     {}\n".format(origin_data_tc['__EBU_DDRNTAG2_INIT']))
        header_file.write("#define __EBU_DDRNTAG2_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNTAG2_VALUE']))
        header_file.write("#define __EBU_DDRNTAG3_INIT     {}\n".format(origin_data_tc['__EBU_DDRNTAG3_INIT']))
        header_file.write("#define __EBU_DDRNTAG3_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNTAG3_VALUE']))
        header_file.write("#define __EBU_DLLCON_INIT       {}\n".format(origin_data_tc['__EBU_DLLCON_INIT']))
        header_file.write("#define __EBU_DLLCON_VALUE      {}\n".format(origin_data_tc['__EBU_DLLCON_VALUE']))
        header_file.write("#define __EBU_SDRMCON_INIT      {}\n".format(origin_data_tc['__EBU_SDRMCON_INIT']))
        header_file.write("#define __EBU_SDRMCON_VALUE     {}\n".format(origin_data_tc['__EBU_SDRMCON_VALUE']))
        header_file.write("#define __EBU_SDRMOD_INIT       {}\n".format(origin_data_tc['__EBU_SDRMOD_INIT']))
        header_file.write("#define __EBU_SDRMOD_VALUE      {}\n".format(origin_data_tc['__EBU_SDRMOD_VALUE']))
        header_file.write("#define __EBU_SDRMREF_INIT      {}\n".format(origin_data_tc['__EBU_SDRMREF_INIT']))
        header_file.write("#define __EBU_SDRMREF_VALUE     {}\n".format(origin_data_tc['__EBU_SDRMREF_VALUE']))
        header_file.write("#define __EBU_SDRSTAT_INIT      {}\n".format(origin_data_tc['__EBU_SDRSTAT_INIT']))
        header_file.write("#define __EBU_SDRSTAT_VALUE     {}\n".format(origin_data_tc['__EBU_SDRSTAT_VALUE']))
        header_file.write("#define __P24_PDR0_INIT     {}\n".format(origin_data_tc['__P24_PDR0_INIT']))
        header_file.write("#define __P24_PDR0_VALUE    {}\n".format(origin_data_tc['__P24_PDR0_VALUE']))
        header_file.write("#define __P24_PDR1_INIT     {}\n".format(origin_data_tc['__P24_PDR1_INIT']))
        header_file.write("#define __P24_PDR1_VALUE    {}\n".format(origin_data_tc['__P24_PDR1_VALUE']))
        header_file.write("#define __P25_PDR0_INIT     {}\n".format(origin_data_tc['__P25_PDR0_INIT']))
        header_file.write("#define __P25_PDR0_VALUE    {}\n".format(origin_data_tc['__P25_PDR0_VALUE']))
        header_file.write("#define __P25_PDR1_INIT     {}\n".format(origin_data_tc['__P25_PDR1_INIT']))
        header_file.write("#define __P25_PDR1_VALUE    {}\n".format(origin_data_tc['__P25_PDR1_VALUE']))
        header_file.write("#define __P30_PDR0_INIT     {}\n".format(origin_data_tc['__P30_PDR0_INIT']))
        header_file.write("#define __P30_PDR0_VALUE    {}\n".format(origin_data_tc['__P30_PDR0_VALUE']))
        header_file.write("#define __P30_PDR1_INIT     {}\n".format(origin_data_tc['__P30_PDR1_INIT']))
        header_file.write("#define __P30_PDR1_VALUE    {}\n".format(origin_data_tc['__P30_PDR1_VALUE']))
        header_file.write("#define __P31_PDR0_INIT     {}\n".format(origin_data_tc['__P31_PDR0_INIT']))
        header_file.write("#define __P31_PDR0_VALUE    {}\n".format(origin_data_tc['__P31_PDR0_VALUE']))
        header_file.write("#define __P31_PDR1_INIT     {}\n".format(origin_data_tc['__P31_PDR1_INIT']))
        header_file.write("#define __P31_PDR1_VALUE    {}\n".format(origin_data_tc['__P31_PDR1_VALUE']))
        header_file.write("#define __PCON0_INIT            {}\n".format(origin_data_tc['__PCON0_INIT']))
        header_file.write("#define __PCON0_VALUE           {}\n".format(origin_data_tc['__PCON0_VALUE']))
        header_file.write("#define __DCON0_INIT            {}\n".format(origin_data_tc['__DCON0_INIT']))
        header_file.write("#define __DCON0_VALUE           {}\n".format(origin_data_tc['__DCON0_VALUE']))
        header_file.write("\n")
        header_file.write("#endif /*__NO_CSTART_REGISTER_CONFIG */\n")
        header_file.write("\n")
        header_file.write("#endif /* PROST_CSTART_H */\n")

    # tc1 header create
    save_file_name = save_file_path + "\\prost_cstart_tc1.h"
    with open(save_file_name, 'wt', encoding='utf-8', newline='') as header_file:
        header_file.write("/**************************************************************************\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  FILE        :  cstart_tc1.h                                           *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  DESCRIPTION :                                                         *\n")
        header_file.write("**      Header file to control the system startup code's general settings *\n")
        header_file.write("**      and register initializations. The cstart__tc1.c file must be part *\n")
        header_file.write("**      of your project to make use of this cstart__tc1.h.                *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**      In the Eclipse environment this file can be modified using the    *\n")
        header_file.write("**      C startup code editor, which provides a GUI to modify the         *\n")
        header_file.write("**      Configuration settings and register initialization.               *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  Copyright 1996-2018 TASKING BV                                        *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**************************************************************************/\n")
        header_file.write("\n")
        header_file.write("#ifndef PROST_CSTART_TC1_H\n")
        header_file.write("#define PROST_CSTART_TC1_H\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * These items are shown in Eclipse on the C Start Configuration page\n")
        header_file.write(" */\n")
        header_file.write("\n")
        header_file.write("#ifndef __NO_CSTART_DEFAULT_CONFIG\n")
        header_file.write("\n")
        header_file.write("/* C Startup settings */\n")
        header_file.write(
            "#define __BIV_TC1_INIT          {}       /* Initialize base address of interrupt vector table */\n".format(
                origin_data_tc1['__BIV_TC1_INIT']))
        header_file.write(
            "#define __BIV_SINGLE_TC1_INIT   {}       /* Initialize single entry interrupt vector table */\n".format(
                origin_data_tc1['__BIV_SINGLE_TC1_INIT']))
        header_file.write(
            "#define __BIV_8BYTE_TC1_INIT    {}       /* Initialize 8 byte spacing interrupt vector table */\n".format(
                origin_data_tc1['__BIV_8BYTE_TC1_INIT']))
        header_file.write(
            "#define __BTV_TC1_INIT          {}       /* Initialize base address of trap vector table */\n".format(
                origin_data_tc1['__BTV_TC1_INIT']))
        header_file.write("#define __CSA_TC1_INIT          {}       /* Initialize CSA lists */\n".format(
            origin_data_tc1['__CSA_TC1_INIT']))
        header_file.write("#define __C_TC1_INIT            {}       /* Initialize and clear C variables */\n".format(
            origin_data_tc1['__C_TC1_INIT']))
        header_file.write("#define __USP_TC1_INIT          {}       /* Initialize user stack pointer */\n".format(
            origin_data_tc1['__USP_TC1_INIT']))
        header_file.write("#define __ISP_TC1_INIT          {}       /* Initialize interrupt stack pointer */\n".format(
            origin_data_tc1['__ISP_TC1_INIT']))
        header_file.write(
            "#define __A0A1_TC1_INIT         {}       /* Initialize a0 and a1 for _a0/_a1 addressing */\n".format(
                origin_data_tc1['__A0A1_TC1_INIT']))
        header_file.write(
            "#define __A8A9_TC1_INIT         {}       /* Initialize a8 and a9 for _a8/_a9 addressing (OS support) */\n".format(
                origin_data_tc1['__A8A9_TC1_INIT']))
        header_file.write(
            "#define __RM_TC1_INIT           {}       /* Initialize rounding mode */\n".format(
                origin_data_tc1['__RM_TC1_INIT']))
        header_file.write(
            "#define __CDC_TC1                       {}     /* Call Depth Counter (set PSW.CDC) */\n".format(
                origin_data_tc1['__CDC_TC1']))
        header_file.write(
            "#define __RM_TC1_VALUE          {}  /* FE_TONEAREST, FE_UPWARD, FE_DOWNWARD or FE_TOWARDZERO */\n".format(
                origin_data_tc1['__RM_TC1_VALUE']))

        header_file.write(
            "#define __USER_STACK_TC1                {}       /* Use the user stack (clear PSW.IS) */\n".format(
                origin_data_tc1['__USER_STACK_TC1']))
        header_file.write(
            "#define __COMPAT_TC1            {}     /* Compatibility mode */\n".format(
                origin_data_tc1['__COMPAT_TC1']))
        header_file.write(
            "#define __USE_ARGC_ARGV_TC1     {}       /* Enable passing argc/argv to main() */\n".format(
                origin_data_tc1['__USE_ARGC_ARGV_TC1']))
        header_file.write(
            "#define __ARGCV_BUFSIZE_TC1     {}     /* Buffer size for argv */\n".format(
                origin_data_tc1['__ARGCV_BUFSIZE_TC1']))
        header_file.write("\n")
        header_file.write("\n")
        header_file.write("/* Trap Vectors */\n")
        header_file.write("#define __RESOLVE_TRAP_0_TC1    {}       /* Class 0: MMU */\n".format(
            origin_data_tc1['__RESOLVE_TRAP_0_TC1']))
        header_file.write("#define __RESOLVE_TRAP_1_TC1    {}       /* Class 1: Internal protection */\n".format(
            origin_data_tc1['__RESOLVE_TRAP_1_TC1']))
        header_file.write("#define __RESOLVE_TRAP_2_TC1    {}       /* Class 2: Instruction error */\n".format(
            origin_data_tc1['__RESOLVE_TRAP_2_TC1']))
        header_file.write("#define __RESOLVE_TRAP_3_TC1    {}       /* Class 3: Context management */\n".format(
            origin_data_tc1['__RESOLVE_TRAP_3_TC1']))
        header_file.write(
            "#define __RESOLVE_TRAP_4_TC1    {}       /* Class 4: System bus and peripheral errors */\n".format(
                origin_data_tc1['__RESOLVE_TRAP_4_TC1']))
        header_file.write("#define __RESOLVE_TRAP_5_TC1    {}       /* Class 5: Assertion */\n".format(
            origin_data_tc1['__RESOLVE_TRAP_5_TC1']))
        header_file.write("#define __RESOLVE_TRAP_6_TC1    {}       /* Class 6: System call */\n".format(
            origin_data_tc1['__RESOLVE_TRAP_6_TC1']))
        header_file.write("#define __RESOLVE_TRAP_7_TC1    {}       /* Class 7: Non-maskable interrupt */\n".format(
            origin_data_tc1['__RESOLVE_TRAP_7_TC1']))
        header_file.write("\n")
        header_file.write("#endif /* __NO_CSTART_DEFAULT_CONFIG */\n")
        header_file.write("\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * Control of initialization registers\n")
        header_file.write(" *\n")
        header_file.write(" * The *_VALUE macros define the value of the register\n")
        header_file.write(" * The *_INIT macros must be defined to 0 or 1, specifying whether\n")
        header_file.write(" * or not it will be intialized by the cstart.c code.\n")
        header_file.write(" *\n")
        header_file.write(" * Most registers are not set to be initialized, which means that\n")
        header_file.write(" * the CPU's defaults are used. The bus configuration registers will be\n")
        header_file.write(" * set by running the 'Target Board Configuration' wizard.\n")
        header_file.write(" * The Eclipse environment will automatically apply the CPU default\n")
        header_file.write(" * values to the registers. These defaults are defined in the SFR files\n")
        header_file.write(" * from the include/sfr directory of the product.\n")
        header_file.write(" *\n")
        header_file.write(" */\n")
        header_file.write("#ifndef __NO_CSTART_REGISTER_CONFIG\n")
        header_file.write("\n")
        header_file.write("#define __PCON0_INIT            {}\n".format(origin_data_tc1['__PCON0_INIT']))
        header_file.write("#define __PCON0_VALUE           {}\n".format(origin_data_tc1['__PCON0_VALUE']))
        header_file.write("#define __DCON0_INIT            {}\n".format(origin_data_tc1['__DCON0_INIT']))
        header_file.write("#define __DCON0_VALUE           {}\n".format(origin_data_tc1['__DCON0_VALUE']))
        header_file.write("\n")
        header_file.write("#endif /*__NO_CSTART_REGISTER_CONFIG */\n")
        header_file.write("\n")
        header_file.write("#endif /* PROST_CSTART_TC1_H */\n")

    # tc2 header create
    save_file_name = save_file_path + "\\prost_cstart_tc2.h"
    with open(save_file_name, 'wt', encoding='utf-8', newline='') as header_file:
        header_file.write("/**************************************************************************\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  FILE        :  cstart_tc2.h                                           *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  DESCRIPTION :                                                         *\n")
        header_file.write("**      Header file to control the system startup code's general settings *\n")
        header_file.write("**      and register initializations. The cstart__tc2.c file must be part *\n")
        header_file.write("**      of your project to make use of this cstart__tc2.h.                *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**      In the Eclipse environment this file can be modified using the    *\n")
        header_file.write("**      C startup code editor, which provides a GUI to modify the         *\n")
        header_file.write("**      Configuration settings and register initialization.               *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  Copyright 1996-2018 TASKING BV                                        *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**************************************************************************/\n")
        header_file.write("\n")
        header_file.write("#ifndef PROST_CSTART_TC2_H\n")
        header_file.write("#define PROST_CSTART_TC2_H\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * These items are shown in Eclipse on the C Start Configuration page\n")
        header_file.write(" */\n")
        header_file.write("\n")
        header_file.write("#ifndef __NO_CSTART_DEFAULT_CONFIG\n")
        header_file.write("\n")
        header_file.write("/* C Startup settings */\n")
        header_file.write(
            "#define __BIV_TC2_INIT          {}       /* Initialize base address of interrupt vector table */\n".format(
                origin_data_tc2['__BIV_TC2_INIT']))
        header_file.write(
            "#define __BIV_SINGLE_TC2_INIT   {}       /* Initialize single entry interrupt vector table */\n".format(
                origin_data_tc2['__BIV_SINGLE_TC2_INIT']))
        header_file.write(
            "#define __BIV_8BYTE_TC2_INIT    {}       /* Initialize 8 byte spacing interrupt vector table */\n".format(
                origin_data_tc2['__BIV_8BYTE_TC2_INIT']))
        header_file.write(
            "#define __BTV_TC2_INIT          {}       /* Initialize base address of trap vector table */\n".format(
                origin_data_tc2['__BTV_TC2_INIT']))
        header_file.write("#define __CSA_TC2_INIT          {}       /* Initialize CSA lists */\n".format(
            origin_data_tc2['__CSA_TC2_INIT']))
        header_file.write("#define __C_TC2_INIT            {}       /* Initialize and clear C variables */\n".format(
            origin_data_tc2['__C_TC2_INIT']))
        header_file.write("#define __USP_TC2_INIT          {}       /* Initialize user stack pointer */\n".format(
            origin_data_tc2['__USP_TC2_INIT']))
        header_file.write("#define __ISP_TC2_INIT          {}       /* Initialize interrupt stack pointer */\n".format(
            origin_data_tc2['__ISP_TC2_INIT']))
        header_file.write(
            "#define __A0A1_TC2_INIT         {}       /* Initialize a0 and a1 for _a0/_a1 addressing */\n".format(
                origin_data_tc2['__A0A1_TC2_INIT']))
        header_file.write(
            "#define __A8A9_TC2_INIT         {}       /* Initialize a8 and a9 for _a8/_a9 addressing (OS support) */\n".format(
                origin_data_tc2['__A8A9_TC2_INIT']))
        header_file.write(
            "#define __RM_TC2_INIT           {}       /* Initialize rounding mode */\n".format(
                origin_data_tc2['__RM_TC2_INIT']))
        header_file.write(
            "#define __RM_TC2_VALUE          {}  /* FE_TONEAREST, FE_UPWARD, FE_DOWNWARD or FE_TOWARDZERO */\n".format(
                origin_data_tc2['__RM_TC2_VALUE']))
        header_file.write(
            "#define __CDC_TC2                       {}     /* Call Depth Counter (set PSW.CDC) */\n".format(
                origin_data_tc2['__CDC_TC2']))

        header_file.write(
            "#define __USER_STACK_TC2                {}       /* Use the user stack (clear PSW.IS) */\n".format(
                origin_data_tc2['__USER_STACK_TC2']))
        header_file.write(
            "#define __COMPAT_TC2            {}     /* Compatibility mode */\n".format(
                origin_data_tc2['__COMPAT_TC2']))
        header_file.write(
            "#define __USE_ARGC_ARGV_TC2     {}       /* Enable passing argc/argv to main() */\n".format(
                origin_data_tc2['__USE_ARGC_ARGV_TC2']))
        header_file.write(
            "#define __ARGCV_BUFSIZE_TC2     {}     /* Buffer size for argv */\n".format(
                origin_data_tc2['__ARGCV_BUFSIZE_TC2']))

        header_file.write("\n")
        header_file.write("/* Trap Vectors */\n")
        header_file.write("#define __RESOLVE_TRAP_0_TC2    {}       /* Class 0: MMU */\n".format(
            origin_data_tc2['__RESOLVE_TRAP_0_TC2']))
        header_file.write("#define __RESOLVE_TRAP_1_TC2    {}       /* Class 1: Internal protection */\n".format(
            origin_data_tc2['__RESOLVE_TRAP_1_TC2']))
        header_file.write("#define __RESOLVE_TRAP_2_TC2    {}       /* Class 2: Instruction error */\n".format(
            origin_data_tc2['__RESOLVE_TRAP_2_TC2']))
        header_file.write("#define __RESOLVE_TRAP_3_TC2    {}       /* Class 3: Context management */\n".format(
            origin_data_tc2['__RESOLVE_TRAP_3_TC2']))
        header_file.write(
            "#define __RESOLVE_TRAP_4_TC2    {}       /* Class 4: System bus and peripheral errors */\n".format(
                origin_data_tc2['__RESOLVE_TRAP_4_TC2']))
        header_file.write("#define __RESOLVE_TRAP_5_TC2    {}       /* Class 5: Assertion */\n".format(
            origin_data_tc2['__RESOLVE_TRAP_5_TC2']))
        header_file.write("#define __RESOLVE_TRAP_6_TC2    {}       /* Class 6: System call */\n".format(
            origin_data_tc2['__RESOLVE_TRAP_6_TC2']))
        header_file.write("#define __RESOLVE_TRAP_7_TC2    {}       /* Class 7: Non-maskable interrupt */\n".format(
            origin_data_tc2['__RESOLVE_TRAP_7_TC2']))
        header_file.write("\n")
        header_file.write("#endif /* __NO_CSTART_DEFAULT_CONFIG */\n")
        header_file.write("\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * Control of initialization registers\n")
        header_file.write(" *\n")
        header_file.write(" * The *_VALUE macros define the value of the register\n")
        header_file.write(" * The *_INIT macros must be defined to 0 or 1, specifying whether\n")
        header_file.write(" * or not it will be intialized by the cstart.c code.\n")
        header_file.write(" *\n")
        header_file.write(" * Most registers are not set to be initialized, which means that\n")
        header_file.write(" * the CPU's defaults are used. The bus configuration registers will be\n")
        header_file.write(" * set by running the 'Target Board Configuration' wizard.\n")
        header_file.write(" * The Eclipse environment will automatically apply the CPU default\n")
        header_file.write(" * values to the registers. These defaults are defined in the SFR files\n")
        header_file.write(" * from the include/sfr directory of the product.\n")
        header_file.write(" *\n")
        header_file.write(" */\n")
        header_file.write("#ifndef __NO_CSTART_REGISTER_CONFIG\n")
        header_file.write("\n")
        header_file.write("#define __PCON0_INIT            {}\n".format(origin_data_tc2['__PCON0_INIT']))
        header_file.write("#define __PCON0_VALUE           {}\n".format(origin_data_tc2['__PCON0_VALUE']))
        header_file.write("#define __DCON0_INIT            {}\n".format(origin_data_tc2['__DCON0_INIT']))
        header_file.write("#define __DCON0_VALUE           {}\n".format(origin_data_tc2['__DCON0_VALUE']))
        header_file.write("\n")
        header_file.write("#endif /*__NO_CSTART_REGISTER_CONFIG */\n")
        header_file.write("\n")
        header_file.write("#endif /* PROST_CSTART_TC2_H */\n")
        header_file.write("\n")

    # tc3 header create
    save_file_name = save_file_path + "\\prost_cstart_tc3.h"
    with open(save_file_name, 'wt', encoding='utf-8', newline='') as header_file:
        header_file.write("/**************************************************************************\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  FILE        :  cstart_tc3.h                                           *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  DESCRIPTION :                                                         *\n")
        header_file.write("**      Header file to control the system startup code's general settings *\n")
        header_file.write("**      and register initializations. The cstart__tc3.c file must be part *\n")
        header_file.write("**      of your project to make use of this cstart__tc3.h.                *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**      In the Eclipse environment this file can be modified using the    *\n")
        header_file.write("**      C startup code editor, which provides a GUI to modify the         *\n")
        header_file.write("**      Configuration settings and register initialization.               *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  Copyright 1996-2018 TASKING BV                                        *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**************************************************************************/\n")
        header_file.write("\n")
        header_file.write("#ifndef PROST_CSTART_TC3_H\n")
        header_file.write("#define PROST_CSTART_TC3_H\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * These items are shown in Eclipse on the C Start Configuration page\n")
        header_file.write(" */\n")
        header_file.write("\n")
        header_file.write("#ifndef __NO_CSTART_DEFAULT_CONFIG\n")
        header_file.write("\n")
        header_file.write("/* C Startup settings */\n")
        header_file.write(
            "#define __BIV_TC3_INIT          {}       /* Initialize base address of interrupt vector table */\n".format(
                origin_data_tc3['__BIV_TC3_INIT']))
        header_file.write(
            "#define __BIV_SINGLE_TC3_INIT   {}       /* Initialize single entry interrupt vector table */\n".format(
                origin_data_tc3['__BIV_SINGLE_TC3_INIT']))
        header_file.write(
            "#define __BIV_8BYTE_TC3_INIT    {}       /* Initialize 8 byte spacing interrupt vector table */\n".format(
                origin_data_tc3['__BIV_8BYTE_TC3_INIT']))
        header_file.write(
            "#define __BTV_TC3_INIT          {}       /* Initialize base address of trap vector table */\n".format(
                origin_data_tc3['__BTV_TC3_INIT']))
        header_file.write("#define __CSA_TC3_INIT          {}       /* Initialize CSA lists */\n".format(
            origin_data_tc3['__CSA_TC3_INIT']))
        header_file.write("#define __C_TC3_INIT            {}       /* Initialize and clear C variables */\n".format(
            origin_data_tc3['__C_TC3_INIT']))
        header_file.write("#define __USP_TC3_INIT          {}       /* Initialize user stack pointer */\n".format(
            origin_data_tc3['__USP_TC3_INIT']))
        header_file.write("#define __ISP_TC3_INIT          {}       /* Initialize interrupt stack pointer */\n".format(
            origin_data_tc3['__ISP_TC3_INIT']))
        header_file.write(
            "#define __A0A1_TC3_INIT         {}       /* Initialize a0 and a1 for _a0/_a1 addressing */\n".format(
                origin_data_tc3['__A0A1_TC3_INIT']))
        header_file.write(
            "#define __A8A9_TC3_INIT         {}       /* Initialize a8 and a9 for _a8/_a9 addressing (OS support) */\n".format(
                origin_data_tc3['__A8A9_TC3_INIT']))
        header_file.write(
            "#define __RM_TC3_INIT           {}       /* Initialize rounding mode */\n".format(
                origin_data_tc3['__RM_TC3_INIT']))
        header_file.write(
            "#define __RM_TC3_VALUE          {}  /* FE_TONEAREST, FE_UPWARD, FE_DOWNWARD or FE_TOWARDZERO */\n".format(
                origin_data_tc3['__RM_TC3_VALUE']))
        header_file.write(
            "#define __CDC_TC3                       {}     /* Call Depth Counter (set PSW.CDC) */\n".format(
                origin_data_tc3['__CDC_TC3']))

        header_file.write(
            "#define __USER_STACK_TC3                {}       /* Use the user stack (clear PSW.IS) */\n".format(
                origin_data_tc3['__USER_STACK_TC3']))
        header_file.write(
            "#define __COMPAT_TC3            {}     /* Compatibility mode */\n".format(
                origin_data_tc3['__COMPAT_TC3']))
        header_file.write(
            "#define __USE_ARGC_ARGV_TC3     {}       /* Enable passing argc/argv to main() */\n".format(
                origin_data_tc3['__USE_ARGC_ARGV_TC3']))
        header_file.write(
            "#define __ARGCV_BUFSIZE_TC3     {}     /* Buffer size for argv */\n".format(
                origin_data_tc3['__ARGCV_BUFSIZE_TC3']))

        header_file.write("\n")
        header_file.write("/* Trap Vectors */\n")
        header_file.write("#define __RESOLVE_TRAP_0_TC3    {}       /* Class 0: MMU */\n".format(
            origin_data_tc3['__RESOLVE_TRAP_0_TC3']))
        header_file.write("#define __RESOLVE_TRAP_1_TC3    {}       /* Class 1: Internal protection */\n".format(
            origin_data_tc3['__RESOLVE_TRAP_1_TC3']))
        header_file.write("#define __RESOLVE_TRAP_2_TC3    {}       /* Class 2: Instruction error */\n".format(
            origin_data_tc3['__RESOLVE_TRAP_2_TC3']))
        header_file.write("#define __RESOLVE_TRAP_3_TC3    {}       /* Class 3: Context management */\n".format(
            origin_data_tc3['__RESOLVE_TRAP_3_TC3']))
        header_file.write(
            "#define __RESOLVE_TRAP_4_TC3    {}       /* Class 4: System bus and peripheral errors */\n".format(
                origin_data_tc3['__RESOLVE_TRAP_4_TC3']))
        header_file.write("#define __RESOLVE_TRAP_5_TC3    {}       /* Class 5: Assertion */\n".format(
            origin_data_tc3['__RESOLVE_TRAP_5_TC3']))
        header_file.write("#define __RESOLVE_TRAP_6_TC3    {}       /* Class 6: System call */\n".format(
            origin_data_tc3['__RESOLVE_TRAP_6_TC3']))
        header_file.write("#define __RESOLVE_TRAP_7_TC3    {}       /* Class 7: Non-maskable interrupt */\n".format(
            origin_data_tc3['__RESOLVE_TRAP_7_TC3']))
        header_file.write("\n")
        header_file.write("#endif /* __NO_CSTART_DEFAULT_CONFIG */\n")
        header_file.write("\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * Control of initialization registers\n")
        header_file.write(" *\n")
        header_file.write(" * The *_VALUE macros define the value of the register\n")
        header_file.write(" * The *_INIT macros must be defined to 0 or 1, specifying whether\n")
        header_file.write(" * or not it will be intialized by the cstart.c code.\n")
        header_file.write(" *\n")
        header_file.write(" * Most registers are not set to be initialized, which means that\n")
        header_file.write(" * the CPU's defaults are used. The bus configuration registers will be\n")
        header_file.write(" * set by running the 'Target Board Configuration' wizard.\n")
        header_file.write(" * The Eclipse environment will automatically apply the CPU default\n")
        header_file.write(" * values to the registers. These defaults are defined in the SFR files\n")
        header_file.write(" * from the include/sfr directory of the product.\n")
        header_file.write(" *\n")
        header_file.write(" */\n")
        header_file.write("#ifndef __NO_CSTART_REGISTER_CONFIG\n")
        header_file.write("\n")
        header_file.write("#define __PCON0_INIT            {}\n".format(origin_data_tc3['__PCON0_INIT']))
        header_file.write("#define __PCON0_VALUE           {}\n".format(origin_data_tc3['__PCON0_VALUE']))
        header_file.write("#define __DCON0_INIT            {}\n".format(origin_data_tc3['__DCON0_INIT']))
        header_file.write("#define __DCON0_VALUE           {}\n".format(origin_data_tc3['__DCON0_VALUE']))
        header_file.write("\n")
        header_file.write("#endif /*__NO_CSTART_REGISTER_CONFIG */\n")
        header_file.write("\n")
        header_file.write("#endif /* PROST_CSTART_TC3_H */\n")
        header_file.write("\n")

    # tc4 header create
    save_file_name = save_file_path + "\\prost_cstart_tc4.h"
    with open(save_file_name, 'wt', encoding='utf-8', newline='') as header_file:
        header_file.write("/**************************************************************************\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  FILE        :  cstart_tc4.h                                           *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  DESCRIPTION :                                                         *\n")
        header_file.write("**      Header file to control the system startup code's general settings *\n")
        header_file.write("**      and register initializations. The cstart__tc4.c file must be part *\n")
        header_file.write("**      of your project to make use of this cstart__tc4.h.                *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**      In the Eclipse environment this file can be modified using the    *\n")
        header_file.write("**      C startup code editor, which provides a GUI to modify the         *\n")
        header_file.write("**      Configuration settings and register initialization.               *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  Copyright 1996-2018 TASKING BV                                        *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**************************************************************************/\n")
        header_file.write("\n")
        header_file.write("#ifndef PROST_CSTART_TC4_H\n")
        header_file.write("#define PROST_CSTART_TC4_H\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * These items are shown in Eclipse on the C Start Configuration page\n")
        header_file.write(" */\n")
        header_file.write("\n")
        header_file.write("#ifndef __NO_CSTART_DEFAULT_CONFIG\n")
        header_file.write("\n")
        header_file.write("/* C Startup settings */\n")
        header_file.write(
            "#define __BIV_TC4_INIT          {}       /* Initialize base address of interrupt vector table */\n".format(
                origin_data_tc4['__BIV_TC4_INIT']))
        header_file.write(
            "#define __BIV_SINGLE_TC4_INIT   {}       /* Initialize single entry interrupt vector table */\n".format(
                origin_data_tc4['__BIV_SINGLE_TC4_INIT']))
        header_file.write(
            "#define __BIV_8BYTE_TC4_INIT    {}       /* Initialize 8 byte spacing interrupt vector table */\n".format(
                origin_data_tc4['__BIV_8BYTE_TC4_INIT']))
        header_file.write(
            "#define __BTV_TC4_INIT          {}       /* Initialize base address of trap vector table */\n".format(
                origin_data_tc4['__BTV_TC4_INIT']))
        header_file.write("#define __CSA_TC4_INIT          {}       /* Initialize CSA lists */\n".format(
            origin_data_tc4['__CSA_TC4_INIT']))
        header_file.write("#define __C_TC4_INIT            {}       /* Initialize and clear C variables */\n".format(
            origin_data_tc4['__C_TC4_INIT']))
        header_file.write("#define __USP_TC4_INIT          {}       /* Initialize user stack pointer */\n".format(
            origin_data_tc4['__USP_TC4_INIT']))
        header_file.write("#define __ISP_TC4_INIT          {}       /* Initialize interrupt stack pointer */\n".format(
            origin_data_tc4['__ISP_TC4_INIT']))
        header_file.write(
            "#define __A0A1_TC4_INIT         {}       /* Initialize a0 and a1 for _a0/_a1 addressing */\n".format(
                origin_data_tc4['__A0A1_TC4_INIT']))
        header_file.write(
            "#define __A8A9_TC4_INIT         {}       /* Initialize a8 and a9 for _a8/_a9 addressing (OS support) */\n".format(
                origin_data_tc4['__A8A9_TC4_INIT']))
        header_file.write(
            "#define __RM_TC4_INIT           {}       /* Initialize rounding mode */\n".format(
                origin_data_tc4['__RM_TC4_INIT']))
        header_file.write(
            "#define __RM_TC4_VALUE          {}  /* FE_TONEAREST, FE_UPWARD, FE_DOWNWARD or FE_TOWARDZERO */\n".format(
                origin_data_tc4['__RM_TC4_VALUE']))
        header_file.write(
            "#define __CDC_TC4                       {}     /* Call Depth Counter (set PSW.CDC) */\n".format(
                origin_data_tc4['__CDC_TC4']))

        header_file.write(
            "#define __USER_STACK_TC4                {}       /* Use the user stack (clear PSW.IS) */\n".format(
                origin_data_tc4['__USER_STACK_TC4']))
        header_file.write(
            "#define __COMPAT_TC4            {}     /* Compatibility mode */\n".format(
                origin_data_tc4['__COMPAT_TC4']))
        header_file.write(
            "#define __USE_ARGC_ARGV_TC4     {}       /* Enable passing argc/argv to main() */\n".format(
                origin_data_tc4['__USE_ARGC_ARGV_TC4']))
        header_file.write(
            "#define __ARGCV_BUFSIZE_TC4     {}     /* Buffer size for argv */\n".format(
                origin_data_tc4['__ARGCV_BUFSIZE_TC4']))

        header_file.write("\n")
        header_file.write("/* Trap Vectors */\n")
        header_file.write("#define __RESOLVE_TRAP_0_TC4    {}       /* Class 0: MMU */\n".format(
            origin_data_tc4['__RESOLVE_TRAP_0_TC4']))
        header_file.write("#define __RESOLVE_TRAP_1_TC4    {}       /* Class 1: Internal protection */\n".format(
            origin_data_tc4['__RESOLVE_TRAP_1_TC4']))
        header_file.write("#define __RESOLVE_TRAP_2_TC4    {}       /* Class 2: Instruction error */\n".format(
            origin_data_tc4['__RESOLVE_TRAP_2_TC4']))
        header_file.write("#define __RESOLVE_TRAP_3_TC4    {}       /* Class 3: Context management */\n".format(
            origin_data_tc4['__RESOLVE_TRAP_3_TC4']))
        header_file.write(
            "#define __RESOLVE_TRAP_4_TC4    {}       /* Class 4: System bus and peripheral errors */\n".format(
                origin_data_tc4['__RESOLVE_TRAP_4_TC4']))
        header_file.write("#define __RESOLVE_TRAP_5_TC4    {}       /* Class 5: Assertion */\n".format(
            origin_data_tc4['__RESOLVE_TRAP_5_TC4']))
        header_file.write("#define __RESOLVE_TRAP_6_TC4    {}       /* Class 6: System call */\n".format(
            origin_data_tc4['__RESOLVE_TRAP_6_TC4']))
        header_file.write("#define __RESOLVE_TRAP_7_TC4    {}       /* Class 7: Non-maskable interrupt */\n".format(
            origin_data_tc4['__RESOLVE_TRAP_7_TC4']))
        header_file.write("\n")
        header_file.write("#endif /* __NO_CSTART_DEFAULT_CONFIG */\n")
        header_file.write("\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * Control of initialization registers\n")
        header_file.write(" *\n")
        header_file.write(" * The *_VALUE macros define the value of the register\n")
        header_file.write(" * The *_INIT macros must be defined to 0 or 1, specifying whether\n")
        header_file.write(" * or not it will be intialized by the cstart.c code.\n")
        header_file.write(" *\n")
        header_file.write(" * Most registers are not set to be initialized, which means that\n")
        header_file.write(" * the CPU's defaults are used. The bus configuration registers will be\n")
        header_file.write(" * set by running the 'Target Board Configuration' wizard.\n")
        header_file.write(" * The Eclipse environment will automatically apply the CPU default\n")
        header_file.write(" * values to the registers. These defaults are defined in the SFR files\n")
        header_file.write(" * from the include/sfr directory of the product.\n")
        header_file.write(" *\n")
        header_file.write(" */\n")
        header_file.write("#ifndef __NO_CSTART_REGISTER_CONFIG\n")
        header_file.write("\n")
        header_file.write("#define __PCON0_INIT            {}\n".format(origin_data_tc4['__PCON0_INIT']))
        header_file.write("#define __PCON0_VALUE           {}\n".format(origin_data_tc4['__PCON0_VALUE']))
        header_file.write("#define __DCON0_INIT            {}\n".format(origin_data_tc4['__DCON0_INIT']))
        header_file.write("#define __DCON0_VALUE           {}\n".format(origin_data_tc4['__DCON0_VALUE']))
        header_file.write("\n")
        header_file.write("#endif /*__NO_CSTART_REGISTER_CONFIG */\n")
        header_file.write("\n")
        header_file.write("#endif /* PROST_CSTART_TC4_H */\n")
        header_file.write("\n")

    # tc5 header create
    save_file_name = save_file_path + "\\prost_cstart_tc5.h"
    with open(save_file_name, 'wt', encoding='utf-8', newline='') as header_file:
        header_file.write("/**************************************************************************\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  FILE        :  cstart_tc5.h                                           *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  DESCRIPTION :                                                         *\n")
        header_file.write("**      Header file to control the system startup code's general settings *\n")
        header_file.write("**      and register initializations. The cstart__tc5.c file must be part *\n")
        header_file.write("**      of your project to make use of this cstart__tc5.h.                *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**      In the Eclipse environment this file can be modified using the    *\n")
        header_file.write("**      C startup code editor, which provides a GUI to modify the         *\n")
        header_file.write("**      Configuration settings and register initialization.               *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  Copyright 1996-2018 TASKING BV                                        *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**************************************************************************/\n")
        header_file.write("\n")
        header_file.write("#ifndef CSTART_TC5_H\n")
        header_file.write("#define CSTART_TC5_H\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * These items are shown in Eclipse on the C Start Configuration page\n")
        header_file.write(" */\n")
        header_file.write("\n")
        header_file.write("#ifndef __NO_CSTART_DEFAULT_CONFIG\n")
        header_file.write("\n")
        header_file.write("/* C Startup settings */\n")
        header_file.write(
            "#define __BIV_TC5_INIT          {}       /* Initialize base address of interrupt vector table */\n".format(
                origin_data_tc5['__BIV_TC5_INIT']))
        header_file.write(
            "#define __BIV_SINGLE_TC5_INIT   {}       /* Initialize single entry interrupt vector table */\n".format(
                origin_data_tc5['__BIV_SINGLE_TC5_INIT']))
        header_file.write(
            "#define __BIV_8BYTE_TC5_INIT    {}       /* Initialize 8 byte spacing interrupt vector table */\n".format(
                origin_data_tc5['__BIV_8BYTE_TC5_INIT']))
        header_file.write(
            "#define __BTV_TC5_INIT          {}       /* Initialize base address of trap vector table */\n".format(
                origin_data_tc5['__BTV_TC5_INIT']))
        header_file.write("#define __CSA_TC5_INIT          {}       /* Initialize CSA lists */\n".format(
            origin_data_tc5['__CSA_TC5_INIT']))
        header_file.write("#define __C_TC5_INIT            {}       /* Initialize and clear C variables */\n".format(
            origin_data_tc5['__C_TC5_INIT']))
        header_file.write("#define __USP_TC5_INIT          {}       /* Initialize user stack pointer */\n".format(
            origin_data_tc5['__USP_TC5_INIT']))
        header_file.write("#define __ISP_TC5_INIT          {}       /* Initialize interrupt stack pointer */\n".format(
            origin_data_tc5['__ISP_TC5_INIT']))
        header_file.write(
            "#define __A0A1_TC5_INIT         {}       /* Initialize a0 and a1 for _a0/_a1 addressing */\n".format(
                origin_data_tc5['__A0A1_TC5_INIT']))
        header_file.write(
            "#define __A8A9_TC5_INIT         {}       /* Initialize a8 and a9 for _a8/_a9 addressing (OS support) */\n".format(
                origin_data_tc5['__A8A9_TC5_INIT']))
        header_file.write(
            "#define __RM_TC5_INIT           {}       /* Initialize rounding mode */\n".format(
                origin_data_tc5['__RM_TC5_INIT']))
        header_file.write(
            "#define __RM_TC5_VALUE          {}  /* FE_TONEAREST, FE_UPWARD, FE_DOWNWARD or FE_TOWARDZERO */\n".format(
                origin_data_tc5['__RM_TC5_VALUE']))
        header_file.write(
            "#define __CDC_TC5                       {}     /* Call Depth Counter (set PSW.CDC) */\n".format(
                origin_data_tc5['__CDC_TC5']))

        header_file.write(
            "#define __USER_STACK_TC5                {}       /* Use the user stack (clear PSW.IS) */\n".format(
                origin_data_tc5['__USER_STACK_TC5']))
        header_file.write(
            "#define __COMPAT_TC5            {}     /* Compatibility mode */\n".format(
                origin_data_tc5['__COMPAT_TC5']))
        header_file.write(
            "#define __USE_ARGC_ARGV_TC5     {}       /* Enable passing argc/argv to main() */\n".format(
                origin_data_tc5['__USE_ARGC_ARGV_TC5']))
        header_file.write(
            "#define __ARGCV_BUFSIZE_TC5     {}     /* Buffer size for argv */\n".format(
                origin_data_tc5['__ARGCV_BUFSIZE_TC5']))

        header_file.write("\n")
        header_file.write("/* Trap Vectors */\n")
        header_file.write("#define __RESOLVE_TRAP_0_TC5    {}       /* Class 0: MMU */\n".format(
            origin_data_tc5['__RESOLVE_TRAP_0_TC5']))
        header_file.write("#define __RESOLVE_TRAP_1_TC5    {}       /* Class 1: Internal protection */\n".format(
            origin_data_tc5['__RESOLVE_TRAP_1_TC5']))
        header_file.write("#define __RESOLVE_TRAP_2_TC5    {}       /* Class 2: Instruction error */\n".format(
            origin_data_tc5['__RESOLVE_TRAP_2_TC5']))
        header_file.write("#define __RESOLVE_TRAP_3_TC5    {}       /* Class 3: Context management */\n".format(
            origin_data_tc5['__RESOLVE_TRAP_3_TC5']))
        header_file.write(
            "#define __RESOLVE_TRAP_4_TC5    {}       /* Class 4: System bus and peripheral errors */\n".format(
                origin_data_tc5['__RESOLVE_TRAP_4_TC5']))
        header_file.write("#define __RESOLVE_TRAP_5_TC5    {}       /* Class 5: Assertion */\n".format(
            origin_data_tc5['__RESOLVE_TRAP_5_TC5']))
        header_file.write("#define __RESOLVE_TRAP_6_TC5    {}       /* Class 6: System call */\n".format(
            origin_data_tc5['__RESOLVE_TRAP_6_TC5']))
        header_file.write("#define __RESOLVE_TRAP_7_TC5    {}       /* Class 7: Non-maskable interrupt */\n".format(
            origin_data_tc5['__RESOLVE_TRAP_7_TC5']))
        header_file.write("\n")
        header_file.write("#endif /* __NO_CSTART_DEFAULT_CONFIG */\n")
        header_file.write("\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * Control of initialization registers\n")
        header_file.write(" *\n")
        header_file.write(" * The *_VALUE macros define the value of the register\n")
        header_file.write(" * The *_INIT macros must be defined to 0 or 1, specifying whether\n")
        header_file.write(" * or not it will be intialized by the cstart.c code.\n")
        header_file.write(" *\n")
        header_file.write(" * Most registers are not set to be initialized, which means that\n")
        header_file.write(" * the CPU's defaults are used. The bus configuration registers will be\n")
        header_file.write(" * set by running the 'Target Board Configuration' wizard.\n")
        header_file.write(" * The Eclipse environment will automatically apply the CPU default\n")
        header_file.write(" * values to the registers. These defaults are defined in the SFR files\n")
        header_file.write(" * from the include/sfr directory of the product.\n")
        header_file.write(" *\n")
        header_file.write(" */\n")
        header_file.write("#ifndef __NO_CSTART_REGISTER_CONFIG\n")
        header_file.write("\n")
        header_file.write("#define __PCON0_INIT            {}\n".format(origin_data_tc5['__PCON0_INIT']))
        header_file.write("#define __PCON0_VALUE           {}\n".format(origin_data_tc5['__PCON0_VALUE']))
        header_file.write("#define __DCON0_INIT            {}\n".format(origin_data_tc5['__DCON0_INIT']))
        header_file.write("#define __DCON0_VALUE           {}\n".format(origin_data_tc5['__DCON0_VALUE']))
        header_file.write("\n")
        header_file.write("#endif /*__NO_CSTART_REGISTER_CONFIG */\n")
        header_file.write("\n")
        header_file.write("#endif /* PROST_CSTART_TC5_H */\n")
        header_file.write("\n")


def tasking_v62(save_file_name):
    with open(save_file_name, 'wt', encoding='utf-8', newline='') as header_file:
        header_file.write("/**************************************************************************\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  FILE        :  cstart.h                                               *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  DESCRIPTION :                                                         *\n")
        header_file.write("**      Header file to control the system startup code's general settings *\n")
        header_file.write("**      and register initializations. The cstart.c file must be part of   *\n")
        header_file.write("**      your project to make use of this cstart.h.                        *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**      In the Eclipse environment this file can be modified using the    *\n")
        header_file.write("**      C startup code editor, which provides a GUI to modify the         *\n")
        header_file.write("**      Configuration settings and register initialization.               *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**  Copyright 1996-2018 TASKING BV                                        *\n")
        header_file.write("**                                                                        *\n")
        header_file.write("**************************************************************************/\n")
        header_file.write("\n")
        header_file.write("#ifndef CSTART_H\n")
        header_file.write("#define CSTART_H\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * These items are shown on in Eclipse on the C Start Configuration page\n")
        header_file.write(" */\n")
        header_file.write("\n")
        header_file.write("#ifndef __NO_CSTART_DEFAULT_CONFIG\n")
        header_file.write("\n")
        header_file.write("/* C Startup settings */\n")
        header_file.write(
            "#define __BIV_INIT              {}       /* Initialize base address of interrupt vector table */\n".format(
                origin_data_tc['__BIV_INIT']))
        header_file.write(
            "#define __BIV_SINGLE_INIT       {}       /* Initialize single entry interrupt vector table */\n".format(
                origin_data_tc['__BIV_SINGLE_INIT']))
        header_file.write(
            "#define __BIV_8BYTE_INIT        {}       /* Initialize 8 byte spacing interrupt vector table */\n".format(
                origin_data_tc['__BIV_8BYTE_INIT']))
        header_file.write(
            "#define __BTV_INIT              {}       /* Initialize base address of trap vector table */\n".format(
                origin_data_tc['__BTV_INIT']))
        header_file.write(
            "#define __CSA_INIT              {}       /* Initialize CSA lists */\n".format(origin_data_tc['__CSA_INIT']))
        header_file.write("#define __C_INIT                {}       /* Initialize and clear C variables */\n".format(
            origin_data_tc['__C_INIT']))
        header_file.write("#define __USP_INIT              {}       /* Initialize user stack pointer */\n".format(
            origin_data_tc['__USP_INIT']))
        header_file.write("#define __ISP_INIT              {}       /* Initialize interrupt stack pointer */\n".format(
            origin_data_tc['__ISP_INIT']))
        header_file.write(
            "#define __A0A1_INIT             {}       /* Initialize a0 and a1 for _a0/_a1 addressing */\n".format(
                origin_data_tc['__A0A1_INIT']))
        header_file.write(
            "#define __A8A9_INIT             {}       /* Initialize a8 and a9 for _a8/_a9 addressing (OS support) */\n".format(
                origin_data_tc['__A8A9_INIT']))
        header_file.write("#define __RM_INIT               {}       /* Initialize rounding mode */\n".format(
            origin_data_tc['__RM_INIT']))
        header_file.write(
            "#define __RM_VALUE              {}  /* FE_TONEAREST, FE_UPWARD, FE_DOWNWARD or FE_TOWARDZERO */\n".format(
                origin_data_tc['__RM_VALUE']))
        header_file.write("\n")
        header_file.write("#define __CDC                   {}     /* Call Depth Counter (set PSW.CDC) */\n".format(
            origin_data_tc['__CDC']))
        header_file.write("#define __USER_STACK            {}       /* Use the user stack (clear PSW.IS) */\n".format(
            origin_data_tc['__USER_STACK']))
        header_file.write("#define __WATCHDOG_DISABLE      {}       /* Watchdog disable */\n".format(
            origin_data_tc['__WATCHDOG_DISABLE']))
        header_file.write("#define __SAFETY_WATCHDOG_DISABLE {}     /* Safety watchdog disable */\n".format(
            origin_data_tc['__SAFETY_WATCHDOG_DISABLE']))
        header_file.write(
            "#define __COMPAT                {}     /* Compatibility mode */\n".format(origin_data_tc['__COMPAT']))
        header_file.write("#define __USE_ARGC_ARGV         {}       /* Enable passing argc/argv to main() */\n".format(
            origin_data_tc['__USE_ARGC_ARGV']))
        header_file.write("#define __ARGCV_BUFSIZE       {}       /* Buffer size for argv */\n".format(
            origin_data_tc['__ARGCV_BUFSIZE']))
        header_file.write("#define __CLOCKS_PER_SEC_INIT   {}       /* Initialize clocks per sec */\n".format(
            origin_data_tc['__CLOCKS_PER_SEC_INIT']))
        header_file.write(
            "#define __fOSC           {}       /* Oscillator frequency Hz */\n".format(origin_data_tc['__fOSC']))
        header_file.write(
            "#define __PLL_K2_RAMPUP         {}       /* PLL K2 rampup */\n".format(origin_data_tc['__PLL_K2_RAMPUP']))
        header_file.write(
            "#define __START_INIT_TC1        {}       /* Start TC1 */\n".format(origin_data_tc['__START_INIT_TC1']))
        header_file.write(
            "#define __START_INIT_TC2        {}       /* Start TC2 */\n".format(origin_data_tc['__START_INIT_TC2']))
        header_file.write(
            "#define __START_INIT_TC3        {}       /* Start TC3 */\n".format(origin_data_tc['__START_INIT_TC3']))
        header_file.write(
            "#define __START_INIT_TC4        {}       /* Start TC4 */\n".format(origin_data_tc['__START_INIT_TC4']))
        header_file.write(
            "#define __START_INIT_TC5        {}       /* Start TC5 */\n".format(origin_data_tc['__START_INIT_TC5']))
        header_file.write("\n")
        header_file.write("/* Trap Vectors */\n")
        header_file.write(
            "#define __RESOLVE_TRAP_0        {}       /* Class 0: MMU */\n".format(origin_data_tc['__RESOLVE_TRAP_0']))
        header_file.write("#define __RESOLVE_TRAP_1        {}       /* Class 1: Internal protection */\n".format(
            origin_data_tc['__RESOLVE_TRAP_1']))
        header_file.write("#define __RESOLVE_TRAP_2        {}       /* Class 2: Instruction error */\n".format(
            origin_data_tc['__RESOLVE_TRAP_2']))
        header_file.write("#define __RESOLVE_TRAP_3        {}       /* Class 3: Context management */\n".format(
            origin_data_tc['__RESOLVE_TRAP_3']))
        header_file.write(
            "#define __RESOLVE_TRAP_4        {}       /* Class 4: System bus and peripheral errors */\n".format(
                origin_data_tc['__RESOLVE_TRAP_4']))
        header_file.write("#define __RESOLVE_TRAP_5        {}       /* Class 5: Assertion */\n".format(
            origin_data_tc['__RESOLVE_TRAP_5']))
        header_file.write("#define __RESOLVE_TRAP_6        {}       /* Class 6: System call */\n".format(
            origin_data_tc['__RESOLVE_TRAP_6']))
        header_file.write("#define __RESOLVE_TRAP_7        {}       /* Class 7: Non-maskable interrupt */\n".format(
            origin_data_tc['__RESOLVE_TRAP_7']))
        header_file.write("\n")
        header_file.write("#define __XC800_INIT            {}       /* Download XC800 image to XRAM */\n".format(
            origin_data_tc['__XC800_INIT']))
        header_file.write("\n")
        header_file.write("#endif /* __NO_CSTART_DEFAULT_CONFIG */\n")
        header_file.write("\n")
        header_file.write("\n")
        header_file.write("/*\n")
        header_file.write(" * Control of initialization registers\n")
        header_file.write(" *\n")
        header_file.write(" * The *_VALUE macros define the value of the register\n")
        header_file.write(" * The *_INIT macros must be defined to 0 or 1, specifying whether\n")
        header_file.write(" * or not it will be intialized by the cstart.c code.\n")
        header_file.write(" *\n")
        header_file.write(" * Most registers are not set to be initialized, which means that\n")
        header_file.write(" * the CPU's defaults are used. The bus configuration registers will be\n")
        header_file.write(" * set by running the 'Target Board Configuration' wizard.\n")
        header_file.write(" * The Eclipse environment will automatically apply the CPU default\n")
        header_file.write(" * values to the registers. These defaults are defined in the SFR files\n")
        header_file.write(" * from the include/sfr directory of the product.\n")
        header_file.write(" *\n")
        header_file.write(" */\n")
        header_file.write("\n")
        header_file.write("#define __EBU_BOOTCFG_INIT      {}\n".format(origin_data_tc['__EBU_BOOTCFG_INIT']))
        header_file.write("#define __EBU_BOOTCFG_VALUE     {}\n".format(origin_data_tc['__EBU_BOOTCFG_VALUE']))
        header_file.write("\n")
        header_file.write("#ifndef __NO_CSTART_REGISTER_CONFIG\n")
        header_file.write("/* Non-bus configuration: */\n")
        header_file.write("#define __PMI_CON0_INIT         {}\n".format(origin_data_tc['__PMI_CON0_INIT']))
        header_file.write("#define __PMI_CON0_VALUE        {}\n".format(origin_data_tc['__PMI_CON0_VALUE']))
        header_file.write("#define __PMI_CON1_INIT         {}\n".format(origin_data_tc['__PMI_CON1_INIT']))
        header_file.write("#define __PMI_CON1_VALUE        {}\n".format(origin_data_tc['__PMI_CON1_VALUE']))
        header_file.write("#define __PMI_CON2_INIT         {}\n".format(origin_data_tc['__PMI_CON2_INIT']))
        header_file.write("#define __PMI_CON2_VALUE        {}\n".format(origin_data_tc['__PMI_CON2_VALUE']))
        header_file.write("#define __PMU_EIFCON_INIT       {}\n".format(origin_data_tc['__PMU_EIFCON_INIT']))
        header_file.write("#define __PMU_EIFCON_VALUE      {}\n".format(origin_data_tc['__PMU_EIFCON_VALUE']))
        header_file.write("#define __DMI_CON_INIT          {}\n".format(origin_data_tc['__DMI_CON_INIT']))
        header_file.write("#define __DMI_CON_VALUE         {}\n".format(origin_data_tc['__DMI_CON_VALUE']))
        header_file.write("#define __PLL_CLC_INIT          {}\n".format(origin_data_tc['__PLL_CLC_INIT']))
        header_file.write("#define __PLL_CLC_VALUE         {}\n".format(origin_data_tc['__PLL_CLC_VALUE']))
        header_file.write("#define __SCU_PLLCON0_INIT      {}\n".format(origin_data_tc['__SCU_PLLCON0_INIT']))
        header_file.write("#define __SCU_PLLCON0_VALUE     {}\n".format(origin_data_tc['__SCU_PLLCON0_VALUE']))
        header_file.write("#define __SCU_SYSPLLCON0_INIT   {}\n".format(origin_data_tc['__SCU_SYSPLLCON0_INIT']))
        header_file.write("#define __SCU_SYSPLLCON0_VALUE  {}\n".format(origin_data_tc['__SCU_SYSPLLCON0_VALUE']))
        header_file.write("#define __SCU_PLLCON1_INIT      {}\n".format(origin_data_tc['__SCU_PLLCON1_INIT']))
        header_file.write("#define __SCU_PLLCON1_VALUE     {}\n".format(origin_data_tc['__SCU_PLLCON1_VALUE']))
        header_file.write("#define __SCU_SYSPLLCON1_INIT   {}\n".format(origin_data_tc['__SCU_SYSPLLCON1_INIT']))
        header_file.write("#define __SCU_SYSPLLCON1_VALUE  {}\n".format(origin_data_tc['__SCU_SYSPLLCON1_VALUE']))
        header_file.write("#define __SCU_OSCCON_INIT       {}\n".format(origin_data_tc['__SCU_OSCCON_INIT']))
        header_file.write("#define __SCU_OSCCON_VALUE      {}\n".format(origin_data_tc['__SCU_OSCCON_VALUE']))
        header_file.write("#define __SCU_CCUCON0_INIT      {}\n".format(origin_data_tc['__SCU_CCUCON0_INIT']))
        header_file.write("#define __SCU_CCUCON0_VALUE     {}\n".format(origin_data_tc['__SCU_CCUCON0_VALUE']))
        header_file.write("#define __SCU_CCUCON1_INIT      {}\n".format(origin_data_tc['__SCU_CCUCON1_INIT']))
        header_file.write("#define __SCU_CCUCON1_VALUE     {}\n".format(origin_data_tc['__SCU_CCUCON1_VALUE']))
        header_file.write("#define __SCU_CCUCON2_INIT      {}\n".format(origin_data_tc['__SCU_CCUCON2_INIT']))
        header_file.write("#define __SCU_CCUCON2_VALUE     {}\n".format(origin_data_tc['__SCU_CCUCON2_VALUE']))
        header_file.write("#define __STM_CLC_INIT          {}\n".format(origin_data_tc['__STM_CLC_INIT']))
        header_file.write("#define __STM_CLC_VALUE         {}\n".format(origin_data_tc['__STM_CLC_VALUE']))
        header_file.write("#define __GTM_CLC_INIT          {}\n".format(origin_data_tc['__GTM_CLC_INIT']))
        header_file.write("#define __GTM_CLC_VALUE         {}\n".format(origin_data_tc['__GTM_CLC_VALUE']))
        header_file.write("#define __FLASH0_FCON_INIT      {}\n".format(origin_data_tc['__FLASH0_FCON_INIT']))
        header_file.write("#define __FLASH0_FCON_VALUE     {}\n".format(origin_data_tc['__FLASH0_FCON_VALUE']))
        header_file.write("#define __FLASH1_FCON_INIT      {}\n".format(origin_data_tc['__FLASH1_FCON_INIT']))
        header_file.write("#define __FLASH1_FCON_VALUE     {}\n".format(origin_data_tc['__FLASH1_FCON_VALUE']))
        header_file.write("/* Bus configuration: (set by 'Target Board Configuration' wizard) */\n")
        header_file.write("#define __EBU_ADDRSEL0_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL0_INIT']))
        header_file.write("#define __EBU_ADDRSEL0_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL0_VALUE']))
        header_file.write("#define __EBU_ADDRSEL1_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL1_INIT']))
        header_file.write("#define __EBU_ADDRSEL1_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL1_VALUE']))
        header_file.write("#define __EBU_ADDRSEL2_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL2_INIT']))
        header_file.write("#define __EBU_ADDRSEL2_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL2_VALUE']))
        header_file.write("#define __EBU_ADDRSEL3_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL3_INIT']))
        header_file.write("#define __EBU_ADDRSEL3_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL3_VALUE']))
        header_file.write("#define __EBU_ADDRSEL4_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL4_INIT']))
        header_file.write("#define __EBU_ADDRSEL4_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL4_VALUE']))
        header_file.write("#define __EBU_ADDRSEL5_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL5_INIT']))
        header_file.write("#define __EBU_ADDRSEL5_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL5_VALUE']))
        header_file.write("#define __EBU_ADDRSEL6_INIT     {}\n".format(origin_data_tc['__EBU_ADDRSEL6_INIT']))
        header_file.write("#define __EBU_ADDRSEL6_VALUE    {}\n".format(origin_data_tc['__EBU_ADDRSEL6_VALUE']))
        header_file.write("#define __EBU_BFCON_INIT        {}\n".format(origin_data_tc['__EBU_BFCON_INIT']))
        header_file.write("#define __EBU_BFCON_VALUE       {}\n".format(origin_data_tc['__EBU_BFCON_VALUE']))
        header_file.write("#define __EBU_BUSAP0_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP0_INIT']))
        header_file.write("#define __EBU_BUSAP0_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP0_VALUE']))
        header_file.write("#define __EBU_BUSAP1_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP1_INIT']))
        header_file.write("#define __EBU_BUSAP1_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP1_VALUE']))
        header_file.write("#define __EBU_BUSAP2_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP2_INIT']))
        header_file.write("#define __EBU_BUSAP2_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP2_VALUE']))
        header_file.write("#define __EBU_BUSAP3_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP3_INIT']))
        header_file.write("#define __EBU_BUSAP3_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP3_VALUE']))
        header_file.write("#define __EBU_BUSAP4_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP4_INIT']))
        header_file.write("#define __EBU_BUSAP4_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP4_VALUE']))
        header_file.write("#define __EBU_BUSAP5_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP5_INIT']))
        header_file.write("#define __EBU_BUSAP5_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP5_VALUE']))
        header_file.write("#define __EBU_BUSAP6_INIT       {}\n".format(origin_data_tc['__EBU_BUSAP6_INIT']))
        header_file.write("#define __EBU_BUSAP6_VALUE      {}\n".format(origin_data_tc['__EBU_BUSAP6_VALUE']))
        header_file.write("#define __EBU_BUSCON0_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON0_INIT']))
        header_file.write("#define __EBU_BUSCON0_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON0_VALUE']))
        header_file.write("#define __EBU_BUSCON1_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON1_INIT']))
        header_file.write("#define __EBU_BUSCON1_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON1_VALUE']))
        header_file.write("#define __EBU_BUSCON2_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON2_INIT']))
        header_file.write("#define __EBU_BUSCON2_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON2_VALUE']))
        header_file.write("#define __EBU_BUSCON3_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON3_INIT']))
        header_file.write("#define __EBU_BUSCON3_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON3_VALUE']))
        header_file.write("#define __EBU_BUSCON4_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON4_INIT']))
        header_file.write("#define __EBU_BUSCON4_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON4_VALUE']))
        header_file.write("#define __EBU_BUSCON5_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON5_INIT']))
        header_file.write("#define __EBU_BUSCON5_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON5_VALUE']))
        header_file.write("#define __EBU_BUSCON6_INIT      {}\n".format(origin_data_tc['__EBU_BUSCON6_INIT']))
        header_file.write("#define __EBU_BUSCON6_VALUE     {}\n".format(origin_data_tc['__EBU_BUSCON6_VALUE']))
        header_file.write("#define __EBU_CLC_INIT          {}\n".format(origin_data_tc['__EBU_CLC_INIT']))
        header_file.write("#define __EBU_CLC_VALUE         {}\n".format(origin_data_tc['__EBU_CLC_VALUE']))
        header_file.write("#define __EBU_CON_INIT          {}\n".format(origin_data_tc['__EBU_CON_INIT']))
        header_file.write("#define __EBU_CON_VALUE         {}\n".format(origin_data_tc['__EBU_CON_VALUE']))
        header_file.write("#define __EBU_EMUAS_INIT        {}\n".format(origin_data_tc['__EBU_EMUAS_INIT']))
        header_file.write("#define __EBU_EMUAS_VALUE       {}\n".format(origin_data_tc['__EBU_EMUAS_VALUE']))
        header_file.write("#define __EBU_EMUBAP_INIT       {}\n".format(origin_data_tc['__EBU_EMUBAP_INIT']))
        header_file.write("#define __EBU_EMUBAP_VALUE      {}\n".format(origin_data_tc['__EBU_EMUBAP_VALUE']))
        header_file.write("#define __EBU_EMUBC_INIT        {}\n".format(origin_data_tc['__EBU_EMUBC_INIT']))
        header_file.write("#define __EBU_EMUBC_VALUE       {}\n".format(origin_data_tc['__EBU_EMUBC_VALUE']))
        header_file.write("#define __EBU_EMUCON_INIT       {}\n".format(origin_data_tc['__EBU_EMUCON_INIT']))
        header_file.write("#define __EBU_EMUCON_VALUE      {}\n".format(origin_data_tc['__EBU_EMUCON_VALUE']))
        header_file.write("#define __EBU_EMUOVL_INIT       {}\n".format(origin_data_tc['__EBU_EMUOVL_INIT']))
        header_file.write("#define __EBU_EMUOVL_VALUE      {}\n".format(origin_data_tc['__EBU_EMUOVL_VALUE']))
        header_file.write("#define __EBU_SDRMCON0_INIT     {}\n".format(origin_data_tc['__EBU_SDRMCON0_INIT']))
        header_file.write("#define __EBU_SDRMCON0_VALUE    {}\n".format(origin_data_tc['__EBU_SDRMCON0_VALUE']))
        header_file.write("#define __EBU_SDRMCON1_INIT     {}\n".format(origin_data_tc['__EBU_SDRMCON1_INIT']))
        header_file.write("#define __EBU_SDRMCON1_VALUE    {}\n".format(origin_data_tc['__EBU_SDRMCON1_VALUE']))
        header_file.write("#define __EBU_SDRMOD0_INIT      {}\n".format(origin_data_tc['__EBU_SDRMOD0_INIT']))
        header_file.write("#define __EBU_SDRMOD0_VALUE     {}\n".format(origin_data_tc['__EBU_SDRMOD0_VALUE']))
        header_file.write("#define __EBU_SDRMOD1_INIT      {}\n".format(origin_data_tc['__EBU_SDRMOD1_INIT']))
        header_file.write("#define __EBU_SDRMOD1_VALUE     {}\n".format(origin_data_tc['__EBU_SDRMOD1_VALUE']))
        header_file.write("#define __EBU_SDRMREF0_INIT     {}\n".format(origin_data_tc['__EBU_SDRMREF0_INIT']))
        header_file.write("#define __EBU_SDRMREF0_VALUE    {}\n".format(origin_data_tc['__EBU_SDRMREF0_VALUE']))
        header_file.write("#define __EBU_SDRMREF1_INIT     {}\n".format(origin_data_tc['__EBU_SDRMREF1_INIT']))
        header_file.write("#define __EBU_SDRMREF1_VALUE    {}\n".format(origin_data_tc['__EBU_SDRMREF1_VALUE']))
        header_file.write("#define __CBS_MCDBBS_INIT       {}\n".format(origin_data_tc['__CBS_MCDBBS_INIT']))
        header_file.write("#define __CBS_MCDBBS_VALUE      {}\n".format(origin_data_tc['__CBS_MCDBBS_VALUE']))
        header_file.write("#define __SBCU_CON_INIT         {}\n".format(origin_data_tc['__SBCU_CON_INIT']))
        header_file.write("#define __SBCU_CON_VALUE        {}\n".format(origin_data_tc['__SBCU_CON_VALUE']))
        header_file.write("#define __EBU_BUSRAP1_INIT      {}\n".format(origin_data_tc['__EBU_BUSRAP1_INIT']))
        header_file.write("#define __EBU_BUSRAP1_VALUE     {}\n".format(origin_data_tc['__EBU_BUSRAP1_VALUE']))
        header_file.write("#define __EBU_BUSRAP0_INIT      {}\n".format(origin_data_tc['__EBU_BUSRAP0_INIT']))
        header_file.write("#define __EBU_BUSRAP0_VALUE     {}\n".format(origin_data_tc['__EBU_BUSRAP0_VALUE']))
        header_file.write("#define __EBU_BUSRAP2_INIT      {}\n".format(origin_data_tc['__EBU_BUSRAP2_INIT']))
        header_file.write("#define __EBU_BUSRAP2_VALUE     {}\n".format(origin_data_tc['__EBU_BUSRAP2_VALUE']))
        header_file.write("#define __EBU_BUSRAP3_INIT      {}\n".format(origin_data_tc['__EBU_BUSRAP3_INIT']))
        header_file.write("#define __EBU_BUSRAP3_VALUE     {}\n".format(origin_data_tc['__EBU_BUSRAP3_VALUE']))
        header_file.write("#define __EBU_BUSRCON0_INIT     {}\n".format(origin_data_tc['__EBU_BUSRCON0_INIT']))
        header_file.write("#define __EBU_BUSRCON0_VALUE    {}\n".format(origin_data_tc['__EBU_BUSRCON0_VALUE']))
        header_file.write("#define __EBU_BUSRCON1_INIT     {}\n".format(origin_data_tc['__EBU_BUSRCON1_INIT']))
        header_file.write("#define __EBU_BUSRCON1_VALUE    {}\n".format(origin_data_tc['__EBU_BUSRCON1_VALUE']))
        header_file.write("#define __EBU_BUSRCON2_INIT     {}\n".format(origin_data_tc['__EBU_BUSRCON2_INIT']))
        header_file.write("#define __EBU_BUSRCON2_VALUE    {}\n".format(origin_data_tc['__EBU_BUSRCON2_VALUE']))
        header_file.write("#define __EBU_BUSRCON3_INIT     {}\n".format(origin_data_tc['__EBU_BUSRCON3_INIT']))
        header_file.write("#define __EBU_BUSRCON3_VALUE    {}\n".format(origin_data_tc['__EBU_BUSRCON3_VALUE']))
        header_file.write("#define __EBU_BUSWAP0_INIT      {}\n".format(origin_data_tc['__EBU_BUSWAP0_INIT']))
        header_file.write("#define __EBU_BUSWAP0_VALUE     {}\n".format(origin_data_tc['__EBU_BUSWAP0_VALUE']))
        header_file.write("#define __EBU_BUSWAP1_INIT      {}\n".format(origin_data_tc['__EBU_BUSWAP1_INIT']))
        header_file.write("#define __EBU_BUSWAP1_VALUE     {}\n".format(origin_data_tc['__EBU_BUSWAP1_VALUE']))
        header_file.write("#define __EBU_BUSWAP2_INIT      {}\n".format(origin_data_tc['__EBU_BUSWAP2_INIT']))
        header_file.write("#define __EBU_BUSWAP2_VALUE     {}\n".format(origin_data_tc['__EBU_BUSWAP2_VALUE']))
        header_file.write("#define __EBU_BUSWAP3_INIT      {}\n".format(origin_data_tc['__EBU_BUSWAP3_INIT']))
        header_file.write("#define __EBU_BUSWAP3_VALUE     {}\n".format(origin_data_tc['__EBU_BUSWAP3_VALUE']))
        header_file.write("#define __EBU_BUSWCON0_INIT     {}\n".format(origin_data_tc['__EBU_BUSWCON0_INIT']))
        header_file.write("#define __EBU_BUSWCON0_VALUE    {}\n".format(origin_data_tc['__EBU_BUSWCON0_VALUE']))
        header_file.write("#define __EBU_BUSWCON1_INIT     {}\n".format(origin_data_tc['__EBU_BUSWCON1_INIT']))
        header_file.write("#define __EBU_BUSWCON1_VALUE    {}\n".format(origin_data_tc['__EBU_BUSWCON1_VALUE']))
        header_file.write("#define __EBU_BUSWCON2_INIT     {}\n".format(origin_data_tc['__EBU_BUSWCON2_INIT']))
        header_file.write("#define __EBU_BUSWCON2_VALUE    {}\n".format(origin_data_tc['__EBU_BUSWCON2_VALUE']))
        header_file.write("#define __EBU_BUSWCON3_INIT     {}\n".format(origin_data_tc['__EBU_BUSWCON3_INIT']))
        header_file.write("#define __EBU_BUSWCON3_VALUE    {}\n".format(origin_data_tc['__EBU_BUSWCON3_VALUE']))
        header_file.write("#define __EBU_EXTBOOT_INIT      {}\n".format(origin_data_tc['__EBU_EXTBOOT_INIT']))
        header_file.write("#define __EBU_EXTBOOT_VALUE     {}\n".format(origin_data_tc['__EBU_EXTBOOT_VALUE']))
        header_file.write("#define __EBU_MODCON_INIT       {}\n".format(origin_data_tc['__EBU_MODCON_INIT']))
        header_file.write("#define __EBU_MODCON_VALUE      {}\n".format(origin_data_tc['__EBU_MODCON_VALUE']))
        header_file.write("#define __EBU_DDRNCON_INIT      {}\n".format(origin_data_tc['__EBU_DDRNCON_INIT']))
        header_file.write("#define __EBU_DDRNCON_VALUE     {}\n".format(origin_data_tc['__EBU_DDRNCON_VALUE']))
        header_file.write("#define __EBU_DDRNMOD_INIT      {}\n".format(origin_data_tc['__EBU_DDRNMOD_INIT']))
        header_file.write("#define __EBU_DDRNMOD_VALUE     {}\n".format(origin_data_tc['__EBU_DDRNMOD_VALUE']))
        header_file.write("#define __EBU_DDRNMOD2_INIT     {}\n".format(origin_data_tc['__EBU_DDRNMOD2_INIT']))
        header_file.write("#define __EBU_DDRNMOD2_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNMOD2_VALUE']))
        header_file.write("#define __EBU_DDRNPRLD_INIT     {}\n".format(origin_data_tc['__EBU_DDRNPRLD_INIT']))
        header_file.write("#define __EBU_DDRNPRLD_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNPRLD_VALUE']))
        header_file.write("#define __EBU_DDRNTAG0_INIT     {}\n".format(origin_data_tc['__EBU_DDRNTAG0_INIT']))
        header_file.write("#define __EBU_DDRNTAG0_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNTAG0_VALUE']))
        header_file.write("#define __EBU_DDRNTAG1_INIT     {}\n".format(origin_data_tc['__EBU_DDRNTAG1_INIT']))
        header_file.write("#define __EBU_DDRNTAG1_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNTAG1_VALUE']))
        header_file.write("#define __EBU_DDRNTAG2_INIT     {}\n".format(origin_data_tc['__EBU_DDRNTAG2_INIT']))
        header_file.write("#define __EBU_DDRNTAG2_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNTAG2_VALUE']))
        header_file.write("#define __EBU_DDRNTAG3_INIT     {}\n".format(origin_data_tc['__EBU_DDRNTAG3_INIT']))
        header_file.write("#define __EBU_DDRNTAG3_VALUE    {}\n".format(origin_data_tc['__EBU_DDRNTAG3_VALUE']))
        header_file.write("#define __EBU_DLLCON_INIT       {}\n".format(origin_data_tc['__EBU_DLLCON_INIT']))
        header_file.write("#define __EBU_DLLCON_VALUE      {}\n".format(origin_data_tc['__EBU_DLLCON_VALUE']))
        header_file.write("#define __EBU_SDRMCON_INIT      {}\n".format(origin_data_tc['__EBU_SDRMCON_INIT']))
        header_file.write("#define __EBU_SDRMCON_VALUE     {}\n".format(origin_data_tc['__EBU_SDRMCON_VALUE']))
        header_file.write("#define __EBU_SDRMOD_INIT       {}\n".format(origin_data_tc['__EBU_SDRMOD_INIT']))
        header_file.write("#define __EBU_SDRMOD_VALUE      {}\n".format(origin_data_tc['__EBU_SDRMOD_VALUE']))
        header_file.write("#define __EBU_SDRMREF_INIT      {}\n".format(origin_data_tc['__EBU_SDRMREF_INIT']))
        header_file.write("#define __EBU_SDRMREF_VALUE     {}\n".format(origin_data_tc['__EBU_SDRMREF_VALUE']))
        header_file.write("#define __EBU_SDRSTAT_INIT      {}\n".format(origin_data_tc['__EBU_SDRSTAT_INIT']))
        header_file.write("#define __EBU_SDRSTAT_VALUE     {}\n".format(origin_data_tc['__EBU_SDRSTAT_VALUE']))
        header_file.write("#define __P24_PDR0_INIT         {}\n".format(origin_data_tc['__P24_PDR0_INIT']))
        header_file.write("#define __P24_PDR0_VALUE        {}\n".format(origin_data_tc['__P24_PDR0_VALUE']))
        header_file.write("#define __P24_PDR1_INIT         {}\n".format(origin_data_tc['__P24_PDR1_INIT']))
        header_file.write("#define __P24_PDR1_VALUE        {}\n".format(origin_data_tc['__P24_PDR1_VALUE']))
        header_file.write("#define __P25_PDR0_INIT         {}\n".format(origin_data_tc['__P25_PDR0_INIT']))
        header_file.write("#define __P25_PDR0_VALUE        {}\n".format(origin_data_tc['__P25_PDR0_VALUE']))
        header_file.write("#define __P25_PDR1_INIT         {}\n".format(origin_data_tc['__P25_PDR1_INIT']))
        header_file.write("#define __P25_PDR1_VALUE        {}\n".format(origin_data_tc['__P25_PDR1_VALUE']))
        header_file.write("#define __P30_PDR0_INIT         {}\n".format(origin_data_tc['__P30_PDR0_INIT']))
        header_file.write("#define __P30_PDR0_VALUE        {}\n".format(origin_data_tc['__P30_PDR0_VALUE']))
        header_file.write("#define __P30_PDR1_INIT         {}\n".format(origin_data_tc['__P30_PDR1_INIT']))
        header_file.write("#define __P30_PDR1_VALUE        {}\n".format(origin_data_tc['__P30_PDR1_VALUE']))
        header_file.write("#define __P31_PDR0_INIT         {}\n".format(origin_data_tc['__P31_PDR0_INIT']))
        header_file.write("#define __P31_PDR0_VALUE        {}\n".format(origin_data_tc['__P31_PDR0_VALUE']))
        header_file.write("#define __P31_PDR1_INIT         {}\n".format(origin_data_tc['__P31_PDR1_INIT']))
        header_file.write("#define __P31_PDR1_VALUE        {}\n".format(origin_data_tc['__P31_PDR1_VALUE']))
        header_file.write("#define __PCON0_INIT            {}\n".format(origin_data_tc['__PCON0_INIT']))
        header_file.write("#define __PCON0_VALUE           {}\n".format(origin_data_tc['__PCON0_VALUE']))
        header_file.write("#define __DCON0_INIT            {}\n".format(origin_data_tc['__DCON0_INIT']))
        header_file.write("#define __DCON0_VALUE           {}\n".format(origin_data_tc['__DCON0_VALUE']))
        header_file.write("\n")
        header_file.write("#endif /*__NO_CSTART_REGISTER_CONFIG */\n")
        header_file.write("\n")
        header_file.write("#endif /* CSTART_H */\n")


def modify_cstart_h(dic_project_info, save_file_path):

    #modify_data = pa.object_file_load(modify_data_path, "rb")
    modify_data = dic_project_info['Compiler']['Register_List']

    #save_file_name = save_file_path + "\\cstart.h"

    if dic_project_info['Test_Env']['CompilerVersion'] == "4.3":
        if 'tc29x' in dic_project_info['Test_Env']['Test_CPU']:
            #tasking_v43_tc29x_h_default()

            origin_data_tc.update(modify_data)
            origin_data_tc1.update(modify_data)
            origin_data_tc2.update(modify_data)
            tasking_v43(save_file_path)

        elif 'tc27x' in dic_project_info['Test_Env']['Test_CPU']:
            #tasking_v43_tc29x_h_default()
            tasking_v43_tc27x_h_default(dic_project_info)

            origin_data_tc.update(modify_data)
            origin_data_tc1.update(modify_data)
            origin_data_tc2.update(modify_data)
            tasking_v43_tc27x_h_modify_save(save_file_path)


    elif dic_project_info['Test_Env']['CompilerVersion'] == "6.2":
        if 'tc29x' in dic_project_info['Test_Env']['Test_CPU']:
            tasking_v62_tc29x_h_default(dic_project_info)

            origin_data_tc.update(modify_data)
            origin_data_tc1.update(modify_data)
            origin_data_tc2.update(modify_data)

            tasking_v62_tc29x_h_modify_save(save_file_path)

        # skc### 220211
        elif 'tc38x' in dic_project_info['Test_Env']['Test_CPU']:
            tasking_v62_tc38x_h_default(dic_project_info)

            origin_data_tc.update(modify_data)
            origin_data_tc1.update(modify_data)
            origin_data_tc2.update(modify_data)
            origin_data_tc3.update(modify_data)

            tasking_v62_tc38x_h_modify_save(save_file_path)
        # skc### 220211
			
        elif 'tc39x' in dic_project_info['Test_Env']['Test_CPU']:
            tasking_v62_tc39x_h_default(dic_project_info)

            origin_data_tc.update(modify_data)
            origin_data_tc1.update(modify_data)
            origin_data_tc2.update(modify_data)
            origin_data_tc3.update(modify_data)
            origin_data_tc4.update(modify_data)
            origin_data_tc5.update(modify_data)

            tasking_v62_tc39x_h_modify_save(save_file_path)

    elif dic_project_info['Test_Env']['CompilerVersion'] == "4.2":
        if 'tc29x' in dic_project_info['Test_Env']['Test_CPU']:
            tasking_v42_tc29x_h_default(dic_project_info)

            origin_data_tc.update(modify_data)
            origin_data_tc1.update(modify_data)
            origin_data_tc2.update(modify_data)

            tasking_v42_tc29x_h_modify_save(save_file_path)

        #tasking_v62_h_default()
        #origin_data_tc.update(modify_data)
        #tasking_v62(save_file_name)



#modify_cstart_h(r"C:\Git\1.Prost\Prost\src\compiler\src\tasking_v43_h_default.txt", r"C:\Git\1.Prost\Workspace\Project_Name\Target_SW", "4.3")
#modify_cstart_h( r"C:\Git\1.Prost\Workspace\Project_Name\Target_SW", "6.2")




