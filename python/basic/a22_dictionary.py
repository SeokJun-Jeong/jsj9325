def main():
    dict_a = dict() #dict
    dict_b = {1:1,2:2,3:3} #dict
    dict_c = {1,2,3} #set
    
    print(type(dict_a), type(dict_b),type(dict_c))
    
    a = 'd'
    dict_d = {'a':100, 'b':200, 'c':300, a:400}  #위에 a = 'd'를 추가하지 않을시 네임에러
    print(dict_d["a"])
    dict_d["d"] = 500 #데이터 덮어씌우기
    print(dict_d["d"])
    dict_d["e"] = 600 #데이터 추가
    print(dict_d)
    # print(dict_d["f"]) #f가없으므로 keyerror
    print(dict_d.get("f")) #안전한 접근 (none)
    
    
if __name__ == "__main__":
    main()