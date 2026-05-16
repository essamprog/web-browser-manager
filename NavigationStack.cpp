#include "NavigationStack.h"
// Ali Ashraf 3
NavigationStack::NavigationStack()
{
    topNode = NULL;
}
void NavigationStack::push(string value)
{
    StackNode* node = new StackNode(value);
    node->next = topNode;
    topNode = node;
}
void NavigationStack::pop()
{
    if (isEmpty()) return;

    StackNode* temp = topNode;
    topNode = topNode->next;
    delete temp;
}
string NavigationStack::top()
{
    if (isEmpty()) return "";
    return topNode->data;
}
bool NavigationStack::isEmpty()
{
    return topNode == NULL;
}