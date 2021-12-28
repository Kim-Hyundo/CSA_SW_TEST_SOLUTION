import os
import shutil
import subprocess
import pickle
from datetime import datetime
G_Log_level = int(0)

Logtype_CPL = int(-2)
Logtype_ERR = int(-1)
Logtype_PRG = int(0)
Logtype_PFF = int(1)
Logtype_INF = int(2)
Logtype_DGB = int(3)

# get time for log   #################################################################
def cur_date():
    now = datetime.now()
    return '%s-%s-%s' % (now.year, str(now.month).zfill(2), str(now.day).zfill(2))


def cur_time():
    now = datetime.now()
    return '%s:%s:%s.%s' % (str(now.hour).zfill(2), str(now.minute).zfill(2),
                            str(now.second).zfill(2), str(int(now.microsecond) // 1000).zfill(3))

def set_log(msg, logtype):
    LogTName='Unknown'
    if logtype == -2:
        LogTName='CPL'
    elif logtype == -1:
        LogTName='ERR'
    elif logtype == 0:
        LogTName = 'PRG'
    elif logtype == 1:
        LogTName = 'PFF'
    elif logtype == 2:
        LogTName = 'INF'
    elif logtype == 3:
        LogTName = 'DBG'
    else:
        LogTName = 'Unknown'

    if  G_Log_level >= logtype:
        msg = '[' + cur_time() + '][BUILD][' + LogTName + ']' + msg
        print(msg, flush=True)