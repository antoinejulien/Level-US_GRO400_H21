import time
import serial

from modules import comm
from modules.anglePlaqueToAngleMoteur_c import getAngles_cffi
from modules.anglePlaqueToAngleMoteur_c.getAngles import getAngles

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

height = float(220)

popupWindow = Popup(title ="Port error", content = Builder.load_file("popup.kv"),
                    size_hint =(0.5, 0.5))

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
        if ser.test_comm() == True:
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
            App.get_running_app().root.current = "manual_window"
        else:
            popupWindow.open()
    
    def goto_auto(self):
        if ser.test_comm():
            App.get_running_app().root.current = "auto_window"
        else:
            popupWindow.open()

class ManualWindow(Screen):
    def __init__(self, **kwargs): 
        super(ManualWindow, self).__init__(**kwargs)
        self.x_value = ObjectProperty(None)
        self.y_value = ObjectProperty(None)
        self.h_value = ObjectProperty(None)
        self.i_value = ObjectProperty(None)

        self.qty = 1

    def add(self, axis):
        if axis == "x":
            self.x_value.text = str(int(self.x_value.text) + self.qty)
        elif axis == "y":
            self.y_value.text = str(int(self.y_value.text) + self.qty)
        elif axis == "h":
            self.h_value.text = str(int(self.h_value.text) + self.qty)
        elif axis == "i":
            self.i_value.text = str(int(self.i_value.text) + 1)
            self.qty = int(self.i_value.text)
        
    def substract(self,axis):
        if axis == "x":
            if int(self.x_value.text)-self.qty >= -35:
                self.x_value.text = str(int(self.x_value.text) - self.qty)
        elif axis == "y":
            if int(self.y_value.text)-self.qty >= -35:
                self.y_value.text = str(int(self.y_value.text) - self.qty)
        elif axis == "h":
            if int(self.h_value.text)-self.qty >= 0:
                self.h_value.text = str(int(self.h_value.text) - self.qty)
        elif axis == "i":
            if int(self.i_value.text)-1 >= 1:
                self.i_value.text = str(int(self.i_value.text) - 1)
                self.qty = int(self.i_value.text)

    def send(self):
        sendX = float(self.x_value.text)
        sendY = float(self.y_value.text)
        sendH = float(self.h_value.text)

        anglesMoteurs = getAngles(sendX, sendY, sendH)

        angles = [0, 0, 0]
        for i, angle in enumerate(anglesMoteurs,0):
            angles[i] = round(angle,2)

        ser.encode(0, angles)    

class AutoWindow(Screen):
    def __init__(self, **kwargs): 
        super(AutoWindow, self).__init__(**kwargs)

        self.x_value = ObjectProperty(None)
        self.y_value = ObjectProperty(None)
        self.h_value = ObjectProperty(None)

        self.motor1_value = ObjectProperty(None)
        self.motor2_value = ObjectProperty(None)
        self.motor3_value = ObjectProperty(None)

    def auto_mode(self,dt):
        try:
            global height
            angles = [0, 0, 0]
        

            ser.write(ser.encode(1, angles))
            
            [angleX, angleY] = ser.decode(ser.read())

            anglesMoteurs = getAngles(float(angleX), float(angleY), height)

            for i, angle in enumerate(anglesMoteurs,0):
                angles[i] = round(angle,2)

            ser.encode(0, angles)

            self.update_labels([angleX, angleY, angles[0], angles[1], angles[2]])
        except:
            self.stop_auto()
            App.get_running_app().root.current = "menu"


    def start_auto(self):
        Clock.unschedule(self.auto_mode)
        Clock.schedule_interval(self.auto_mode, 0.055)

    def stop_auto(self):
        Clock.unschedule(self.auto_mode)

    def update_labels(self, data):
        self.x_value.text = str(data[0])
        self.y_value.text = str(data[1])
        self.h_value.text = str(height)
        self.motor1_value.text = str(data[2])
        self.motor2_value.text = str(data[3])
        self.motor3_value.text = str(data[4])


class WindowManager(ScreenManager):
    pass
    def __init__(self, **kwargs): 
        super(WindowManager, self).__init__(**kwargs)

kv_builder = Builder.load_file("Level_US.kv")

class Level_US(App):

    def __init__(self):
        super(Level_US, self).__init__()

        Clock.unschedule(self.check_connection)
        Clock.schedule_interval(self.check_connection, 1)

    def build(self):
        return kv_builder

    def check_connection(self, dt):
        App.get_running_app().root.get_screen("menu").check_port()   

if __name__ == "__main__":
    Level_US().run()