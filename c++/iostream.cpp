#include <iostream>

int main()
{
    std::cout << "hello, world" << std::endl;

    // std::cout << "hello, world";
    operator<<(std::cout, "hello, world");    //<< c에서는 비트연산 c++에서는 출력
    // std::cout.operator<<("hello, world");

    //std::cout << std:endl;
    // operator<<(std::cout, std::endl);
    std::cout.operator<<(std::endl);

    operator<<(std::cout, "hello, world").operator<<(std::endl);     //5번 라인과 같이 함수 호출

    return 0;
}