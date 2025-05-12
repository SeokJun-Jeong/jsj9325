def main():
    with open("data/text.txt","r", encoding="utf-8")as f:
        # str = f.read()
        # sentences = str.split("\n")
        # for line in sentences:
        #     print(line+" // per line")
            
        # print(str)
        #첫번째
        
        # lines = f.readlines()
        # for line in lines:
        #     print(line + " // per line")
        #두번째
        
        while(line := f.readline()):
                print(line)
        #세번째
if __name__ == "__main__":
    main()