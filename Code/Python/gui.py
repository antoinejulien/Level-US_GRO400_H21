import serial
import time

from kivy.app import App
from kivy.config import Config
from kivy.uix.widget import Widget
from kivy.lang import Builder
from kivy.properties import ObjectProperty
from kivy.core.window import Window
from kivy.uix.screenmanager import Screen, ScreenManager

Config.set("graphics", "window_state", "maximized")
class MenuWindow(Screen):
     pass

class ManualWindow(Screen):
    def __init__(self, **kwargs): 
        super(ManualWindow, self).__init__(**kwargs)
        self.ser = serial.Serial('COM3', 57600, timeout=1)
        self.ser.flush()
        self.status = ObjectProperty(None)

    def high(self):
        self.status.text = "Moving to\nposition high."
        line = ""

        self.status.text = "Writing line"
        self.ser.write(b"3")
        self.ser.reset_input_buffer()

        self.status.text = "Reading line"
        
        while True:
            if self.ser.in_waiting > 0:
                line = self.ser.readline()
                line = line.decode("utf-8").rstrip()

                if line == "DONE":
                    self.status.text = "Position high\nreached."
                    break

                else:
                    self.status.text = "An error\noccured."
                    break

    def mid(self):
        self.status.text = "Moving to\nposition mid."
        line = ""

        self.status.text = "Writing line"
        self.ser.write(b"2")

        self.ser.reset_input_buffer()
        self.status.text = "Reading line"

        while True:
            if self.ser.in_waiting > 0:
                line = self.ser.readline()
                line = line.decode("utf-8").rstrip()

                if line == "DONE":
                    self.status.text = "Position mid\nreached."
                    break

                else:
                    self.status.text = "An error\noccured."
                    break
    def low(self):
        self.status.text = "Moving to\nposition low."        
        line = ""

        self.status.text = "Writing line"   
        self.ser.write(b"1")
        
        self.ser.reset_input_buffer()
        self.status.text = "Reading line"

        while True:
            if self.ser.in_waiting > 0:
                line = self.ser.readline()
                line = line.decode("utf-8").rstrip()

                if line == "DONE":
                    self.status.text = "Position low\nreached."
                    break

                else:
                    self.status.text = "An error\noccured."
                    break

class AutoWindow(Screen):
    pass

class WindowManager(ScreenManager):
    pass

kv_builder = Builder.load_file("gui.kv")

class Level_US(App):

    def build(self):
        return kv_builder

if __name__ == "__main__":
    pass