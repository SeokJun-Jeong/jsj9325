# if elif else 사용하여 현재 시간 오전 오후 계절 표시 
#datetime 모듈 사용
#input받아서 나타나게(시간,월) -> "now" -> now()함수를 불러와 표시
import datetime


def main():
    a = input("몇시 : ")
    b = input("몇월 : ")
    
    if a == "now":
        hour = datetime.now().hour
    else:
        hour = int(a)

    if b == "now":
        month = datetime.now().month
    else:
        month = int(b)
        
    if 0<=hour<12:
        print(f"오전{hour}시")
    else:
        print(f"오후{hour-12}시")    
        
    if b in [3,4,5]:
        print("봄")
    elif b in [6,7,8]:
        print("여름")
    elif b in [9,10,11]:
        print("가을")
    else:
        print("겨울")
        
        
        
if __name__ == "__main__":
    main()
    
    
# import datetime


# def main():
#     user_input = input("시간과 월을 넣어 주세요 (now) 현재 시간-> 시간, 월: ")
#     hour = 0
#     month = 0
#     if user_input == "now":
#         ptime = datetime.datetime.now()
#         hour = int(ptime.hour)
#         month = int(ptime.month)
#     else:
#         hour, month = user_input.split(",")
#         hour = int(hour.strip())
#         month = int(month.strip())

#     if hour < 12:
#         period = "오전"
#     else:
#         period = "오휴"

#     if 3 <= month <= 5:
#         season = "봄"
#     elif month <= 8:
#         season = "여름"
#     elif month <=11:
#         season = "가을"
#     else:
#         season = "겨울"

#     print(f"현재 오전/오후 : {period} 계절 : {season} 입니다.")

# if __name__ == "__main__":
#     main()