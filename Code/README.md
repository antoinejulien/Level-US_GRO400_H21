# Code READ ME

## GUI

The GUI is built using the Kivy2.0 module for Python 3.6. The resolution of the screen is 480x320 because it is the resolution of the touch scren that will be used eventually. The GUI is scallable so the window can be bigger and the layout will stay the same.
The app contains 3 windows:
1. Menu, boot window and used to acces the other windows.
  <img src="https://github.com/antoinejulien/Level-US_GRO400_H21/blob/master/Images/menu_window_R1.png?raw=true" width="480" height="320">
2. Manual Window, used to manually control the movement of the platform.
<img src="https://github.com/antoinejulien/Level-US_GRO400_H21/blob/python-gui/Images/manual_window_R1.jpg?raw=true" width="480" height="320">
3. Automatic Window, not yet fully implemented, but will eventually have data for the automatic control of the platform.
4. <img src="https://github.com/antoinejulien/Level-US_GRO400_H21/blob/master/Images/automatic_window_R1.png?raw=true" width="480" height="320">


## Communication

The app is the high-end of the program, it sends commands to the OpenCR platform for the command type and positionning.
