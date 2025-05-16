class Parent:
    def __init__(self,value):
        self.value = "부모 클래스"
        self.value2 = value
        print("Parent클래스 __init__ 메소드 실행")
        
    def test(self):
        print("Parent클래스의 test메소드")
        
class Child(Parent):
    def __init__(self,value):
        super().__init__(value)
        print("child 클래스의 __init__메소드 실행")
    
    def child_test(self):
        print("Child 클래스의 메소드 실행")
    
    def test(self):
        super().test()
        print("이것은 Child의 test메소드")

def main():
    child = Child("123")
    child.test()
    print(child.value2)
    print(child.__dict__)
    print(child.__dir__())
    print(Child.mro()) #python에서 제공
    
if __name__ == "__main__":
    main()