#ifndef DOWNLOADS_QUEUE_H
#define DOWNLOADS_QUEUE_H
#include <iostream>
using namespace std;
// 4 - Mohamed Ahmed
struct QNode
{
    string data;
    QNode* next;

    QNode(string d)
    {
        data = d;
        next = NULL;
    }
};
class DownloadsQueue
{
private:
    QNode* front;
    QNode* rear;

public:
    DownloadsQueue();
    ~DownloadsQueue();
    void enqueue(string file);
    void dequeue();
    void showDownloads();
    bool isEmpty();
};
#endif