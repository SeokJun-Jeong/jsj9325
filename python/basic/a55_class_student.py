# class를 활용하한 a54
import random

class Student:
     def __init__(self, name, korean, math, english, science): 
         # *this = self (this -> member1) cpp에서는 생략가능 파이썬에서는 인스턴스 변수는 self를 반드시 붙여야 한다
        self.name= name
        self.korean= korean
        self.math= math
        self.english= english
        self.science= science

def student_get_sum(student: Student):
    return student.korean + student.math + student.english + student.science


def student_get_average(student, num):
    return student_get_sum(student) / num


def student_to_string(student, num):
    return f'{student.name}\t{student_get_sum(student)}\t{student_get_average(student, num):.2f}'

def main():
    hanguls = list("최강박이손정적고구류오김송곽유")
    hanguls2 = list("가나다라마바사아자차카파타하길진재형준석화섭윤진")
    students = [
        Student(
            random.choice(hanguls) + "".join(random.choices(hanguls2, k=2)),
            random.randint(65, 100),
            random.randint(65, 100),
            random.randint(65, 100),
            random.randint(65, 100)
        )
        for _ in range(50)
    ]
    for student in students:
        print(student_to_string(student, 4))


if __name__ == "__main__":
    main()