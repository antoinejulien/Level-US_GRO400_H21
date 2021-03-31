import time
import serial

from modules import comm

from kivy.app import App
from kivy.clock import Clock
from kivy.config import Config
from kivy.core.window import Window
from kivy.lang import Builder
from kivy.properties import ObjectProperty
from kivy.uix.screenmanager import Screen, ScreenManager
from kivy.uix.widget import Widget
from kivy.uix.popup import Popup

Config.set("graphics", "window_state", "maximized")
ser = comm.serialport("COM3", 115200, 1)

bidon = 0

class PortPopup(Popup):
    pass

class DummyWindow(Screen):
    def on_enter(self):
        Clock.schedule_once(self.switch_screen)

    def switch_screen(self, dt):
        self.manager.current = "menu"

class MenuWindow(Screen):
    def __init__(self, **kwargs): 
        super(MenuWindow, self).__init__(**kwargs)
        self.port_status = ObjectProperty(None)
        self.reco_button = ObjectProperty(None)

    def check_port(self):
        if ser.test_comm():
            self.port_status.text = "Port connected"
            self.reco_button.opacity = 0.75
            self.reco_button.disabled = True
        else:
            self.port_status.text = "No port detected"
            self.reco_button.opacity = 1
            self.reco_button.disabled = False

    def reconnect(self):
        global ser
        ser = comm.serialport("COM3", 115200, 1)
        self.check_port()

    def goto_manual(self):
        if ser.test_comm():
            Level_US.WindowManager.current = "ManualWindow"
        else:
            PortPopup().open()

class ManualWindow(Screen):
    def __init__(self, **kwargs): 
        super(ManualWindow, self).__init__(**kwargs)
        self.status = ObjectProperty(None)

    def high(self):
        self.status.text = "Moving to\nposition high."
        msg = ""

        self.status.text = "Writing line"
        ser.write(b"3")
        ser.reset_input_buffer()

        self.status.text = "Reading line"
        
        msg = ser.read()

        if msg == "DONE":
            self.status.text = "Position high\nreached."

        else:
            self.status.text = "An error\noccured."

class AutoWindow(Screen):
    def __init__(self, **kwargs): 
        super(AutoWindow, self).__init__(**kwargs)

        self.x_value = ObjectProperty(None)

    def auto_mode(self,dt):
        global bidon
        bidon += 1

        if bidon >= 10:
            self.x_value.text = "Last test " + str(bidon)
            return False

        self.x_value.text = "Test " + str(bidon)

        
        

    def start_auto(self):
        Clock.unschedule(self.auto_mode)
        Clock.schedule_interval(self.auto_mode, 1)

    def stop_auto(self):
        global bidon
        bidon = 0

        self.x_value.text = "Stopped"
        Clock.unschedule(self.auto_mode)  

class WindowManager(ScreenManager):
    pass

kv_builder = Builder.load_file("Level_US.kv")

class Level_US(App):

    def __init__(self):
        super(Level_US, self).__init__()

    def build(self):
        return kv_builder

if __name__ == "__main__":
    Level_US().run()