#include <memory>
#include <iostream>

using namespace std;

class B;

class A
{
public:
    int a_var = 100;
    shared_ptr<B> b_ptr;        //소유
    ~A() {cout << "A 소멸" << endl;}
};

class B
{
public:
    int b_var = 200;
    weak_ptr<A> a_ptr;      //참조  둘다 shared_ptr사용시 참조 횟수가 0이 되지 않아 메모리 누수 발생 
    ~B() {cout << "B 소멸" << endl;}
};

int main()
{
    auto a = make_shared<A>();
    auto b = make_shared<B>();
    a->b_ptr = b;
    b->a_ptr = a;
    cout << a->b_ptr->b_var << endl;
    cout << b->a_ptr.lock()->a_var << endl;     //lock을 사용해 weak -> shared로 변환하여 안전하게 사용 (잠깐 소유권을 얻음, 안전한 임시 접근 수단)
    
    return 0;
}