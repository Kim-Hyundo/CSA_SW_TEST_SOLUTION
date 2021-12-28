; --------------------------------------------------------------------------------
; @Title: Marvell DB-784MP STM Demo Scripts - README
; @Description: -
; @Author: PEG
; @Board: DB-MV784MP-GP
; @Chip: MV78460V7
; @Copyright: (C) 1989-2014 Lauterbach GmbH, licensed for use with TRACE32(R) only
; --------------------------------------------------------------------------------
; $Id: readme.txt 7050 2014-05-05 12:40:42Z mobermeir $

02-09-2013, PEG

Hints for debugging the Marvell MV78460V7 on the Armada XP Development Platform DB-MV784MP-GP:

TRACE32 Software Version:
You need to use a version dated August 26, 2013 or newer.
There is not yet a suitable release version available.
Meanwhile you could use an intermediate update which you get here:
http://www.lauterbach.com/support/53094133_02-09-13_arm_update.zip
Just replace fcc.t32 and fccarm.t32 in the TRACE32 system directory (c:\t32?)
and replace the executable you are using (host dependent).
If the link is not valid anymore contact Alexander.Merkle@lauterbach.com.

Start-up script:
Enclosed is a first draft of a script: start.cmm
Further tests with the board are on-going.

