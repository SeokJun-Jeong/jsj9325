import pickle

from a58_method import Student

def main():
    students: list[Student] = []
    with open("/home/seokjun/kubig2025/python/basic/student_b.pickle", "rb") as f:
        try:
            while data := pickle.load(f):
                students.append(data)
        except EOFError:
            pass
            

    for student in students:
        print(student.__str__())

    print(students[0], students[1])
    print(students[0] > students[1])
    print(students[0] == students[1])
    print(students[0] < students[1])
if __name__ == "__main__":
    main()