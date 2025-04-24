#include <iostream>
#include <thread>
#include <mutex> //mutually exclusive

using namespace std;

int counter = 0;
mutex mtx;

void increment()
{
    for (int i = 0; i < 1000; ++i)
    {
        lock_guard<mutex> lock(mtx);
        ++counter;
           
    }
    
}

int main()
{
    thread t1(increment);
    thread t2(increment);
    // execution.
    // ...
    t1.join();  //t1에서 실행되는 상황이 끝나면 대기
    // execution - main.끝 t1 끝난상황
    t2.join();  //t2에서 실행되는 상황이 끝나면 대기
    // execution - main thread. t1 thread. t2 thread. 끝난상황
    cout <<"최종 카운터 값 : " << counter << endl;
}