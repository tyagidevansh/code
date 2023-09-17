import pyqrcode
import png
from pyqrcode import QRCode

s = input(print("Enter the string you want to make into a qr"))

url = pyqrcode.create(s)

url.svg("test1.svg", scale = 8)