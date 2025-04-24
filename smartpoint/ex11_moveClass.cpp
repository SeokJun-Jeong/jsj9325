#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Mydata
{
    private: 
        string data_;
    public:
        Mydata(const string &d): data_(d)
        {
            cout << "복사 생성자 호출" << endl;
        }
        Mydata(const Mydata &data) : data_(data.get_data()){}
        Mydata(const string &&d) noexcept : data_(move(d)) 
        {
            cout << "이동 생성자 호출" << endl;
        }
        const string &get_data()
        {
            return data_;
        }
};

void useMyData(Mydata &&data)
{
    cout << "복사 이동한 Mydata" << endl;
    cout << data.get_data() << endl;
}

void referenceMyData(Mydata &data) 
{
    cout << "레퍼런스 data" << endl;
    cout << data.get_data() << endl;

}

const string &get_data()
{
    
}
int main()
{
    string str = "hello";
    Mydata d1(str);
    Mydata d2(move(str));   //move의 의미가 rvalue를 넘긴다. 소유권을 넘기는 것 x
    Mydata d3(move(str));   //만들어진다 소유권을 넘기는 추가 코드가 있으면 x
    // useMyData(d1);
    useMyData(move(d2));
    referenceMyData(d1);
    return 0;
}