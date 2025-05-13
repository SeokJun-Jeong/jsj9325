def main():
    list_a = [1,2,3]
    list_b = [4,5,6]
    print(list_a + list_b)
    print(list_a, list_b)
    
    list_a.extend(list_b) # list_a에 list_b리스트 추가
    print(list_a,list_b) 
    
    list_a = list_a * 4
    print(len(list_a))   #list_a 리스트가 4배되어 24
    print(list_a)
    list_b.append(7) #7추가
    list_b.append(8)
    print(list_b)    
    list_b.insert(3,0)
    print(list_b)
    list_b.insert(4,6.5) # 4번째에 6.5추가
    print(list_b)
    list_b.remove(7) #7제거
    print(list_b)
    print(list_b.pop()) #리스트 마지막 숫자 표시 후 삭제
    print(list_b)
    del list_b[0] #0번째 숫자 삭제
    print(list_b)
    
if __name__ == "__main__":
    main()
