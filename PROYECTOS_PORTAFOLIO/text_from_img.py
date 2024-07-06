#OCR Optical Character Recognition
#extraer texto de una imagen 

import pytesseract as tess
from PIL import Image
import cv2
tess.pytesseract.tesseract_cmd = r'C:\Program Files\Tesseract-OCR\tesseract.exe'


#my_image = Image.open(r'D:\RALPH INSANO KBRO.png')
my_image = cv2.imread(r'D:\RALPH INSANO KBRO.png')
text = tess.image_to_string(my_image)
print(text)


## Mantener la iamgen en pantalla
