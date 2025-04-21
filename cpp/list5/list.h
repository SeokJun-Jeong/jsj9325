#ifndef LIST_H
#define LIST_H
#include <iostream>
struct Node
{
    int data;
    Node *next;
};


class list
{
   friend std::ostream& operator<<(std::ostream& out, const list& rhs);
private:
    Node *ptr;
public:

    list();
    ~list();

    void insertFirstNode(int data);
    void insertNode(int prevData, int data);
    void deleteNode(int data);

};


// void printList(const List *pList);

#endif