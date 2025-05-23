#include <memory>
#include <cstdio>
#include <iostream>

using namespace std;

class FileCloser
{

public:
    void operator()(FILE *fp)
    {
        if (fp)
        {
            cout << "fclose 동작" << endl;
            fclose(fp);
        }
    }
};

void useUnique(unique_ptr<FILE, FileCloser> ptr)
{
    cout << "fp를 받아서 사용한 함수" << endl;
}

int main()
{
    auto fp = fopen("/home/seokjun/kubig2025/stl/1000.txt","r");
    unique_ptr<FILE, FileCloser> filePtr(fp);
    // ....file 관련된 코드
    //  ... 2..
    // fclose(fp);
    useUnique(move(filePtr));
    cout << "main함수의 끝" << endl;
    return 0;
}