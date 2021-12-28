; --------------------------------------------------------------------------------
; @Title: Erika3 demo for TC39x and TC27x emulation devices
; @Description:
; @Keywords: AURIX, AURIX2G, AUTOSAR, flash, Infineon, TriCore
; @Author: HDA
; @Copyright: (C) 1989-2020 Lauterbach GmbH, licensed for use with TRACE32(R) only
; --------------------------------------------------------------------------------
; $Id: readme.txt 16283 2020-07-07 13:57:07Z hdammak $


Notes on the application:
- Built using Erika3 GH65
- SMP variant, using 3 cores.

Demo tc27x:
    - Tested with TriBoard:
        + TC275TE
        + TC275TF
        + TC277TE
        + TC277TF

    - To start the demo:
        + Start TRACE32
        + Power on the target
        + Run the script tc27x/start_erika3_tc27x.cmm
            e.g.:
            DO ~~/demo/tricore/kernel/erika/v3/tc27x/start_erika3_tc27x.cmm

Demo tc39x:
    - Tested with TriBoard:
        + TC397XE
        + TC397QP

    - To start the demo:
        + Start TRACE32
        + Power on the target
        + Run the script tc39x/start_erika3_tc39x.cmm
            e.g.:
            DO ~~/demo/tricore/kernel/erika/v3/tc39x/start_erika3_tc39x.cmm