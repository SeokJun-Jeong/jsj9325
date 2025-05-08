def main():
    print(a:=range(10)) # :=코끼리문 대입과 동시에 값 사용
    print(a.count(2)) #2번째 수 = 1
    print(a.step)  #1씩증가
    print(a.index(1)) # 
    print(list(a)) # a리스트
    
    for i in range(10):
        print(f"{i+1}번째 출력")

    list_a = ["choi",123, 3.3]
    for ele in list_a:
        print(f"원소의 값은 {ele}입니다")
        
    for i,ele in enumerate(list_a):
        print(f"{i+1}번째 원소의 값은 {ele} 입니다")
        
    num = [0,1,2]
    
    for ele, i in zip(list_a, num):
        print(f"{i+1}번째 원소의 값은 {ele}입니다")
    
if __name__ == "__main__":
    main()