def main():
    li = [i for i in range(101) if i % 2 == 0] #짝  
    print(li)
    li = [i+1 for i in range(101) if i % 2 == 0] #홀
    print(li)
    li = [(i+1) ** 2 for i in range(101) if i % 2 == 0] #홀값 제곱한거
    print(li)

if __name__ == "__main__":
    main()