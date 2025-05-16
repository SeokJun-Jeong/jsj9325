class Test:
    def __init__(self, name):
        self.name = name
        print(f"{self.name} - 생성 되었습니다")
        
    def __del__(self):
        print(f"{self.name} - 파괴 되었습니다")
        
def main():
    a = Test("A")
    b = Test("B")
    c = Test("C")
    print(a,b,c)
    li = [a,b,c]
    del li[2]
    # del c # C 작동하지 않고 소멸
    #컨테이너 안의 원소를 제거시 컨테이너 포함을 제거 후 원소 제거
    #원소만 제거시 컨테이너 안에는 남이있다
    #컨테이너 안을 제거시 원소는 남아있다
    print(li)
    print(c)
    
if __name__ == "__main__":
    main()