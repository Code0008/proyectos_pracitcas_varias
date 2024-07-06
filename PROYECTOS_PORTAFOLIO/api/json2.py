import json

names = dict(first='Insano', last='Skibidi')

print(names)

rec = dict(name=names, job=['Mewing', 'Chad', 'Sigma'], age=40.3)

do = json.dump(rec, fp=open('PROYECTOS_PORTAFOLIO/api/testjson2.json', 'w'), indent = 4)

read = json.load(open('PROYECTOS_PORTAFOLIO/api/testjson.json'))


print(read)

if 1<3: {print(False)}; print('xd'); 


















