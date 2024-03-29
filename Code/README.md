# Code READ ME

## GUI

The GUI is built using the Kivy2.0 module for Python 3.6. The resolution of the screen was originally set to 480x320 because it is the resolution of the touch scren that would be used eventually, but it is still not implemented. The GUI is scallable so the window can be bigger and the layout will stay the same.
The app contains 3 windows:
1. Menu, boot window and used to acces the other windows. It also allows to see the state of the serial port connection. If the port is not connected, a pop-up will appear to block the acces to that window.
  <img src="https://github.com/antoinejulien/Level-US_GRO400_H21/blob/master/Images/Main_menu.png?raw=true" width="480" height="320">
2. Manual Window, used to manually control the movement of the platform to allow easy testing.
<img src="https://github.com/antoinejulien/Level-US_GRO400_H21/blob/master/Images/manual.png?raw=true" width="480" height="320">
3. Automatic Window, allows to start and stop the automatic control of the platform. The values read by the OpenCR and the motor angles sent are also displayed on the screen.
  <img src="https://github.com/antoinejulien/Level-US_GRO400_H21/blob/master/Images/Automatic.png?raw=true" width="480" height="320">
NOTE: If the serial connection is lost during the use of the automatic mode, it will stop and return to the menu.

## OpenCR code

It is recommended to use the desktop Arduino IDE to upload the .ino code into the OpenCR. You can follow this link https://emanual.robotis.com/docs/en/parts/controller/opencr10/ for a step by step download (section 4). In the Arduino IDE app, you will also need to download the Dynamixel library. To do so :
  - Go to Tools -> Manage libraries ... -> Make sure that option all is selected in both boxes -> Type Dynamixel2Arduino and download the library.

If there are any issues, the library will still be available in the corresponding foler ([Libraries folder](Arduino/libraries)). You will then be able to use the library to communicate easily with the dynamixel motors. There are a few example codes in the File -> Example -> OpenCR section in the arduino IDE.

The MPU6050 libraries and all libraries attached were taken from another opensource github project. The link to the GitHub page is : https://github.com/rfetick/MPU6050_light

## Communication

The app is the high-end of the program, it sends commands to the OpenCR platform for the command type and positionning. The openCR communicates information about the sensors and the motors. Information are encoded and decoded on both end. All communication is done by serial port. 

## Code Specifications

Make sure that the motors are labeled correctly from 1 to 3 in the arduino code. Also, motor 1's arm should be aligned with the x openCR IMU rotating axis. Also, as for the MPU6050, the code to retreive angles was written and commented in the openCR code. We wanted to make a PID on the position and the angle, but we didn't have enough time.
