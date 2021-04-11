# Code READ ME

## GUI

The GUI is built using the Kivy2.0 module for Python 3.6. The resolution of the screen is 480x320 because it is the resolution of the touch scren that will be used eventually. The GUI is scallable so the window can be bigger and the layout will stay the same.
The app contains 3 windows:
1. Menu, boot window and used to acces the other windows.
  <img src="https://github.com/antoinejulien/Level-US_GRO400_H21/blob/master/Images/menu_window_R1.png?raw=true" width="480" height="320">
2. Manual Window, used to manually control the movement of the platform.
<img src="https://github.com/antoinejulien/Level-US_GRO400_H21/blob/master/Images/manual_window_R1.png?raw=true" width="480" height="320">
3. Automatic Window, not yet fully implemented, but will eventually have data for the automatic control of the platform.
4. <img src="https://github.com/antoinejulien/Level-US_GRO400_H21/blob/master/Images/automatic_window_R1.png?raw=true" width="480" height="320">

## OpenCR code

It is recommended to use the desktop Arduino IDE to upload the .ino code into the OpenCR. You can follow this link https://emanual.robotis.com/docs/en/parts/controller/opencr10/ for a step by step download (section 4). In the Arduino IDE app, you will also need to download the Dynamixel library. To do so :
  - Go to Tools -> Manage libraries ... -> Make sure that option all is selected in both boxes -> Type Dynamixel2Arduino and download the library.

If there are any issues, the library will still be available in the corresponding foler ([Libraries folder](Arduino/libraries)). You will then be able to use the library to communicate easily with the dynamixel motors. There are a few example codes in the File -> Example -> OpenCR section in the arduino IDE.

The MPU6050 libraries and all libraries attached were taken from another opensource github project. The link to the GitHub page is : https://github.com/rfetick/MPU6050_light

## Communication

The app is the high-end of the program, it sends commands to the OpenCR platform for the command type and positionning. The openCR communicates information about the sensors and the motors. Information are encoded and decoded on both end. All communication is done by serial port. 
