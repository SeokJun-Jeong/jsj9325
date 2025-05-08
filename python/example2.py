# 섭씨 화씨 변환 프로그램 input -> casting -> 연산 -> 출력
def main():
    bo = True
    input_celsius = input("온도 : ")
    for i in input_celsius.split('.'):
        if not i.isdigit():
            bo = False
        if bo:
            print(f"썹씨 온도 {input_celsius} 의 화씨 온도는 {float(input_celsius)*1.8+32:.2f} 입니다.")
        else:
            print("다시적어 씨발아")
    
if __name__ == "__main__":
    main()