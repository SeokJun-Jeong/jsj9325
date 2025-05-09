def print_n_times(*args,n=2,**kwargs): #main n을 지우고 n을 넣어 반복문 가능
    print(type(args)) #tuple
    print(type(kwargs)) #dict
    print(args)
    for k,v in kwargs.items():
        # n = kwargs.get("n") 
        if n:  
            for _ in range(n):
                print(f"{k} : {v}")

def main():
    print_n_times("hi",123,3.145, a=3, b=4, abc="fuckyou")
    
if __name__ == "__main__":
    main()