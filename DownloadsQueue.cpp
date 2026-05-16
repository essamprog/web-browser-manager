#include "DownloadsQueue.h"

// 4 - Mohamed Ahmed

DownloadsQueue::DownloadsQueue()
{
    front = rear = NULL;
}

DownloadsQueue::~DownloadsQueue()
{
    while (!isEmpty())
        dequeue();
}

void DownloadsQueue::enqueue(string file)
{
    QNode* node = new QNode(file);

    if (!front)
    {
        front = rear = node;
        return;
    }

    rear->next = node;
    rear = node;
}

void DownloadsQueue::dequeue()
{
    if (isEmpty()) return;

    QNode* temp = front;
    front = front->next;
    delete temp;
}

void DownloadsQueue::showDownloads()
{
    if (isEmpty())
    {
        cout << "No files in queue." << endl;
        return;
    }

    QNode* temp = front;
    int i = 1;
    while (temp)
    {
        cout << i << ". " << temp->data << endl;
        temp = temp->next;
        i++;
    }
}

bool DownloadsQueue::isEmpty()
{
    return front == NULL;
}
