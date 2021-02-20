from kivy.app import App
from kivy.uix.widget import Widget
from kivy.lang import Builder
from kivy.uix.screenmanager import Screen, ScreenManager

class MenuWindow(Screen):
     pass

class ManualWindow(Screen):
    pass

class AutoWindow(Screen):
    pass

class WindowManager(ScreenManager):
    pass

kv_builder = Builder.load_file("gui.kv")

class MyApp(App):
    def build(self):
        return kv_builder

if __name__ == "__main__":
    MyApp().run()