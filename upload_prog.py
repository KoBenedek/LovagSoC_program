# -*- coding: utf-8 -*-

"""
    Copyright (C) 2023 Benedek Kocsis

    File name:      upload_prog.py
    Company:        University of Miskolc
    Department:     Department of Automation and Infocommunication
    Author:         Benedek Kocsis

    Description:    Sript for uploading output hex file to the LovagSoC.
                    Uses the MikroKon board with its software.
"""

import serial
import os

ser = serial.Serial()
ser.port = "/dev/ttyACM0"
ser.baudrate = 115200
ser.bytesize = serial.EIGHTBITS
ser.parity = serial.PARITY_NONE
ser.stopbits = serial.STOPBITS_ONE
ser.xonxoff = False
ser.rtscts = True
ser.dsrdtr = True

source_name = "LovagSoC_program.hex"

os.chdir("./build/")
if os.path.isfile(source_name):
    source = open(source_name, "r")
    print("Uploading " + source_name + " to LovagSoC.")
else:
    print("File of name: " + source_name + " not found!")
    exit()

source_contents:str = []

for line in source:
    source_contents.append(line)

try: 
    ser.open()
    ser.write(("prog\n").encode())
    ser.readline()
    ser.write((str(len(source_contents)) + "\n").encode())
    ser.readline()
    for index, item in enumerate(source_contents):
        item = item.replace("\n", "")
        item = "0x" + item
        ser.write(((str(int(item, 16))) + "\n").encode())
        print("Progress: " + str(int(index * 100 / len(source_contents))) + "%", end='\r')
        if int(item, 16) != int(ser.readline().decode("utf-8").replace("\n", "")): 
            print("Upload failed!")
            exit()
    ser.write(("done\n").encode())
    ser.readline()
    print("Upload finished.")
    ser.close()
    exit()
except Exception as e:
    print("Error with open serial port: " + str(e))
    exit()
