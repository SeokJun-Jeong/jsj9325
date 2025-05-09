def print_3_time():  #PyTypeObject 무조건 리턴됨
    print("함수 정상 작동")
    print("씨발")
    print("새끼")
    print("반갑다")

def print_n_times(value: str, n: int):
    print("함수 정상 작동")
    print(type(value))
    if not isinstance(n,int):
        print("에러")
        return


    
def print_n_times_variable(n:int, *value: tuple[str]):
    print("함수 정상 작동")
    print(type(value))
    if not isinstance(n,int):
        print("에러")
        return
    for _ in range(n):
        for ele in value:
            print(ele, end=" ")
        print()

def main():
    print_3_time()
    print()
    print_3_time()
    print()
    print_n_times("느금마",5)
    print_n_times("느금마", "five") # 힌트 에러
    print_n_times_variable(7,"니","엄","마")


if __name__ == "__main__":
    main()