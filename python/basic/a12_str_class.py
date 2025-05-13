def main():
    a = "seokjun"
    b = "SEOKJUN"
    c = "SeokJun"
    print(a.upper())
    print(a)
    print(b.lower())
    print(b)
    print(c.lower())
    print(c)
    c = " jeong  "
    print(c+"end")
    print(c.strip() + 'end')
    print(c.lstrip() + 'end')
    print(c.rstrip() + 'end')
    
    d= "this is a python class in ict, out class is bet of IT class"
    print(d.find("a"))
    print(d[d.find("a")])
    print(d.rfind("a")) # 오른쪽에서 부터 a찾기
    
    idx = int()
    while d.find("a",idx) != -1:
        idx = d.find("a",idx)
        print(idx,end=' ')
        print("")
        idx += 1
        
    f = "TrainA10".isalnum()
    print(f)
    
    f = "Train_A10".isalnum()
    print(f)
    
    f = "10a".isdecimal()
    print(f)
    
    f = "10ff".isspace()
    print(f)
    g = d.split()
    print(g) #d에 속한 글자 띄어쓰기 마다 표시
    
    print("안녕" in "안녕하세요")       #안녕하세요 안에 안녕이있는지 T/F
    print("요요" in "안녕하세요")       #안녕하세요 안에 요요가있는지 T/F
    
    
if __name__ == "__main__":
    main()    
