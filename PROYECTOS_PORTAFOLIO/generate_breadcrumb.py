#String filtrer wazaaa
import re

def generate_bc(url, separator):
    sep= ''.join(list(re.findall("/(\w+)/\/(\w+)", url)))
    return f'<a href="/"HOME</a> {separator} <a href="/{sep}/">{sep.upper()}</a>'

print(generate_bc("www.codewars.com/users//GiacomoSorbi?ref=CodeWars", " / "))
#<a href="/">HOME</a> / <a href="/users/">USERS</a> / <span class="active">GIACOMOSORBI</span