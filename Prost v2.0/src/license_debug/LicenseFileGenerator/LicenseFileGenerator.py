import os
import sys
import hashlib
from datetime import datetime, timedelta

from PyQt5.QtWidgets import QApplication, QWidget, QGridLayout, QLabel, QLineEdit, QTextEdit, QPushButton, QDesktopWidget, QComboBox, QMessageBox
from PyQt5.QtCore import QCoreApplication

import AESCipherModule as AESCM


class MyApp(QWidget):

    def __init__(self):
        super().__init__()

        self.todayNow = datetime.now()
        self.key = [0x10, 0x01, 0x15, 0x1B, 0xA1, 0x11, 0x57, 0x72, 0x6C, 0x21, 0x56, 0x57, 0x62, 0x16, 0x05, 0x3D,
                    0xFF, 0xFE, 0x11, 0x1B, 0x21, 0x31, 0x57, 0x72, 0x6B, 0x21, 0xA6, 0xA7, 0x6E, 0xE6, 0xE5, 0x3F]

        self.licenseKey = ""
        self.hashValue = ""
        self.licenseData = ""

        self.endUsercompany = ""
        self.userName = ""
        self.t32IPAddress = ""
        self.userDefendencyLicenseData = ""
        self.licenseIssuedDate = str(self.todayNow.date())
        self.licenseExpiredDate = ""
        self.maintenanceExpiredDate = ""
        self.supportArch = ""
        self.supportMCU = ""

        # set data widget
        self.licenseKeyArea = QTextEdit()
        self.endUsercompanyLE = QLineEdit()
        self.userNameLE = QLineEdit()
        self.userDefendencyLicenseDataLE = QLineEdit()
        self.t32IPAddressLE = QLineEdit()
        self.licenseExpiredDateLE = QLineEdit()
        self.maintenanceExpiredDateLE = QLineEdit()

        # set data field attributes
        self.endUsercompanyLE.setReadOnly(True)
        self.userNameLE.setReadOnly(True)
        self.userDefendencyLicenseDataLE.setReadOnly(True)
        self.t32IPAddressLE.setReadOnly(True)
        self.licenseExpiredDateLE.setReadOnly(True)
        self.maintenanceExpiredDateLE.setReadOnly(True)

        self.initUI()

    def initUI(self):

        # add generate button
        generateBtn = QPushButton('Generate', self)
        generateBtn.resize(generateBtn.sizeHint())
        generateBtn.clicked.connect(self.clickedGenerateBtn)

        # add Quit button
        quitBtn = QPushButton('Quit', self)
        quitBtn.resize(quitBtn.sizeHint())
        quitBtn.clicked.connect(QCoreApplication.instance().quit)

        # set license Issue date
        licenseIssueDateLE = QLineEdit()
        licenseIssueDateLE.setText(self.licenseIssuedDate)
        licenseIssueDateLE.setReadOnly(True)

        # add combo box as each label
        licenseTermCB = QComboBox(self)
        licenseTermCB.addItem("1 month")
        licenseTermCB.addItem("1 year")
        licenseTermCB.addItem("permanent")

        # add combo box as each label
        maintenanceTermCB = QComboBox(self)
        maintenanceTermCB.addItem("1 month")
        maintenanceTermCB.addItem("1 year")

        # add combo box as each label
        supportArchCB = QComboBox(self)
        supportArchCB.addItem("AURIX")

        # add combo box as each label
        supportMCUCB = QComboBox(self)
        supportMCUCB.addItem("TC277")

        # activate.connect
        self.licenseKeyArea.textChanged.connect(self.onLicenseKeyAreaChanged)
        licenseTermCB.activated[str].connect(self.onLicenseTermCBActivated)
        maintenanceTermCB.activated[str].connect(self.onMaintenanceTermCBActivated)
        supportArchCB.activated[str].connect(self.onSupportArchCBActivated)
        supportMCUCB.activated[str].connect(self.onSupportMCUCBActivated)

        # draw grid layoutdwd
        grid = QGridLayout()
        self.setLayout(grid)

        grid.addWidget(QLabel('License key'), 0, 0)
        grid.addWidget(QLabel('End User(Company) :'), 1, 0)
        grid.addWidget(QLabel('User Name :'), 2, 0)
        grid.addWidget(QLabel('PC ID :'), 3, 0)
        grid.addWidget(QLabel('TRACE32 IP Address :'), 4, 0)
        grid.addWidget(QLabel('License issue date :'), 5, 0)
        grid.addWidget(QLabel('License Term :'), 6, 0)
        grid.addWidget(QLabel('Maintenance Term :'), 7, 0)
        grid.addWidget(QLabel('License Expired Date :'), 8, 0)
        grid.addWidget(QLabel('Maintenance Expired Date :'), 9, 0)
        grid.addWidget(QLabel('Support Architecture :'), 10, 0)
        grid.addWidget(QLabel('Support MCU :'), 11, 0)
        grid.addWidget(generateBtn, 12, 0)

        grid.addWidget(self.licenseKeyArea, 0, 1)
        grid.addWidget(self.endUsercompanyLE, 1, 1)
        grid.addWidget(self.userNameLE, 2, 1)
        grid.addWidget(self.userDefendencyLicenseDataLE, 3, 1)
        grid.addWidget(self.t32IPAddressLE, 4, 1)
        grid.addWidget(licenseIssueDateLE, 5, 1)
        grid.addWidget(licenseTermCB, 6, 1)
        grid.addWidget(maintenanceTermCB, 7, 1)
        grid.addWidget(self.licenseExpiredDateLE, 8, 1)
        grid.addWidget(self.maintenanceExpiredDateLE, 9, 1)
        grid.addWidget(supportArchCB, 10, 1)
        grid.addWidget(supportMCUCB, 11, 1)
        grid.addWidget(quitBtn, 12, 1)

        self.setWindowTitle('PROST License File Generator')
        self.setGeometry(500, 500, 400, 400)
        self.center()
        self.show()

    def onLicenseKeyAreaChanged(self):
        try:
            self.licenseKey = self.licenseKeyArea.toPlainText()
            decrypted_data = AESCM.AESCipher(bytes(self.key)).decrypt(self.licenseKey)
            decrypted_data = decrypted_data.decode('utf-8')
            licenseKeyRawData = decrypted_data.split('@@')

            self.t32IPAddress = licenseKeyRawData[1]
            self.userName = licenseKeyRawData[2]
            self.userDefendencyLicenseData = licenseKeyRawData[3]
            self.endUsercompany = licenseKeyRawData[4]
        except Exception as ex:
            print(ex);
            self.endUsercompany = ""
            self.userName = ""
            self.userDefendencyLicenseData = ""
            self.t32IPAddress = ""
        self.endUsercompanyLE.setText(self.endUsercompany)
        self.userNameLE.setText(self.userName)
        self.userDefendencyLicenseDataLE.setText(self.userDefendencyLicenseData)
        self.t32IPAddressLE.setText(self.t32IPAddress)

    def clickedGenerateBtn(self):
        if ( self.userDefendencyLicenseData or self.licenseExpiredDate or self.maintenanceExpiredDate or self.supportArch or self.supportMCU) == "":
            reply = QMessageBox.critical(self, "Error", "Please set any empty configurations", QMessageBox.Close)
        else:
            """
            self.hashValue = self.endUsercompany + self.userName + self.userDefendencyLicenseData + self.licenseIssuedDate \
                             + self.licenseExpiredDate + self.maintenanceExpiredDate + self.supportArch + self.supportMCU + self.t32IPAddress
            """
            self.hashValue = self.endUsercompany + self.userName + self.userDefendencyLicenseData + self.t32IPAddress \
                             + self.licenseIssuedDate + self.licenseExpiredDate + self.maintenanceExpiredDate + self.supportArch + self.supportMCU

            self.licenseData = self.get_hash_value(in_str=self.hashValue, in_digest_bytes_size=64, in_return_type='hexdigest')

            #print(self.hashValue)

            filename = "LCF_" + str(self.todayNow.year) + str(self.todayNow.month) + str(self.todayNow.day) + ".plc"
            with open(filename, 'wt', encoding='utf-8', newline='') as licenseFileWrite:
                licenseFileWrite.write("HancomMDS PROST License\n")
                licenseFileWrite.write("EndUserCompany="+self.endUsercompany+"\n")
                licenseFileWrite.write("UserName="+self.userName+"\n")
                licenseFileWrite.write("PCID="+self.userDefendencyLicenseData+"\n")
                licenseFileWrite.write("TRACE32 IP Address=" + self.t32IPAddress + "\n")
                licenseFileWrite.write("LicenseIssuedDate="+self.licenseIssuedDate+"\n")
                licenseFileWrite.write("LicenseExpirationDate="+self.licenseExpiredDate+"\n")
                licenseFileWrite.write("MaintenanceExpirationDate="+self.maintenanceExpiredDate+"\n")
                licenseFileWrite.write("SupportArchitecture="+self.supportArch+"\n")
                licenseFileWrite.write("SupportMCU="+self.supportMCU+"\n")
                licenseFileWrite.write("LicenseData=" + self.licenseData + "\n")
            licenseFileWrite.close()
            reply = QMessageBox.information(self, "Success", "Created new license file", QMessageBox.Close)

    def onLicenseTermCBActivated(self, text):
        if text == "1 month":
            self.licenseExpiredDate = self.todayNow + timedelta(days=30)
        elif text == "1 year":
            self.licenseExpiredDate = self.todayNow + timedelta(days=365)
        elif text == "permanent":
            self.licenseExpiredDate = self.todayNow + timedelta(days=36135)
        self.licenseExpiredDate = str(self.licenseExpiredDate.date())
        self.licenseExpiredDateLE.setText(self.licenseExpiredDate)

    def onMaintenanceTermCBActivated(self, text):
        if text == "1 month":
            self.maintenanceExpiredDate = self.todayNow + timedelta(days=30)
        elif text == "1 year":
            self.maintenanceExpiredDate = self.todayNow + timedelta(days=365)
        self.maintenanceExpiredDate = str(self.maintenanceExpiredDate.date())
        self.maintenanceExpiredDateLE.setText(self.maintenanceExpiredDate)

    def onSupportArchCBActivated(self, text):
        self.supportArch = text

    def onSupportMCUCBActivated(self, text):
        self.supportMCU = text

    def center(self):
        qr = self.frameGeometry()
        cp = QDesktopWidget().availableGeometry().center()
        qr.moveCenter(cp)
        self.move(qr.topLeft())

    def get_hash_value(self, in_str, in_digest_bytes_size=64, in_return_type='digest'):
        """해시값을 구한다
        Parameter: in_str: 해싱할문자열, in_digest_bytes_size: Digest바이트크기,
                   in_return_type: 반환형태(digest or hexdigest or number) """
        assert 1 <= in_digest_bytes_size and in_digest_bytes_size <= 64
        blake = hashlib.blake2b(in_str.encode('utf-8'), digest_size=in_digest_bytes_size)
        if in_return_type == 'hexdigest': return blake.hexdigest()
        elif in_return_type == 'number': return int(blake.hexdigest(), base=16)
        return blake.digest()


if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = MyApp()
    sys.exit(app.exec_())


