#include <iostream>
#include <utility>
using namespace std;

void process(string &&s)    //&& = move나 forward를 받음 (move작동 가능)
{
    // s = "hi";
    cout << "Rvalue: 참조: " << s << endl;
}

void wrapper(string &&s)
{
    process(forward<string>(s));
}

int main()
{
    wrapper(string("hello, world"));
    return 0;
}