def test():
    print("함수가 호출")
    yield test  #return

def main():
    print("A")
    test() #return object 만들어 수행    
    
    print("B")
    test()
    print(test())
    
if __name__ == "__main__":
    main()
    