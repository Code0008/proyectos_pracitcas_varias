#import scapy.all as scapy
#import subprocess
#from scapy.layers import http
import subprocess
import re
import tkinter as tk
from tkinter import * 
from tkinter.scrolledtext import ScrolledText


class Funcionalidades: #Clase de con los metodos de funcionalidades en todo el programa

    def mac_change(new_mac, interface):
        #interfaces = re.match(r'[e][n|t][s|h]\d[1-3]$', interface)
        #correct_mac = re.match(r'^([A-Fa-f0-9]{2}[:]){5}[A-Fa-f0-9]{2}$', new_mac)
        subprocess.run(["ifconfig,", interface, "down"])
        subprocess.run(["ifconfig", interface, "hw", "ehter", new_mac])
        subprocess.run(["ifconfig", interface, "up"])

class INTERFAZ_GRAFICA: #Interfaz graifca
    def __init__(self) -> None:
        herramientas = Funcionalidades()
        self.main= tk.Tk()
        self.main.geometry("1000x800")
        INTERFAZ_GRAFICA.frame_scrolled_text(self)
        INTERFAZ_GRAFICA.frame_macchange(self)
        INTERFAZ_GRAFICA.scrolled_text(self)
        self.main.mainloop()    
    def scrolled_text(self):
        self.scrolled_text = ScrolledText(self.frame_scroll, state="disabled" )
        self.scrolled_text.configure(state = "normal")
        self.scrolled_text.insert(END, f"FUNCIONES: \n -> MACCCHANGE")
        self.scrolled_text.configure(state = "disabled")
        self.scrolled_text.pack(fill=BOTH, expand=1, pady=5, padx=5)     
    def frame_scrolled_text(self):
        self.frame_scroll = Frame(self.main, bg="cyan3")
        self.frame_scroll.pack(fill=BOTH,expand=1, padx=5, pady=5)    

    def frame_macchange(self):
        self.frame_botones=Frame(self.main, bg="red", border=2)
        self.frame_botones.pack(fill=BOTH,side=LEFT,expand=1, pady=5, padx=5)
        self.boton_new_mac_interfaz = Button(self.frame_botones, text="VERIFICAR", bg="blue", font=("Verdana", 20), border=3, 
                                             command= lambda: verif_mac(self) )
        self.boton_new_mac_interfaz.pack(side=LEFT, padx=3, pady=3)
        self.entrada_mac = Entry(self.frame_botones)
        self.entrada_mac.pack(side=LEFT, padx=5, pady=5)
        def verif_mac(self):
            mac_interfaz =self.entrada_mac.get().split("|")
            interfaces = re.match(r'[e][n|t][s|h]\d[1-3]$', mac_interfaz[0])
            correct_mac = re.match(r'^([A-Fa-f0-9]{2}[:]){5}[A-Fa-f0-9]{2}$',mac_interfaz[1])
            
        

  

            
  


if __name__ == '__main__':
    GUI= INTERFAZ_GRAFICA()

