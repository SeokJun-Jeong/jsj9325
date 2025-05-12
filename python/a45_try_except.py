import traceback

def main(): 
    user_input = input("정수 입력:")
    
    try:
        number = int(user_input)
        
    except ValueError as e:
        print("정수를 입력하시 않았습니다")    
        print(e) #에러메세지
        traceback.print_exc()#에러가 일어난 코드 알려줌
        
    else:
        print("반지름", number)
        print("넓이", 3.141592*number*2)
        
    finally:
        print("프로그램 종료")
        
        
if __name__ == "__main__":
    main()
    
    
    
    