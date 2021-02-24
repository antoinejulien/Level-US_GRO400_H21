import serial
import time
from kivy.app import App
from kivy.uix.widget import Widget
from kivy.lang import Builder
from kivy.properties import ObjectProperty
from kivy.core.window import Window
from kivy.uix.screenmanager import Screen, ScreenManager


class MenuWindow(Screen):
     pass

class ManualWindow(Screen):
    def __init__(self, **kwargs): 
        super(ManualWindow, self).__init__(**kwargs)
        self.ser = serial.Serial('COM3', 57600, timeout=1)
        self.status = ObjectProperty(None)

    def high(self):
        self.status.text = "Moving to\nposition high."
        line = ""
        self.status.text = "Writing line"
        self.ser.write(b"3")

        self.status.text = "Reading line"
        
        while line == "":
            line = self.ser.read_until("\n").decode('utf-8').rstrip()

        if line == "DONE":
            self.status.text = "Position high\nreached."

        else:
            self.status.text = "An error\noccured."

    def mid(self):
        self.status.text = "Moving to\nposition mid."
        line = ""

        self.status.text = "Writing line"
        self.ser.write(b"2")

        self.status.text = "Reading line"

        while line == "":
            line = self.ser.read_until("\n").decode('utf-8').rstrip()

        if line == "DONE":
            self.status.text = "Position mid\nreached."

        else:
            self.status.text = "An error\noccured."

    def low(self):
        self.status.text = "Moving to\nposition low."        
        line = ""

        self.status.text = "Writing line"   
        self.ser.write(b"1")
        
        self.status.text = "Reading line"
        while line == "":
            line = self.ser.read_until("\n").decode('utf-8').rstrip()

        if line == "DONE":
            self.status.text = "Position low\nreached."

        else:
            self.status.text = line

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