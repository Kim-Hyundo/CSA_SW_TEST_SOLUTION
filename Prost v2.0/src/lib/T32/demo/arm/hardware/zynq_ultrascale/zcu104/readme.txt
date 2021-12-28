; --------------------------------------------------------------------------------
; @Title: Readme for ZCU104 Evaluation Board
; @Description: Readme for ZCU104 Evaluation Board
; @Keywords: ARM, Cortex-A53
; @Author: CSA
; @Board: ZCU104
; @Chip: ZYNQ-ULTRASCALE+*
; @Props: ZIP
; @Copyright: (C) 1989-2019 Lauterbach GmbH, licensed for use with TRACE32(R) only
; --------------------------------------------------------------------------------
; $Id: readme.txt 14042 2019-03-01 15:09:19Z csax $

= Debug =
Please use connector J180/PC4 on ZCU104 in conjunction with LA-3881 for debug. Signal PC4_PS_SRST_B on J180/PC4 Pin 14 is
not forwarded by LA-3381 and has to be added manually. The PRACTICE scripts for ZCU102 are suitable for use with ZCU104.
