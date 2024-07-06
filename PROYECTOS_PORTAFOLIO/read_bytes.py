import struct 
import json 
packed = struct.pack('>i4sh', 7, b'spam', 8)

def see():
    readeable_files = list(packed)
    print(readeable_files)
    readeable_files = [chr(i) for i in readeable_files]
    print(readeable_files)
    readeable_files = [i for i in readeable_files if i.isalpha()]
    for i in readeable_files:
        yield i
#print(bin(256))

name = dict(name="bob", last_name="XD")
rec = dict(name=name, job=["dev","mgr"], age=439)
print(rec)
rec =json.dumps(rec) 
print(type(json.loads(rec)))