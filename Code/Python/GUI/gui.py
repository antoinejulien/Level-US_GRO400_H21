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
    
    def high(self):
        self.status.text = "Moving to\nposition high."

    def mid(self):
        self.status.text = "Moving to\nposition mid."

    def low(self):
        self.status.text = "Moving to\nposition low."

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