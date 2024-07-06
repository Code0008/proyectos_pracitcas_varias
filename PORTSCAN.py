import socket
from termcolor import colored
import argparse
import threading
import signal
from concurrent.futures import ThreadPoolExecutor
import sys

socket_conexion=[]

def handler(sig, frame):
    print(colored("Saliendo del programa tingling", 'red'))

    for socket in socket_conexion:
        socket.close()
    sys.exit()

signal.signal(signal.SIGINT, handler)

# ARGUMENTOS Y PANEL DE AYUDA
def get_arguments():
    parser = argparse.ArgumentParser( description=' FAST TCP PORT SCANNER')
    parser.add_argument("-t", "--target",required=True ,dest="target", help="VICTIM TARGET TO SCAN")
    parser.add_argument("-p", "--port",required=True ,dest="port", help="PORT RANGE")
    options = parser.parse_args()
    return options.target, options.port
# ARGUMENTOS Y PANEL DE AYUDA
#lOGICA DE ESCANEO DE PUERTOS

    #CREACION DE LA CONECION POR SOCKET TCP
def make_connection():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.settimeout(0.5)
    socket_conexion.append(s)
    return s
    #lOGICA DE ESCANEO DE PUERTOS

    #ESCANEO DE LOS PUERTOS
def port_scanner(port, target ):
    s=make_connection()
    try:
        s.connect((target,port))
        s.sendall(b"HEAD / HTTP/1.0 \r\n\r\n")
        response = s.recv(1024)
        response = response.decode(errors='ignore').split('\n')
        if response:
            print(colored(f"El puerto //{port}// Esta abierto", "green"))
            for line in response:
                print(colored(f"{line}", "cyan"))
        else:
            print(colored(f"El puerto ||{port} esta abiero"))
    except (socket.timeout, ConnectionRefusedError):
        pass
    finally:
        s.close()
    #lOGICA DE ESCANEO DE PUERTOS

    #LLAMADA A LA CREACION DE LOS OBJETOS A ESCANEAR
def scan_port(ports, target):
    with ThreadPoolExecutor(max_workers=50) as executor:
        executor.map(lambda port: port_scanner(port, target), ports)

    #LLAMADA A LA CREACION DE LOS OBJETOS A ESCANEAR

    #LECTURA DEL PARAMETRO -P --PORTS
def port_interartor(port):
    if '-' in port:
        stard,end=map(int, port.split('-')) 
        return range(stard, end+1)
    elif ',' in port:
        return map(int, port.split(','))
    else:
        return (int(port),)
    #LECTURA DEL PARAMETRO -P --PORTS

#lOGICA DE ESCANEO DE PUERTOS

def main():
    target, port = get_arguments()
    ports = port_interartor(port)
    scan_port(ports, target)

if __name__=='__main__':
    main()