cnt = 0
dictionary = {1:1,2:2}

def fibonacci(n):
    global cnt #전역 변수 명시
    cnt += 1
    
    if n in dictionary:
        return dictionary[n]
    
    else:
        output = fibonacci(n-1) + fibonacci(n-2)
        dictionary[n] = output
        return output
    
def main():
    global cnt
    print(fibonacci(400))
    print(f"fibonacci가 수행된 횟수 {cnt}")
    
if __name__ == "__main__":
    main()