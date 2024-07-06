import base64
import struct
M = [[1,2,3],
     [4,5,6],
     [7,8,9]]

columns = []
diagonals=[]


for i in range(len(M)):
    columns.append([row[i] for row in M])

for i in range(len(M)):
    diagonals.append(M[i][i])

count=0

hexed = []
x="me gusta jilari"
hexed = [hex(ord(i)+5) for i in x]
hexed = ''.join([''.join(hexede.split("0x")).upper() for hexede in hexed])

text = hexed.encode()
print(hexed)

printe= base64.b16decode(text)
print(printe)


