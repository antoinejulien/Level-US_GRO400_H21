from kivy.app import App
from kivy.uix.widget import Widget
from kivy.lang import Builder
from kivy.core.window import Window
from kivy.uix.screenmanager import Screen, ScreenManager

class MenuWindow(Screen):
     pass

class ManualWindow(Screen):
    pass

class AutoWindow(Screen):
    pass

class WindowManager(ScreenManager):
    pass

kv_builder = Builder.load_file("gui\\gui.kv")

class Level_US(App):
    def build(self):
        Window.clear
        Window.size = (480, 320)
        return kv_builder

if __name__ == "__main__":
    #Level_US.run()
    pass