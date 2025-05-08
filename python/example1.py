# 파이썬으로 구구단 출력
def main():

    for i in range(2,10):
        print(f"{i}단 입니다") 
        for j in  range(1,10):
            print(i,'*',j,'=',i*j)  
    
if __name__ == "__main__":
    main()
    