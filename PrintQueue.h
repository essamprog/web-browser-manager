#ifndef PRINTQUEUE_H
#define PRINTQUEUE_H
#include <iostream>
#include <string>
using namespace std;
// Mai Mahmoud 6 - Printer Queue
struct PNode
{
    string doc;
    PNode* next;

    PNode(string d)
    {
        doc = d;
        next = NULL;
    }
};
class PrintQueue
{
private:
    PNode* front;
    PNode* rear;

public:
    PrintQueue();
    ~PrintQueue();
    void addJob(string doc);
    void printJob();
    bool isEmpty();
    void displayQueue();
};
#endif