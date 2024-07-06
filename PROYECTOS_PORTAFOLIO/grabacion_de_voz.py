import sounddevice as sd
from scipy.io.wavfile import write

fs = 44100 #frecuencia
secs = 12 #duracion de grabacion

voice_record = sd.rec(int(secs * fs), samplerate=fs, channels=2)
sd.wait()

write("output.wav", fs, voice_record)

