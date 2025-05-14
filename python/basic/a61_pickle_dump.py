import random
import pickle
from a58_method import Student

def main():
    hanguls = list("최강박이손정적고구류오김송곽유")
    hanguls2 = list("가나다라마바사아자차카파타하길진재형준석화섭윤진")
    with open("/home/seokjun/kubig2025/python/basic/student_b.pickle", "wb") as f:
        for _ in range(100):
            data = Student(
                random.choice(hanguls) + "".join(random.choices(hanguls2, k=2)),
                random.randint(65, 100),
                random.randint(65, 100),
                random.randint(65, 100),
                random.randint(65, 100),
            )
            pickle.dump(data,f)
    
    
if __name__ == "__main__":
    main()