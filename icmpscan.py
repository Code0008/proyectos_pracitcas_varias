import argparse
import sys
import signal
import subprocess
from concurrent.futures import ThreadPoolExecutor
def handler(sig, frame):
    print("Saliendo")
    sys.exit(1)
signal.signal(signal.SIGINT, handler)

def argst():
    parser = argparse.ArgumentParser(description="ESCANER ICMPO")
    parser.add_argument("-t", "--target" , required=True,dest="target" ,help="HOST O RANGO DE HOSTS")

    args=parser.parse_args()

    return args.target

def targets(target_str):
    target_strspit= target_str.split('.')
    threeoctets = '.'.join(target_strspit[:3])

    if len(target_strspit) == 4:
        if '-' in target_strspit[3]:
            start,end = map(int, target_strspit[3].split('-'))
            return [f"{threeoctets}.{i}" for i in range(start, end+1)]
        else:
            return [target_str]
    else:
        print("Pusiste algo mal penejo")

def host_discovery(targete):
        try:
            ping = subprocess.run(["ping", "-c", "1", targete], timeout=1, stdout=subprocess.DEVNULL)
            if ping.returncode == 0:
                print(f"El {targete} esta activa")
        except subprocess.TimeoutExpired:
            pass

def main():
    target_str= argst()
    targete=targets(target_str)
    with ThreadPoolExecutor(max_workers=100) as executor:
        executor.map(host_discovery,targete)
    


if __name__=="__main__":
    main()