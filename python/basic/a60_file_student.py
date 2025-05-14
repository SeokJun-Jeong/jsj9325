
class Student:
    def __init__(self, name, korean, math, english, science):
        self.name = name
        self.korean = korean
        self.math = math
        self.english = english
        self.science = science

    def get_sum(self):
        return self.korean + self.math + self.english + self.science

    def get_average(self):
        return self.get_sum() / 4

    def __str__(self):
        return f"{self.name}\t총점: {self.get_sum()}\t평균: {self.get_average():.2f}"


def main():
    students = []
    with open("/home/seokjun/kubig2025/python/basic/student.txt", "r", encoding="utf-8") as f:
        for line in f:
            parts = line.strip().split(",")
            name = parts[0]
            scores = list(map(int, parts[1:]))
            student = Student(name, *scores)
            students.append(student)

    for student in students:
        print(student)
    
  
    
if __name__ == "__main__":
    main()
