from mitmproxy import http
from urllib.parse import urlparse
def request():
    url = "https://onlyfans.com/miakalifa.porno"
    parsed_url = urlparse(url)
    print(f"Tipo {parsed_url.scheme} \n dominio {parsed_url.netloc} \n ruta:  {parsed_url.path}")

if __name__ == "__main__":
    request()
