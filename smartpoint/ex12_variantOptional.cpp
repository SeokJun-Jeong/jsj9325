//  g++ -std=c++17 ex12_variantOptional.cpp -o ex12_variantOptional
#include <variant>
#include <string>
#include <iostream>
#include <any>
#include <optional>

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
    if (maybeInt)
    {
        cout  << *maybeInt << endl;
    }
    
    any anything = 123; //모두 넣을 수 있다
    cout << any_cast<int>(anything) << endl;
    anything = string("hi");
    // cout << any_cast<단어관련함수>(anything) << endl;
    anything = 1.1;
    cout << any_cast<double>(anything) << endl;
    return 0;
}   