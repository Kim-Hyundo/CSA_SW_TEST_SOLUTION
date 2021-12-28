import sys
import os
import subprocess
import re

sys.path.append(os.path.dirname(os.path.abspath(os.path.dirname(__file__))))
import AESCipherModule as AESCM

from PyQt5.QtWidgets import QApplication, QWidget, QGridLayout, QLabel, QLineEdit, QTextEdit, QPushButton, QDesktopWidget, QComboBox
from PyQt5.QtCore import QCoreApplication

# class MyApp for UI design
class MyApp(QWidget):

    def __init__(self):
        super().__init__()

        cmd = "vol c:"
        sysMsg = subprocess.getstatusoutput(cmd)
        p = re.compile("\w+[-]\w+")
        m = p.search(sysMsg[1])

        self.companyLists = []
        self.endUsercompany = ""
        self.t32IPAddress = ""
        self.userName = ""
        self.licenseKey = ""
        self.licenseKeyArea = QTextEdit()
        self.userDefendencyLicenseData = m.group()

        self.key = [0x10, 0x01, 0x15, 0x1B, 0xA1, 0x11, 0x57, 0x72, 0x6C, 0x21, 0x56, 0x57, 0x62, 0x16, 0x05, 0x3D,
                    0xFF, 0xFE, 0x11, 0x1B, 0x21, 0x31, 0x57, 0x72, 0x6B, 0x21, 0xA6, 0xA7, 0x6E, 0xE6, 0xE5, 0x3F]

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

        # add combo box as each label
        endUserCompanyLE = QLineEdit(self)
        userNameLE = QLineEdit(self)
        t32IPAddressLE = QLineEdit(self)

        # add combo box as each label
        licenseTypeCB = QComboBox(self)
        #licenseTypeCB.addItem("Node-Lock")
        licenseTypeCB.addItem("Float")

        # grid License key area
        self.licenseKeyArea.setReadOnly(True)

        # activate.connect
        endUserCompanyLE.textChanged[str].connect(self.onEndUserCompanyChanged)
        userNameLE.textChanged[str].connect(self.onUserNameChanged)
        t32IPAddressLE.textChanged[str].connect(self.onT32IPAddressChanged)
        #licenseTypeCB.activated[str].connect(self.onLicenseTermCBActivated)


        # draw grid layout
        grid = QGridLayout()
        self.setLayout(grid)

        grid.addWidget(QLabel('End User(Company) :'), 0, 0)
        grid.addWidget(QLabel('User Name :'), 1, 0)
        grid.addWidget(QLabel('License Type :'), 2, 0)
        grid.addWidget(QLabel('TRACE32 IP Address'), 3, 0)
        grid.addWidget(QLabel('License key'), 4, 0)
        grid.addWidget(self.licenseKeyArea, 5, 0)
        grid.addWidget(generateBtn, 9, 0)

        grid.addWidget(endUserCompanyLE, 0, 1)
        grid.addWidget(userNameLE, 1, 1)
        grid.addWidget(licenseTypeCB, 2, 1)
        grid.addWidget(t32IPAddressLE, 3, 1)
        grid.addWidget(quitBtn, 9, 1)

        self.setWindowTitle('License Key Generator')
        self.setGeometry(300, 300, 300, 300)
        self.center()
        self.show()


    def clickedGenerateBtn(self):
        #print("click generate button")

        data = "@@" + self.endUsercompany + "@@" + self.userName + "@@" + self.userDefendencyLicenseData + "@@" \
               + self.t32IPAddress + "@@"
        #print(data)
        try:
            encrypted_data = AESCM.AESCipher(bytes(self.key)).encrypt(data)
            self.licenseKey = str(encrypted_data, encoding='utf-8')
            self.licenseKeyArea.setText(self.licenseKey)
            #print(self.licenseKey)


            decrypted_data = AESCM.AESCipher(bytes(self.key)).decrypt(self.licenseKey)
            decrypted_data = decrypted_data.decode('utf-8')
            #print(decrypted_data)

        except Exception as ex:
            print("dd :", ex)

    def onUserNameChanged(self, text):
        self.userName = text
        #print(self.userName)

    def onEndUserCompanyChanged(self, text):
        self.t32IPAddress = text
        #print(self.endUsercompany)

    def onT32IPAddressChanged(self, text):
        self.endUsercompany = text
        #print(self.endUsercompany)

    def center(self):
        qr = self.frameGeometry()
        cp = QDesktopWidget().availableGeometry().center()
        qr.moveCenter(cp)
        self.move(qr.topLeft())

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = MyApp()

    #print("Hello World")

    sys.exit(app.exec_())


