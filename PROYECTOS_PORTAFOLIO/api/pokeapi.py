#Poke API xDDDD

import requests
import json

url= "https://pokeapi.co/api/v2/"
consult_url  = requests.get(f'{url}pokemon/ditto')

print(json.loads(consult_url.text))




