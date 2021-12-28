import hashlib
import os
import subprocess
import re
import sys


def get_hash_value(in_str, in_digest_bytes_size=64, in_return_type='digest'):
    """해시값을 구한다
    Parameter: in_str: 해싱할문자열, in_digest_bytes_size: Digest바이트크기,
               in_return_type: 반환형태(digest or hexdigest or number) """
    assert 1 <= in_digest_bytes_size and in_digest_bytes_size <= 64
    blake = hashlib.blake2b(in_str.encode('utf-8'), digest_size=in_digest_bytes_size)
    if in_return_type == 'hexdigest':
        return blake.hexdigest()
    elif in_return_type == 'number':
        return int(blake.hexdigest(), base=16)
    return blake.digest()

def create_logfile(str_value):
    f = open(licfile_path + "\\" + "LogFile.txt",'a')
    f.writelines(str_value + "\n")
    f.close()

def get_plc_filename(licfile_path):
    plc_filename = ""

    for file in os.listdir(licfile_path):
        if file.endswith(".plc"):
            plc_filename = licfile_path + "\\" + file

    if plc_filename == "":
        print("License File Not Found")

    return plc_filename


def license_check(licfile_path, t32IPAddress):

    licensePassFail = False
    create_logfile("license_check Start")
    ###Get C: Volume ID(PCID)
    cmd = "vol c:"
    create_logfile("license_check Start 1")
    try:

        sysMsg = os.system(cmd + ' > os_info.txt')
        if os.path.exists('os_info.txt'):
            fp = open('os_info.txt', "r")
            output = fp.read()
            fp.close()
            os.remove('os_info.txt')
        create_logfile("license_check Step 1 :: " + output.split('\n')[1])
        p = re.compile("\w+[-]\w+")
        create_logfile("license_check Step 2")
        m = p.search(output.split('\n')[1])
        create_logfile("license_check Step 3")
        userDefendencyLicenseData = m.group()
        create_logfile("license_check Step 4")
    except Exception as ex:
        create_logfile("Exception :: " + ex)
    with open(get_plc_filename(licfile_path), 'r') as licenseFile:
        while True:
            line = licenseFile.readline()
            # print(line)
            if 'EndUserCompany' in line:
                endUsercompany = line.split('=')
                endUsercompany = endUsercompany[1].replace("\n", "")
            elif 'UserName' in line:
                userName = line.split('=')
                userName = userName[1].replace("\n", "")
            elif 'PCID' in line:
                userDefendencyLicenseData = line.split('=')
                userDefendencyLicenseData = userDefendencyLicenseData[1].replace("\n", "")
            elif 'LicenseIssuedDate' in line:
                licenseIssuedDate = line.split('=')
                licenseIssuedDate = licenseIssuedDate[1].replace("\n", "")
            elif 'LicenseExpirationDate' in line:
                licenseExpiredDate = line.split('=')
                licenseExpiredDate = licenseExpiredDate[1].replace("\n", "")
            elif 'MaintenanceExpirationDate' in line:
                maintenanceExpiredDate = line.split('=')
                maintenanceExpiredDate = maintenanceExpiredDate[1].replace("\n", "")
            elif 'SupportArchitecture' in line:
                supportArch = line.split('=')
                supportArch = supportArch[1].replace("\n", "")
            elif 'SupportMCU' in line:
                supportMCU = line.split('=')
                supportMCU = supportMCU[1].replace("\n", "")
            elif 'LicenseData' in line:
                licenseFileHData = line.split('=')
                licenseFileHData = licenseFileHData[1].replace("\n", "")
            if not line:
                break
    create_logfile("license_check Step 5")
    hashValue = endUsercompany + userName + userDefendencyLicenseData + t32IPAddress + licenseIssuedDate \
                + licenseExpiredDate + maintenanceExpiredDate + supportArch + supportMCU
    # print(hashValue)
    licenseCompareHData = get_hash_value(in_str=hashValue, in_digest_bytes_size=64, in_return_type='hexdigest')
    create_logfile("licenseCompareHData :: " + licenseCompareHData)
    create_logfile("licenseFileHData :: " + licenseFileHData)
    if licenseCompareHData == licenseFileHData:
        licensePassFail = True

    else:
        licensePassFail = False

    return licensePassFail


if __name__ == "__main__":
    licfile_path = str(sys.argv[1])
    t32IPAddress = str(sys.argv[2])
    #t32IPAddress = "192.168.20.100"
    #licfile_path = "C:/Users/CSA_DEV/Documents/Working/Prost_v2.0/Prost v2.0/etc"
    create_logfile("t32IPAddress :: " + t32IPAddress);
    create_logfile("licfile_path :: " + licfile_path);

    if license_check(licfile_path, t32IPAddress):
        print("Pass")
    else:
        print("Fail")
