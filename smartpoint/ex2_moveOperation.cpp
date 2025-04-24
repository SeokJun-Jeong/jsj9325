#include <iostream>
#include <memory>

using namespace std;

class Myclass
{
public:
    int test_a;
    Myclass()
    { 
        cout << "Myclass 생성" << endl;
        test_a = 100;
    }
    ~Myclass() 
    {
        cout << "Myclass 삭제" << endl;
    }
};

void useUnique(unique_ptr<Myclass> ptr)
{
    cout << "함수 안에서 값 : " << ptr->test_a << endl;
}

int main()
{
    auto p1 = make_unique<Myclass>(); //값이 100
    auto p2 = move(p1); //p1의 소유권을 p2에 넘김 -> p1은 더이상 객체 소유 x

    useUnique(move(p2)); //p2의 소유권을 useunique에 넘김 -> p2은 더이상 객체 소유 x  -> if문에 !p1과 !p2의 값이 나옴

    if (!p1)
    {
        cout << "p1은 nullptr 입니다." << endl;
    }
    else
    {
        cout << "p1이 소유한 값 : " << p1->test_a << endl;
    }
    if (!p2)
    {
        cout << "p2은 nullptr 입니다." << endl;
    }
    else
    {
        cout << "p2이 소유한 값 : " << p2->test_a << endl;
    }
    
    return 0;
}