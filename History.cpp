#include "History.h"

// Ziad Hassan 1

History::History()
{
    head = NULL;
}

void History::insert(string url)
{
    HistoryNode* node = new HistoryNode(url);
    node->next = head;
    head = node;
}

void History::display()
{
    HistoryNode* temp = head;

    while (temp)
    {
        cout << temp->url << endl;
        temp = temp->next;
    }
}
