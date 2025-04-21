#include <iostream>
#include <vector>

using namespace std;
int main()
{
    vector<int> v;

    v.push_back(1);  
    v.push_back(11);  
    v.push_back(111);  
    v.push_back(1234);  
    v.push_back(12345);  
    
    // cout << "v의 첫번째 원소는 : " << v[0] << endl;
    // cout << "v의 두번째 원소는 : " << v[1] << endl;
    // cout << "v의 세번째 원소는 : " << v[2] << endl;
    
    // vector<int>::iterator it;
    auto it = v.begin() + 2; //3번째
    v.erase(it);    //111삭제
    v.at(0) = 2;    //원소에 접근하여 변경
    //for문을 쓰는 첫번째
    for (int i = 0; i < v.size(); ++i)
    {
        cout <<"v의" << i+1 << "번째의 원소는 : " << v.at(i) << endl;
    }
    
    return 0;
}