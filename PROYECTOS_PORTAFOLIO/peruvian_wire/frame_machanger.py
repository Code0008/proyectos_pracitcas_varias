import tkinter as tk
from tkinter import *
from tkinter.scrolledtext import ScrolledText
from main import call_intefaces
import macc_changer



class Interfaz_dos:
    def __init__(self, destruir) -> None:
        destruir.destroy()
        self.main = tk.Tk()
        self.main.geometry("400x200")
        Interfaz_dos.frames(self)
        Interfaz_dos.botones(self)
        Interfaz_dos.scrol_text(self)
        self.main.mainloop()

    def frames(self):
        self.frame_main = Frame(self.main, background="cyan3", border=2)
        self.frame_macchange = Frame(self.main, background="red", border=2)
        self.frame_scrol =  Frame(self.main, bg="blue", border=2)        
        self.frame_main.pack(fill=BOTH, padx=5, pady=5)
        self.frame_macchange.pack(fill=BOTH, padx=5, pady=5)    
        self.frame_scrol.pack(fill=BOTH, padx=5, pady=5)
    def botones(self):
        boton_test = Button(self.frame_main, text="REGRESAR", bg="blue", foreground="cyan", font=("Verdana", 15), command= lambda: call_intefaces(self.main))
        boton_test.pack(side=LEFT, pady=5, padx=5)
        boton_tes2 = Button(self.frame_macchange, text="realizar mac change", bg="purple", foreground="blue", font=("Verdana", 15),command= lambda: macc_changer.macc_change("aa:bb:cc:44:55:66","ens33"))
        boton_tes2.pack(side=LEFT, pady=5, padx=5)
        
    def scrol_text(self):
        self.scroll_text = ScrolledText(self.frame_scrol)
        self.scroll_text.pack(expand=1, padx=5, pady=5)
        self.scroll_text.configure(state="normal", font="Verdana")
if __name__ == "__main__":
    interfaz = Interfaz_dos('void')