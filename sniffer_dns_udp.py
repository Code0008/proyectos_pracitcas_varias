 #dns sniffer para ver el trafico de red
import scapy.all as scapy
 
 
def procces_dns_packet(packet): # con esta funcion recibe un paquete aplicando un tratamiento o lo que queremos manipularga
     if packet.haslayer(scapy.DNSQR):
         domain = packet[scapy.DNSQR].qname.decode() 
 
         exclude = ["google", "cloud", "bing", "static"]
         
         if domain not in domains_seen: #and not any(keyword in domain for keyword in exclude):
             domains_seen.add(domain)
             print(f"Dominio: {domain}")
         
 
def main():
     global domains_seen
     domains_seen = set()
     interface = "ens33" # marcamos la interfaz de red que usaremos 
     scapy.sniff(iface=interface, filter="udp and port 53", prn= procces_dns_packet, store=0)
 
 
 #puede servir para reconocimiento de subdominios 
 # api.twitch -> dominio twitch subdominio api
 # porn.twitch -> dominio twitch subdominio porn
 # aprneder el tipo de contewnido del packet[]
if __name__ == '__main__':
    main()