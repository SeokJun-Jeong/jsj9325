#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Task
{
private:
  
public:
    string name;
    int priority;

    // other 대신 rhs(right hand side) lhs(left hand side) 가능
    bool operator<(const Task& other) const
    {
        return priority > other.priority; //내림차순
    }
};

int main()
{
    priority_queue<Task> scheduler;

    scheduler.push({"Write report",2});
    scheduler.push({"Fix bug",3});
    scheduler.push({"Email team",1});
    
    cout << "작업 처리 순서" << endl;
    while (!scheduler.empty())
    {
        Task t = scheduler.top();
        scheduler.pop();
        cout << t.name << "우선순위" << t.priority << endl;
    }
    
     return 0;
}
