def main():
    abc = str() #str class 클래스로 객체 선언 정식
    abc2 = "hi" #str class 파이썬 약식
    print(type(abc))
    print(type(abc2)) #파이썬에서 빌드인 class에 대해서는 소문자 시작
    abc = 4
    print(type(abc)) 
    abc = 3.14          # float
    print(type(abc))  
    abc= [1,2, "three"] # list  STL벡터와 비슷
    print(type(abc))
    
if __name__== "__main__": 
    main()
    