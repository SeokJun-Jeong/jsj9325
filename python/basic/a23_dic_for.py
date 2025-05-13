def main():
    dict_a = dict() #dict
    list_A = ["시발","새끼"]
    dict_b = {1:1,2:2,3:3} #dict
    dict_c = {1,2,3} #set
    
    print(type(dict_a), type(dict_b),type(dict_c))
    
    a = 'd'
    dict_d = {'a':100, 'b':200, 'c':300, a:400}  #위에 a = 'd'를 추가하지 않을시 네임에러
    # for i in dict_d:
    #     print(i,dict_d[i],end="")
    for k,v in dict_d.items():
        print(k,v,end=", ")
    print()
    
    dict_b.update(dict_d) #내부 데이터가 변하는 메소드
    print(dict_b)
    
    del dict_b[3] #3번째 삭제
    print(dict_b)
    print(list_A)
    del list_A #완전삭제
    # print(list_A)
    print(dict_b.pop(2)) #2번째 출력후 삭제
    print(dict_b)

    
if __name__ == "__main__":
    main()