#include "PrintQueue.h"

// Mai Mahmoud 6 - Printer Queue

PrintQueue::PrintQueue() {
    front = NULL;
    rear = NULL;
}
PrintQueue::~PrintQueue() {
    PNode* current = front;
    while (current != NULL) {
        PNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    front = rear = NULL;
}
void PrintQueue::addJob(string doc) {
    PNode* node = new PNode(doc);

    if (front == NULL) {
        front = rear = node;
    }
    else {
        rear->next = node;
        rear = node;
    }
    cout << "[Queue] Paper added: " << doc << endl;
}
bool PrintQueue::isEmpty() {
    return front == NULL;
}

void PrintQueue::printJob() {
    if (isEmpty()) {
        cout << "[!] No jobs to print." << endl;
        return;
    }
    PNode* temp = front;
    cout << ">> Printing: " << temp->doc << "..." << endl;

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }
    delete temp;
}
