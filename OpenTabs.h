#ifndef OPENTABS_H
#define OPENTABS_H
#include <iostream>
using namespace std;
// Habeba Ismail 5 - Open Tabs (SLL simple)
struct TabNode
{
    string url;
    TabNode* next;
    TabNode(string u)
    {
        url = u;
        next = NULL;
    }
};
class OpenTabs
{
private:
    TabNode* head;

public:
    OpenTabs();
    ~OpenTabs();
    void openTab(string url);
    string closeTab();
    bool isEmpty();
    string getCurrentTab();
    void display();
};

#endif
