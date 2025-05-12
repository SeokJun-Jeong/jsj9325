class Minuserror(Exception):
    def __init__(self,e):
        super().__init__()
        self.args = [e]
    
def main():
    li = list(range(0,101,5))
    while True:
        try:
            input_int = int(input("정수 입력 (1~21까지) 0->break: "))
            if not input_int:
                break
            if input_int < 0:
                raise Minuserror("마이너스 에러")
            print(f"이 리스트의 {input_int-1}요소는 {li[input_int-1]}입니다")
        
        except ValueError as e: #에러 처리
            print(e)
            print("정수만 입력")
        
        except IndexError as e :
            print(e)
            print("0~21까지만 입력")
            
        except KeyboardInterrupt:
            print("키보드")
            break
        except Minuserror as e:
            print(e)
            print("음수")
if __name__ == "__main__":
    main()
    