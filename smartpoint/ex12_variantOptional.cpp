//  g++ -std=c++17 ex12_variantOptional.cpp -o ex12_variantOptional
#include <variant>
#include <string>
#include <iostream>

using namespace std;
int main()
{   
    variant<int, string> data;   //데이터가 하나의 메모리에 저장될 때, 타입이 여러가지일 경우
    data = 42;
    cout << get<int>(data) << endl;
    data = string("hello");
    cout << get<string>(data) << endl;

    optional<int> maybeInt; //값이 있을 수도 없을 수도 있음
    maybeInt = 10;
    return 0;
}   