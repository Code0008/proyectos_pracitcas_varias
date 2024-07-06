
import tkinter as tk
from tkinter import messagebox, filedialog
class EditorTexto():
    def __init__(self, ventana) -> None:
        self.ventana=ventana 
        self.text_area = tk.Text(self.ventana) 
        self.text_area.pack(fill=tk.BOTH, expand=1) 
        self.current_open='' 
    
    def open_file(self):
        filename = filedialog.askopenfilename()
        if filename:
            self.text_area.delete("1.0", tk.END)
            with open(filename, 'r', encoding='utf8' ) as file:
                self.text_area.insert('1.0', file.read()) 
            self.current_open = filename 
    def quit(self):
        if messagebox.askokcancel("SALIR", "VAS SALIR TINGLING INSANIN?"):
            self.ventana.destroy()
    def guardar(self):
        x = self.text_area.get("1.0", tk.END) 
        filesave = filedialog.asksaveasfilename() 
        print(filesave)
        with open(filesave, 'w', encoding='utf8') as newfile:
            newfile.write(x)

ventana = tk.Tk() 
ventana.geometry("800x600")

editor=EditorTexto(ventana) 

menubar= tk.Menu(ventana,tearoff=0) 
ventana.config(menu=menubar) 
menu1= tk.Menu(menubar, tearoff=0)
menubar.add_cascade(label="archivo",menu=menu1) 
menu1.add_command(label="Nuevo")
menu1.add_command(label="abrir", command=editor.open_file) 
menu1.add_command(label="guardar", command=editor.guardar)
menu1.add_command(label="salir", command=editor.quit)

ventana.mainloop()