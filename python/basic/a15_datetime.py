import datetime
import test_package
class Myclass:
    def __str__(self):
        return "test my class"
# 1.PATH PYTHONPATH에 있는 .py 파일들 대상 불러오기
# 2. package가 임포트
# 3. .so파일을 임포트(dynamic loading) <-C 모듈만들기(C파이썬) -> GIL우회
#    .(pyi(stub) .so) -> github. -> 실행속도 빠름   ||  병렬처리
#     GIL global interpreter lock -> PVM
    
def main():
    ptime =  datetime.datetime.now()
    print(ptime)  # __str__ 오버로딩이 되어 나온다
    
    myclass = Myclass()
    print(myclass)
    
    print(ptime.month)
    print(f"{ptime.year}년 {ptime.month}월 {ptime.day}일")
    
if __name__ == "__main__":
    main()