def afunc():
    a = 10
    b = 20
    return a,b

def main():
    #iterable하고 list와 차이가 없다
    # tuple -> 불변 자료형
    a = tuple()
    b = 123
    c = a,b
    print(type(c))
    
    #swap
    a = 10
    b = 20
    a,b = b,a # (a,b) = (b,a) <- 소괄호 생략, tuple자료형
    print(a,b)
    print(afunc())
    for ele in afunc():
        print(ele)
    
      
if __name__ == "__main__":
    main()