import serial,subprocess

subprocess.run(['sudo','chmod','a+wr','/dev/ttyACM0'])

ser=serial.Serial('/dev/ttyACM0',timeout=2)

while True:
    content=ser.readline()
    print(content)