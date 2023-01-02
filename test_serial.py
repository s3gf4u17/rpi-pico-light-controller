import serial, subprocess

subprocess.run(["sudo","chmod","a+wr","/dev/ttyACM0"])

ser = serial.Serial("/dev/ttyACM0",timeout=1)

string = '0'

#ser.write(string.encode())

while True:
    content=ser.readline()
    print(content)