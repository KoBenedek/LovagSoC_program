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
import sys

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
else:
    print("File of name: " + source_name + " not found!")
    exit()

source_contents:str = []

for line in source:
    source_contents.append(line)

try: 
    ser.open()
    if sys.argv[1] == "program":
        print("Uploading " + source_name + " to LovagSoC.")
        ser.write(("prog\n").encode())
        ser.readline()
        ser.write((str(len(source_contents)) + "\n").encode())
        ser.readline()
        for index, item in enumerate(source_contents):
            item = item.replace("\n", "")
            item = "0x" + item
            ser.write(((str(int(item, 16))) + "\n").encode())
            #print(str(index+1) + "\t" + str(int(item, 16)))
            read_data = ser.readline().decode("utf-8").replace("\n", "")
            #print("Rec:\t" + read_data)
            print("Progress: " + str(int(index * 100 / len(source_contents))) + "%", end='\r')
            if int(item, 16) != int(read_data): 
                print("Upload failed!")
                exit()
        ser.write(("done\n").encode())
        ser.readline()
        print("Upload finished.")
    elif sys.argv[1] == "erase":
        print("Erasing memory.")
        ser.write(("erase\n").encode())
        ser.readline()
        ser.write((sys.argv[2] + "\n").encode())
        ser.readline()
        read_data = ser.readline().decode("utf-8").replace("\n", "")
        if read_data.strip() == "done":
            print("Memory erased.")
            exit()
        elif read_data.strip() == "error":
            print("Erase failed!")
            exit()
    elif sys.argv[1] == "read":
        print("Reading memory contents into file.")
        read_file = open(sys.argv[3], "w")
        ser.write(("read\n").encode())
        ser.readline()
        ser.write((sys.argv[2] + "\n").encode())
        ser.readline()
        for index in range(int(sys.argv[2])):
            read_data = ser.readline().decode("utf-8").replace("\n", "")
            #print("Read:" + str("{:08x}".format(int(read_data))))
            if read_data.strip() == "error":
                print("Read failed!")
                exit()
            read_file.write(str("{:08x}".format(int(read_data))) + "\n")
            print("Progress: " + str(int(index * 100 / int(sys.argv[2]))) + "%", end='\r')
        read_data = ser.readline().decode("utf-8").replace("\n", "")
        if read_data.strip() == "done":
            print("Read complete.")
            exit()
        elif read_data.strip() == "error":
            print("Read failed!")
            exit()
        ser.readline()
    elif sys.argv[1] == "halt":
        ser.write(("halt\n").encode())
        read_data = ser.readline().decode("utf-8").replace("\n", "")
        if read_data.strip() == "ack":
            print("CPU halted.")
            read_data = ser.readline().decode("utf-8").replace("\n", "")
            print(str("{:08x}".format(int(read_data))))
            print(str(int(read_data) >> 2))
            exit()
        elif read_data.strip() == "error":
            print("Halt failed.")
            exit()
    elif sys.argv[1] == "resume":
        ser.write(("run\n").encode())
        read_data = ser.readline().decode("utf-8").replace("\n", "")
        if read_data.strip() == "ack":
            print("CPU resumed.")
            exit()
        elif read_data.strip() == "error":
            print("Resume failed.")
            exit()
    elif sys.argv[1] == "reset":
        ser.write(("reset\n").encode())
        read_data = ser.readline().decode("utf-8").replace("\n", "")
        if read_data.strip() == "ack":
            print("CPU reset.")
            exit()
        elif read_data.strip() == "error":
            print("Reset failed.")
            exit()
    elif sys.argv[1] == "step":
        ser.write(("step\n").encode())
        read_data = ser.readline().decode("utf-8").replace("\n", "")
        if read_data.strip() == "ack":
            read_data = ser.readline().decode("utf-8").replace("\n", "")
            print(str("{:08x}".format(int(read_data))))
            print(str(int(read_data) >> 2))
            exit()
        elif read_data.strip() == "error":
            print("Step failed.")
            exit()
    ser.close()
    exit()
except Exception as e:
    print("Error with open serial port: " + str(e))
    exit()
