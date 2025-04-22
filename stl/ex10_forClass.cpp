#include <iostream>
#include <cstddef>

template <typename T, std::size_t N>            //typename에 class사용가능
class MyContainer
{
    private:
        T data_[N];
    public:
        MyContainer()
        {
            for(std::size_t i = 0; i < N; ++i)
            {
                data_[i] = static_cast<T>(i+1);
            }
        }
        class Iter
        {
            private:
                T *ptr;

            public:
                using iterator_category = std::forward_iterator_tag;
                using value_type = T;
                using difference_type = std::ptrdiff_t;
                using pointer = T *;
                using reference = T &;

                explicit Iter(T *p) : ptr(p){}
                reference operator* () const { return *ptr;}
                pointer operator->() {return ptr;}
                Iter& operator++()
                {
                    ++ptr;
                    return *this;
                }
                Iter operator++(int)
                {
                    Iter temp = *this;
                    ++(*this);
                    return temp;
                }
                friend bool operator==(const Iter &a, const Iter &b)        // ==논리연산
                {
                    return a.ptr == b.ptr;
                }
                friend bool operator!=(const Iter &a, const Iter &b)        // !=논리연산
                {
                    return a.ptr != b.ptr;
                }
        };
        Iter begin() { return Iter(data_); }
        Iter end() { return Iter(data_ + N); }
};

using namespace std;
int main()
{
 
    MyContainer<int, 10> container;
    for(auto v : container)
    {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}