import datetime

def main():
    #선언
    list_a = list()
    list_b = [1,2,[3,4,5]]
    print(type(list_a), type(list_b))
    
    ptime = datetime.datetime.now()
    list_c = [1,2,3.14,"jeong",ptime]
    
    print(list_c[3], list_c[4])
    print(list_b[1:5])
    print(list_b[2][1], list_b[2][2])
    
if __name__ == "__main__":
    main()