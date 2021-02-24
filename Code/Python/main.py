#!/usr/bin/env python

#################################################################
#     This is the start of our main program.                    #
#     Other files and folder might be added                     #
#     later on.                                                 #
#                                                               #
#     All files are created by the Level-US                     #
#     team and other information can be found                   #
#     in at the github page :                                   #
#     https://github.com/antoinejulien/Level-US_GRO400_H21      #
#################################################################
import GUI.gui as gui
#import serial
#import time

if __name__ == "__main__":
    app = gui.Level_US()
    app.run()

    #ser = serial.Serial('COM3', 57600, timeout=1)
    #ser.flush()
    #ser.reset_input_buffer()

    #print("Writing")
    #ser.write("2".encode('utf-8'))
    #while True:
        #if ser.in_waiting > 0:
            #print("Reading")
            #line = ser.read_until().decode('utf-8')
            #print(line)
        #time.sleep(1)