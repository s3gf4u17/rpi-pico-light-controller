from fastapi import FastAPI

app = FastAPI()

@app.get("/")
async def root():
    return {"STATUS":"ok"}

@app.get("/green/status")
async def root():
    return {"ligth":"on"}

@app.get("/red/status")
async def root():
    return {"light":"off"}

@app.get("/yellow/status")
async def root():
    return {"light":"on"}

@app.post("/green/{status}")
async def root():
    return {"REQUEST":"ok"}

@app.post("/red/{status}")
async def root():
    return {"REQUEST":"ok"}

@app.post("/yellow/{status}")
async def root():
    return {"REQUEST":"ok"}