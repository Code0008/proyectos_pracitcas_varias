import tkinter as tk
from tkinter import *
from tkinter import font
from tkinter.scrolledtext import ScrolledText

class Dictionary:

    def __init__(self, main) -> None:
        
        self.main = main

        self.main.geometry("1080x500")
        self.frame3 = Frame(main, bg="RED")
        self.frame3.pack(fill=BOTH,side=LEFT, expand=1, padx=1)
    
        self.textwidget= ScrolledText(self.main, state="disabled")
        self.textwidget.pack(pady=5, padx=5)
        self.textwidget.configure(state="normal")
        self.textwidget.insert(END, """
            ///////////////////////////////////////////////////////
                    EL USO DE ESTA HERRAMIENTA ES PONER PRIMERO
                    LAS KEYWORDS Y LA PALABRA A VERIFICAR
""")
        self.textwidget.configure(state="disabled")

            
        

        self.frame=Frame(main, bg="Purple")
        self.frame.pack(fill=BOTH, expand=1, padx=5)
        
        self.frame2= Frame(main, bg="red")
        self.frame2.pack(fill=BOTH, expand=1, padx=3)



        self.entrywidget = Entry(self.frame)
        self.entrywidget.bind("<Return>")
        self.entrywidget.pack( side=LEFT, fill=BOTH, expand=1, padx=3,pady=3)

        self.entrywidget2 = Entry(self.frame2)
        self.entrywidget2.pack(side=LEFT, fill=BOTH, expand=1, padx=3, pady=4)
        self.list = []
        self.verif = False

    def wordse(self):
        if self.verif == False:
            self.list = self.entrywidget2.get().split(',')
            self.verif = True
        else:
            x=self.entrywidget2.get().split(',')
            if len(x)>=2:
                for i in x :self.list.append(i)

            else:
                self.list.append(self.entrywidget2.get())

        self.entrywidget2.delete(0, END)
        self.textwidget.configure(state="normal")
        self.textwidget.insert(END, f"\n///\t{','.join(self.list)}")
        self.textwidget.configure(state="disabled")

    def verificar(self):
        verificarw=self.entrywidget.get()
        self.entrywidget.delete(0, END)
        self.textwidget.configure(state="normal")
        self.textwidget.insert(END, f"\n//PALABRA A VERIFICAR->>> \t{verificarw}")
        self.textwidget.insert(END, f"\n{self.similar(verificarw)}" )
        self.textwidget.configure(state="disabled")

        self.list=[] 
        self.verif=False
        
    def similar(self, find):
        pcount=0
        dic={}
        for w in self.list:
            for p in w:
                if p in find:
                    pcount+=1
            dic[w]=pcount
            pcount=0
        return dic
    
################

main = tk.Tk()
objeto = Dictionary(main)
main.title("Ralph come pene")
sendbutton = Button(objeto.frame, text="VERIFICAR", command= lambda: objeto.verificar(), font="Consolas 12" )
sendbutton.pack( side=RIGHT, fill=BOTH, pady=3 )
sendbutton2 = Button(objeto.frame2, text="KEYWORDS", command=lambda: objeto.wordse(), font="Consolas 12")
sendbutton2.pack(side=RIGHT, fill=BOTH, pady=3 )
tk.mainloop()
################


