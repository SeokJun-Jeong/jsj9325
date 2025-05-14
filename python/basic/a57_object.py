from collections.abc import Iterable
import random

class TestClass:  # class TestClas(object):
    pass

def main():
    t1 = TestClass()
    
    if  isinstance(t1,TestClass):
        print("t1은 TestClass의 객체")
    if isinstance(1,TestClass):
        print("int(1)은 TestClass의 객체")
    else:
        print("int(1)은 TestClass의 객체X")
        
    if issubclass(int, TestClass):
        print("int는 TestClass를 상속받았다")
    else:
        print("int는 TestClass를 상속받지않았다")
    
    if issubclass(list,Iterable):
        print("list는 interable를 상속받았다")
    else:
        print("list는 interable를 상속받지않았다")
    
    if issubclass(TestClass,object):
        print("testclass는 object를 상속받았다")
    else:
        print("testclass는 object를 상속받지않았다")
    
    print(
        issubclass(int,object),
        issubclass(float,object),
        issubclass(list,object),
        issubclass(dict,object),
        issubclass(tuple,object),
        issubclass(str,object),
        issubclass(random.random,object))
    
if __name__ == "__main__":
    main()
