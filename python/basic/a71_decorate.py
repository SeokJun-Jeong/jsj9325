from functools import wraps

def hi(value):
    def mydecorator(func):
        @wraps(func)
        def wrapper(*args, **kwargs):
            print("func 실행 전 코드")
            result = func(*args,**kwargs)
            print("func 실행 후 코드")
            return result
            
        return wrapper

    return mydecorator

@hi("hi")
def print_hello(n,v):
    for _ in range(n):
        print(v)
    return 123
    
    
def main():
    a = print_hello(2, "hello")
    print(print_hello.__name__)
    print(a)
    
if __name__ == "__main__":
    main()