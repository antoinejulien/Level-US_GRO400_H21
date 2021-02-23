import serial
from kivy.app import App
from kivy.uix.widget import Widget
from kivy.lang import Builder
from kivy.properties import ObjectProperty
from kivy.core.window import Window
from kivy.uix.screenmanager import Screen, ScreenManager


class MenuWindow(Screen):
     pass

class ManualWindow(Screen):
    
    status = ObjectProperty(None)
    
    ser = serial.Serial('/dev/ttyACM0', 56600)
    ser.flush()

    def high(self):
        self.status.text = "Moving to\nposition high."
        
        if(ser.in_waiting >0):
            ser.write(b"HIGH\n")
            line = ser.readline().decode('utf-8').rstrip()

            if line == "DONE":
                self.status.text = "Position high\nreached."

            if line == "ERR":
                self.status.text = "An error\noccured."

    def mid(self):
        self.status.text = "Moving to\nposition mid."

        if(ser.in_waiting >0):
            ser.write(b"MID\n")
            line = ser.readline().decode('utf-8').rstrip()

            if line == "DONE":
                self.status.text = "Position mid\nreached."

            if line == "ERR":
                self.status.text = "An error\noccured."

    def low(self):
        self.status.text = "Moving to\nposition low."

        if(ser.in_waiting >0):
            ser.write(b"LOW\n")
            line = ser.readline().decode('utf-8').rstrip()

            if line == "DONE":
                self.status.text = "Position low\nreached."

            if line == "ERR":
                self.status.text = "An error\noccured."

class AutoWindow(Screen):
    pass

class WindowManager(ScreenManager):
    pass

kv_builder = Builder.load_file("GUI\\gui.kv")

class Level_US(App):

    def build(self):
        Window.clear
        Window.size = (480, 320)
        return kv_builder

if __name__ == "__main__":
    pass