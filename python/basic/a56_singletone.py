class Singleton:
    _instance = None #class변수
    
    def __new__(cls, *args, **kwargs):
        if cls._instance is None:
            cls._instance= super().__new__(cls)    
        return cls._instance
    
    def __init__(self,a):
        try: #예외처리하고싶을때 사용
            print(f"기본값{self.a}")
                
        except:
            pass
        self.a = a
        print(f"변경값{self.a}")
    
    
def main():
    a= Singleton(10)
    b= Singleton(20)
    print(id(a), id(b))
    print(a == b)
    
if __name__ == "__main__":
    main()