# 웹 스크래핑 -> beatifulsoup bs4
from urllib import request

def main():
    target = request.urlopen("https://ko.wikipedia.org/wiki/%ED%8C%8C%EC%9D%B4%EC%84%A0")
    print(target.read())
    
if __name__ == "__main__":
    main()