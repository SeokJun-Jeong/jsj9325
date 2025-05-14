#student 58번의 학생 총점 평균이 실행마다 랜덤
# 고정적인 데이터로 100명의 학생을 처리하는 프로그램 만들기
# 1. 데이터 생성후 저장 하는 프로그램 100명
# 2. student.txt를 읽어 클래스 생성 후 처리하는 프로그램


import random

def generate_name():
    hanguls = list("최강박이손정적고구류오김송곽유")
    hanguls2 = list("가나다라마바사아자차카파타하길진재형준석화섭윤진")
    return random.choice(hanguls) + "".join(random.choices(hanguls2, k=2))

def generate_score():
    return random.randint(65, 100)

def main():
    with open("/home/seokjun/kubig2025/python/basic/student.txt", "w", encoding="utf-8") as f:
        for _ in range(100):
            name = generate_name()
            scores = [generate_score() for _ in range(4)]  # 국, 수, 영, 과
            line = f"{name},{','.join(map(str, scores))}\n"
            f.write(line)

if __name__ == "__main__":
    main()
