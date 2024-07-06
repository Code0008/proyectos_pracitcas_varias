import frame_machanger
import tkinter as tk
from tkinter import * 
from tkinter.scrolledtext import ScrolledText


class Interfaz_main:
    def __init__(self) -> None:
        self.main = tk.Tk()
        self.main.geometry("400x200")
        self.main.title("Interfaz principal")
        Interfaz_main.frame_botones(self)
        self.main.mainloop()
        
    def frame_botones(self):
        self.boton_uno = Button(self.main, text="PRESIONANDO BOTON", bg="cyan3", font=("Verdana", 15), command= lambda: Interfaz_main.funcion_newinterface(self) )
        self.boton_uno.pack(side=LEFT, pady=5, padx=5)
    
    def funcion_newinterface(self):
        x=frame_machanger.Interfaz_dos(self.main)

def call_intefaces(ventana=None):
    if ventana!=None:
        ventana.destroy()
    interfaz_principal  = Interfaz_main()

if __name__ == '__main__':
    call_intefaces()