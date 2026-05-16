#ifndef HISTORY_H
#define HISTORY_H

#include <iostream>
using namespace std;
// Ziad Hassan 1 - SLL History
struct HistoryNode
{
    string url;
    HistoryNode* next;
    HistoryNode(string u)
    {
        url = u;
        next = NULL;
    }
};
class History
{
private:
    HistoryNode* head;

public:
    History();
    void insert(string url);
    void display();
};

#endif
