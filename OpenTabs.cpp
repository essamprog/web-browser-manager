#include "OpenTabs.h"

// Habeba Ismail 5

OpenTabs::OpenTabs()
{
    head = NULL;
}

OpenTabs::~OpenTabs()
{
    while (head)
    {
        TabNode* temp = head;
        head = head->next;
        delete temp;
    }
}

bool OpenTabs::isEmpty()
{
    return head == NULL;
}

void OpenTabs::openTab(string url)
{
    TabNode* node = new TabNode(url);
    node->next = head;
    head = node;
}

string OpenTabs::closeTab()
{
    if (!head) return "";

    TabNode* temp = head;
    string closedUrl = head->url;
    head = head->next;
    delete temp;
    return closedUrl;
}

void OpenTabs::display()
{
    TabNode* temp = head;
    while (temp)
    {
        cout << temp->url << endl;
        temp = temp->next;
    }
}

string OpenTabs::getCurrentTab()
{
    if (!head) return "";
    return head->url;
}
