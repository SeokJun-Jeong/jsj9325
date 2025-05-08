b = [1,2,3, 'four']

def main():
    a = 123
    print("locals : ", locals())
    print("varsmain : ",vars(main))
    print("globals : ",globals())
    

if __name__== "__main__": 
    main()
    