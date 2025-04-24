#include <vector>
#include <iostream>
#include <future>
#include <chrono>
#include <thread>
using namespace std;

int slowAdd(int a, int b)
{
    for (int i = 0; i < 5; ++i)
    {
        cout << "slowAdd 실행 중" << endl;
        this_thread::sleep_for(chrono::milliseconds(400000));
    }
    return a + b;
}


int main()
{
    vector<future<int>> result;
    for (int i = 0; i < 4; ++i)
    {
        future<int> result = async(slowAdd,i+1,3);
    }
    
    cout << "계산 중 ..." << endl;
    for (int i = 0; i < 4; ++i)
    {
        cout << "결과 : " << result[i].get() << endl;
    }
    
    return 0;
}