; --------------------------------------------------------------------------------
; @Title: IMX6 Secure JTAG Files - README
; @Description: -
; @Author: KJM
; @Chip: IMX6*
; @Copyright: (C) 1989-2017 Lauterbach GmbH, licensed for use with TRACE32(R) only
; --------------------------------------------------------------------------------
; $Id: readme.txt 11811 2017-12-19 13:50:20Z amerkle $

The scripts enable the secure jtag (sjc) using the challenge/response mechanism.

1. Enter the response in calculate_response.cmm. The script gets the challenge as parameter (&challenge)
2. Call attachimx.cmm

imx6_attach_secured.cmm can be called with the following parameters:
  DO imx6_attach_secured.cmm [WAITRESET=<time>] [ENRESET=ON|OFF]
  Default values: WAITRESET=2.s ENRESET=ON
Example 1:
  DO imx6_attach_secured.cmm WAITRESET=300.ms ENRESET=ON
  Reset the SoC by asserting the nRESET line and wait 300ms after reset release with the challenge response attempt.
Example 2:
  DO imx6_attach_secured.cmm ENRESET=OFF
  Immediately start with the challenge response attempt without asserting the nRESET line.