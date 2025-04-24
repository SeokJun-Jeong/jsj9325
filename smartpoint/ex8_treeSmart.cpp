#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct TreeMode
{
    int value;
    vector<shared_ptr<TreeMode>> children;
    TreeMode(int val) : value(val) {}
};

void printTree(const shared_ptr<TreeMode>& node, int depth=0)
{
    if (!node)
    {
        return;
    }
    cout << std::string(depth*2, ' ') << node->value << endl;
    for (const auto& child : node->children)
    {
        printTree(child, depth+1);
    }
    
}

int main()
{
    auto root = make_shared<TreeMode>(1);
    root->children.push_back(make_shared<TreeMode>(2));
    root->children.push_back(make_shared<TreeMode>(3));
    root->children.push_back(make_shared<TreeMode>(4));
    root->children[0]->children.push_back(make_shared<TreeMode>(5));
    printTree(root);
    return 0;
}