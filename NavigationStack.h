#ifndef NAVIGATION_STACK_H
#define NAVIGATION_STACK_H
#include <iostream>
using namespace std;
// Ali Ashraf 3 - Back/Forward Stack
struct StackNode
{
    string data;
    StackNode* next;
    StackNode(string d)
    {
        data = d;
        next = NULL;
    }
};
class NavigationStack
{
private:
    StackNode* topNode;
public:
    NavigationStack();
    void push(string value);
    void pop();
    string top();
    bool isEmpty();
};
#endif