def test():
    print("test A")
    yield 1  #return
    print("test B")
    yield 2  
    print("test C")
    yield 3  

def main():
    print("main A")
    output = test() #return object 만들어 수행    
    
    print("main B")
    a=next(output) #generator 첫 시퀸스 실행
    print(a)
    
    a=next(output) #generator 두번째 시퀸스 실행
    print(a)
    
    a=next(output) #generator 세번째 시퀸스 실행
    print(a)
    


    try:
        a = next(output)
        print(a)
    except StopIteration:
        print("Stop error")
    print("main C")
    
if __name__ == "__main__":
    main()
    