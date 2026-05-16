#ifndef BOOKMARKS_BST_H
#define BOOKMARKS_BST_H
#include <iostream>
using namespace std;
// Ahmed Fathi 2 - BST
struct BNode
{
    string url;
    BNode* left;
    BNode* right;

    BNode(string u)
    {
        url = u;
        left = right = NULL;
    }
};
class BookmarksBST
{
private:
    BNode* root;

    BNode* insert(BNode* node, string url);
    void inorder(BNode* node);
    bool search(BNode* node, string url);
    int count(BNode* node);
    void clear(BNode* node);

public:
    BookmarksBST();
    void insert(string url);
    void display();
    bool search(string url);
    int count();
    bool isEmpty();
    void clear();
};
#endif