import time

def main():
    print(time.asctime())  #
    print(time.time())  #
    print(time.clock_gettime_ns(1)) #
    
    ptime = time.time()
    cnt = int()
    while time.time() < ptime+5:
        cnt += 1
    ptime = time.time()
    for _ in range(10_000_000):
            cnt += 1
    endtime = time.time()
    
    print(f"이 컴퓨터는 5초에 {cnt}카운트 가능")
    print(f"위 작업을 수행할때 {endtime-ptime}초 걸림")
if __name__ == "__main__":
    main()