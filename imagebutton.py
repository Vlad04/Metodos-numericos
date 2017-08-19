from kivy.app import runTouchApp
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.popup import Popup
from kivy.uix.image import Image
from kivy.lang import Builder


kv = '''
BoxLayoutWithPopup:
    orientation:'horizontal'
    spacing:10
    padding:5
    Button:
        text: 'CALCULATE'
        size_hint:.3,.3
        on_press:
            root.pop1()
'''


class BoxLayoutWithPopup(BoxLayout):

    def pop1(self):
        pop = Popup(title='test', content=Image(source='rplot.jpg'),
                    size_hint=(None, None), size=(400, 400))
        pop.open()


if __name__ == '__main__':
    runTouchApp(Builder.load_string(kv))
