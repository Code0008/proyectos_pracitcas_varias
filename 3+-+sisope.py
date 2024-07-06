import os

print("Ubicacion archivo python: " + os.getcwd())
os.chdir("C:/Users/Zerskers/Desktop/curso")
print("Ubicacion actual: " + os.getcwd())
print(os.listdir(os.getcwd()))