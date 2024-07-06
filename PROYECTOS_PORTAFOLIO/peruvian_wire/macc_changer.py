import subprocess
import re 
import make_logs

def macc_verif(mac=None, interface=None) -> bool: 
    interface = re.match(r'[e][t|n][h|s]\d[1-3]$', interface)
    mac = re.match(r'^([A-Fa-f0-9]{2}[:]){5}[A-Fa-f0-9]{2}$', mac)
    if (interface != None and mac != None):  return True
    else: False

def macc_change(mac, interface):
    if macc_verif(mac, interface):
        try:
            #-----TRAZA-----#
            print("TEST PASED")
            #-----TRAZA-----#
            #subprocess.run(["ifconfig", interface, "down"])
            #subprocess.run(["ifconfig", interface, "hw", "ether", mac])
            #subprocess.run(["ifconfig", interface, "up"])
        except Exception as e:
            make_logs.make_logos(e)
            return f"OCURRRIO UN ERROR REVISAR EL ARCHIVO 'LOGS.TXT'"
    else: 
        return f"MAC GUARDADA -> {mac} \nINTEFAZ -> {interface}"


if __name__ == "__main__":
    #-----TRAZA-----#
    print(macc_change("aa:bb:cc:44:55:66","ens33"))