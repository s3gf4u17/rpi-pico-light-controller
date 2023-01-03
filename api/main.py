from fastapi import FastAPI
import serial, subprocess

subprocess.run(["sudo","chmod","a+wr","/dev/ttyACM0"])

# ser = serial.Serial("/dev/ttyACM0",timeout=1)

app = FastAPI()

# test if connection between backend and frontend works
@app.get("/")
async def root():
    return {"STATUS":"ok"}

# test if all components work (leds and both cores)
@app.get("/test")

# check stats on work time, alarms triggered etc.
@app.get("/stats")

# turn security features on
@app.post("/arm")#password

# turn security features off
@app.post("/disarm")#password

# listen for triggers
@app.websocket("/listen")

# green unarmed
# yellow armed
# red armed && detected movement