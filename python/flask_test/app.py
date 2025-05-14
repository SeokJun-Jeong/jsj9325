#웹 프레임 워크 back-end -> 핸드폰 연동가능
#flask run -> 웹 공부를 하고 싶으면 검색
#jdango flaks fastapi
#gradio(머신러닝.. openUI.. )
#streamlit(대시보드)
#dash(데이터 시각화)
#GUI프로그램
#QT pythonQT, tkinter -> window 프로그램
#pygame, matplotlib
#windows OS -> C# MSC(c++) linux -> SDL, vulkan
#Unity, unreal 
#AI 관련 라이브러리
#numpy, pandas, matplotlib, tensorflow(keras), pytorch, sk-learn(머신러닝)
#orange3
from flask import Flask
import redis

app = Flask(__name__)
cache = redis.Redis(host='redis', port= 6379)

def get_hit_count():
    while True:
        try:
            return cache.incr('hits')
        except redis.exceptions.ConnectionError as exc:
            
    
    
@app.route('/')

def hello():
    return "<h1>Hello world"
