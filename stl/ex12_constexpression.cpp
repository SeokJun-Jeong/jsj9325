#include <iostream>

using namespace std;
constexpr int square(int x) {return x * x;}

template<typename T>
auto process(T value)
{
    if constexpr (is_integral_v<T>)
    {
        return value + 1;
    }
    else
    {
        return value + 0.5;
    }
}
int main()
{
    constexpr int result = square(5);
    cout << result << endl;       //25 (5*5)
    cout <<process(10) << endl;    // int -> if(true)
    cout << process(5.6) << endl;   // float  -> if(false)   
    return 0;
}