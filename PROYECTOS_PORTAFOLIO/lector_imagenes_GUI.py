import tkinter as tk
from tkinter import *
from tkinter import filedialog
from tkinter.scrolledtext import ScrolledText
import pytesseract as tess
from PIL import Image

tess.pytesseract.tesseract_cmd =r'C:\Program Files\Tesseract-OCR\tesseract.exe'

class Interfaz():
    def __init__(self, main) -> None:
        self.main=main
        self.main= tk.Tk()
        self.main.geometry("1000x800")
        self.main.configure(bg="blue")
        self.scroll_text = ScrolledText(self.main, state="disabled")
        self.scroll_text.configure(bg="cyan3", font=("Verdana", 15))
        self.scroll_text.pack(fill=BOTH, expand=1, padx=5,pady=5)
        self.frame1 = Frame(self.main, bg="red")
        self.frame1.pack(fill=BOTH, expand=1,padx=5, pady=5)
        self.boton_path = Button(self.frame1,text="Seleccione la ruta", command=lambda:Interfaz.ask_ruta(self), font=("Verdana", 20))
        self.boton_path.pack(side=LEFT, padx=5, pady=5)
        self.boton_show = Button(self.frame1, text="MOSTRAR IMAGEN", command=lambda: Interfaz.show_image(self), font=("Verdana", 20))
        self.boton_show.pack(side=LEFT, padx=5, pady=5)
        self.boton_mostrar_contenido = Button(self.frame1, text="MOSTRAR CONTENIDO", command= lambda:Interfaz.read_image(self), font=("Verdana", 20))
        self.boton_mostrar_contenido.pack(side=LEFT, padx=5, pady=5)
        self.main.mainloop()

    def ask_ruta(self):
        self.scroll_text.configure(state="normal")
        self.path = filedialog.askopenfilename()
        try:
            self.my_image = Image.open(rf"{self.path}")
            if self.path:
                self.scroll_text.insert(END,f"\n-------------------------------------------------------------\nLa ruta que escogiste es: {self.path}\n-------------------------------------------------------------\n")
            else:
                self.scroll_text.insert(END, f"\n------------------------------------------------------------\nNo se ingreso ruta!!!!! \n-------------------------------------------------------------\n")
        except Exception as e :
            self.scroll_text.insert(END,"\n NO SE INGRESO EL FORMATO DE IMAGEN CORRECTA: ")    
        finally:
            self.scroll_text.configure(state="disabled")

    def show_image(self):
        self.scroll_text.configure(state="normal")
        try:
            self.my_image.show()
        except Exception as e:
            self.scroll_text.insert(END, f"\n------------------------------------------------------------\nNo se ingreso ruta!!!!! \n-------------------------------------------------------------\n")
        finally:
            self.scroll_text.configure(state="disabled")
    def read_image(self):
        self.scroll_text.configure(state="normal")
        try:
            text = tess.image_to_string(self.my_image)
            if text:
                self.scroll_text.insert(END, f"\n------------------------------------------------------------\nCONTENIDO \n-------------------------------------------------------------\n")
                self.scroll_text.insert(END, f"\n{text}")
                self.scroll_text.insert(END, f"\n------------------------------------------------------------\nCONTENIDO \n-------------------------------------------------------------\n")
            else:
                self.scroll_text.insert(END, f"\n------------------------------------------------------------\nAl parecer no tiene o no se puede leer \n-------------------------------------------------------------\n")
        except Exception as e:
            self.scroll_text.insert(END, f"\n------------------------------------------------------------\nERROR EN EL PROCESO \n-------------------------------------------------------------\n")
        finally:
            self.scroll_text.configure(state="disabled")


if __name__=="__main__":
    interfaz= Interfaz("main")


