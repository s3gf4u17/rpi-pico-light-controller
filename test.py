from fastapi import FastAPI, WebSocket, WebSocketDisconnect
from fastapi.responses import HTMLResponse

import serial, subprocess

app = FastAPI()
subprocess.run(['sudo','chmod','a+wr','/dev/ttyACM0'])
ser=serial.Serial('/dev/ttyACM0',timeout=2)
with open("template.html","r") as f: html=f.read()

@app.get("/")
async def get():
    return HTMLResponse(html)

@app.websocket("/ws")
async def websocket_endpoint(websocket: WebSocket):
    await websocket.accept()
    while True:
        #data = await websocket.receive_text()
        try:
            data = await websocket.receive_text()
            send="0123456789012345"
            ser.write(send.encode())
            content = ser.readline().decode()
            await websocket.send_text(f"Message text was {content}")
        except WebSocketDisconnect:
            break