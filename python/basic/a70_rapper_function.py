def simple_rapper(func):
    def wrapper():
        print("func 실행 전 코드")
        func()
        print("func 실행 후 코드")
        
    return wrapper

def print_hello():
    print("print_hello함수 발동")
    
    
def main():
    print("aa")
    wrapper = simple_rapper(print_hello)
    wrapper()
    wrapper()

if __name__ == "__main__":
    main()