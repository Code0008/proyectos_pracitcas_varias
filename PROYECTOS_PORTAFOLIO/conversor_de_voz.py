#conversor de voz a texto
import speech_recognition as sr

r = sr.Recognizer() #creamos la instancia

with sr.Microphone() as source: # tratamos con microfone indifcando a python que usaremos nuestro micro predeternmminado
    print("Escuchando")
    audio= r.listen(source) # capturara audio hasta que se detecte silencio
    try:
        text = r.recognize(audio) #usaremos el recognizer de google para convertirlo en texto
        print(text)
    except Exception as e:
        print(e)

#se necesita apikey para que funcione
