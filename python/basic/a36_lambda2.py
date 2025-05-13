def main():

    li = [x for x in range(100)]
    # map 활용 
    output = map(lambda x:x**2,li) # 100까지 제곱
    print(list(output))
    
    #filter활용
    output = filter(lambda x: x < 50,li) # 50이하
    print(list(output))
    output = filter(lambda x: x % 2,li) # 홀수만
    print(list(output))
    
        
    
if __name__ == "__main__":
    main()