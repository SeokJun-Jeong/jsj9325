def main():
    print(10 == 100)
    print(10 != 100)
    
    print(not True)
    print(not(10<100))
    
    if True: #무조건 실행
        print("True입니다")
    
    if  False:
        print("False입니다")
    
    while True:
        a = int(input("100보다 큰 숫자 입력"))
        if a == 0:
            break
        
        if a>200:
            print(a, "는 200보다 큽니다", sep="")
        
        elif a>100:
            print(a, "는 100보다 크고 200보다 작습니다", sep="")
        else:
            print(a, "는 100보다 작습니다", sep="")

if __name__ == "__main__":
    main()