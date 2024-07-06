import re

def   binario_to_decimal(binario):
    try:
        posicion=0
        decimal=0
        binario = binario[::-1]

        for digito in binario:
            multiplicador = 2**posicion
            decimal += int(digito) * multiplicador
            posicion+=1

        numero=0
        for i in str(decimal):
            numero+=int(i)
        if numero%3==0:
            return True
        else: 
            return False
    except ValueError:     
        return False


def rgb(r, g, b):
    nlst=[]
    for i in [r,g,b]:
        nlst.append(hex(i))
    lesta = (''.join(nlst).upper()).split("0X")
    nw=[]
    for i in lesta:
        if not i:
            continue
        if len(i)<2:
            apend="0"+i
            nw.append(apend)
        else:
            nw.append(i)
    return nw


#['', '94', '0', 'd3']  
#print(rgb(255,255,125))
#_----------------------

class CaesarCipher(object):
    def __init__(self, saltos) -> None:
        self.saltos = saltos
        self.abedecario=[chr(i) for i in range(ord('A'), ord('Z')+1)]

    def encode(self, lista):
        lista= lista.upper()
        encodex=[]
        for i in lista:
            if i in self.abedecario:
                indice = self.abedecario.index(i)
                if indice+self.saltos<26:
                    encodex.append(self.abedecario[indice+self.saltos])
                else:
                    encodex.append(self.abedecario[(indice-27)+self.saltos+1])
            else: continue
        return ''.join(encodex)

    def decode(self, lista):
        lista= lista.upper()
        encodex=[]
        for i in lista:
            if i in self.abedecario:
                indice = self.abedecario.index(i)
                if indice-self.saltos>=0:
                    encodex.append(self.abedecario[indice-self.saltos])
                else: 
                    encodex.append(self.abedecario[(27-indice)-self.saltos+1])
            else: continue
        return ''.join(encodex)
#HTIJFWX
#HTIJBFWX
#HTIJWFWX

c = CaesarCipher(5)
print(c.encode("'H@=#\'>,@ (~HU J:E@ HL\'/{-|>< @"))
