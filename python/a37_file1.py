# data/text.txt에 write함수로 작성
def main():
    # f = open("data/text.txt","w")
    # print(f.fileno()) # file descriptor
    # f.write("Hello python programming, hi every one.\n")
    # # 표준 IO 함수 fputs fprintf f...
    # f.close()
    
    with open("data/text.txt","a",encoding="utf-8") as f:
        f.write("Hello python second input.\n")
        

if __name__ == "__main__":
    main()