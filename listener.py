import serial

ser=serial.Serial('/dev/ttyACM0',timeout=2)

while True:
    content=ser.readline()
    print(content)