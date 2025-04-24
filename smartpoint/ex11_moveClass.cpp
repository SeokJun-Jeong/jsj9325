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
        Mydata(const Mydata &data) : data_("100"){}
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
    Mydata d2(move(str));
    // useMyData(d1);
    useMyData(move(d2));
    referenceMyData(d1);
    return 0;
}