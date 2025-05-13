def print_n_times1(value: str, n: int = 2):
    for _ in range(n):
        print(value)

def print_n_times2(a,b,c, *value: str, n: int = 2):
    print(a,b,c)
    for _ in range(n):
        print(value)

def print_n_times3(a,b,c, n=2):
    for _ in range(n):
        print(a,b,c)
        
def main():
    print_n_times1("버러지년1") #int = 2이므로 2번나옴
    print_n_times1("버러지년",n=5)
    print_n_times1("버러지년",5)
    
    print_n_times2(12,34,56,"abc","def",n=5) #가변매게가 끼면 순서 못 바꿈
    
    print_n_times3(b=3,a=1,c=2)
    print_n_times3(n=3, a=1,c=2,b=5)#순서바꾸기가능
    #positional argument, default argument, variable-length argument(*),
    
if __name__ == "__main__":
    main()