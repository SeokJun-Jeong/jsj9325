def main():
    i=int()
    while i <10:
        print(f"{i+1}번째 실행중")
        i += 1
    li = [1,2,3,4,2,4,2]
    
    while 2 in li:
        print("제거중")
        li.remove(2) #2만날때마다 제거
    print(li)

    string_a = "this is a python class in jorudae"
    
    while "i" in string_a:
        string_a = string_a.replace("i","a") # i를 a로 교체
    print(string_a)

    li = [1, 2, 3, 4, 2, 4, 2]
    for number in li:
        if number > 3:
            print(number, end= " ")
    print()
    
    for number in li:
        if number > 3:
            continue # 4부터 33라인 실행 후 다음루프 진행
        print(number, end=" ")
    print()
        
    
    for number in li:
        if number > 3:
            break #4부터 33라인 뒤의 루프는 안돌아감
        print(number, end=" ")
    print()
        
if __name__ == "__main__":
    main()