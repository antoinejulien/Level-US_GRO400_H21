# Code READ ME

## GUI

The GUI is built using the Kivy2.0 module for Python 3.6. The resolution of the screen is 480x320 because it is the resolution of the touch scren that will be used eventually. The GUI is scallable so the window can be bigger and the layout will stay the same.
The app contains 3 windows:
1. Menu, boot window and used to acces the other windows.
2. Manual Window, used to manually control the movement of the platform.
3. Automatic Window, not yet fully implemented, but will eventually have data for the automatic control of the platform.

## Communication

The app is the high-end of the program, it sends commands to the OpenCR platform for the command type and positionning.
