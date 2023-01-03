from fastapi import FastAPI
# import serial, subprocess

# subprocess.run(["sudo","chmod","a+wr","/dev/ttyACM0"])

# ser = serial.Serial("/dev/ttyACM0",timeout=1)

app = FastAPI()

# test if connection between backend and frontend works
@app.get("/")
async def root():
    return {"STATUS":"ok"}

# test if all components work (leds and both cores)
@app.get("/test")
async def root():
    try:
        print("testing")
    except:
        return {"STATUS":"error"}
    return {"STATUS":"ok"}

# check stats on work time, alarms triggered etc.
@app.get("/stats")
async def root():
    WORK_TIME=2222
    ARMED_TIME=1111
    TRIGGER_COUNT=7
    TRIGGERS=[
        {'time':'12:30 tue 07.11.2021'},
        {'time':'12:31 tue 07.11.2021'},
        {'time':'12:32 tue 07.11.2021'},
        {'time':'12:33 tue 07.11.2021'},
        {'time':'12:34 tue 07.11.2021'},
        {'time':'12:35 tue 07.11.2021'},
        {'time':'12:36 tue 07.11.2021'},
    ]
    return {"STATUS":"ok","WORK_TIME":WORK_TIME,"ARMED_TIME":ARMED_TIME,"TRIGGER_COUNT":TRIGGER_COUNT,"TRIGGERS":TRIGGERS}

# turn security features on
# @app.post("/arm")#password

# # turn security features off
# @app.post("/disarm")#password

# # listen for triggers
# @app.websocket("/listen")

# green unarmed
# yellow armed
# red armed && detected movement