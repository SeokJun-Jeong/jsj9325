#include <iostream>
#include <vector>

using namespace std;

// class A
// public:
//    class B;


int main()
{
    vector<int>::iterator it;
    vector<int> test_vector = {1, 2, 3, 4, 5, 6};
    for (it = test_vector.begin(); it != test_vector.end(); ++it)       // for문 두번째 방식
    {
        cout << *it << endl;
    }
    
    // iterator가 정의 - begin(), end()
    // *it의 역참조가 가능
    for (auto v : test_vector)  // 세번째 방식 모던 C++
    {
        cout << v << endl;
    }
    for (auto &v : test_vector)  // 컨테이너의 값을 변경
    {
        cout << v << endl;
    }
    for (const auto &v : test_vector)  //메모리 효율적으로 값 참고 할 때
    {
        cout << v << endl;
    }
    
    return 0;
}