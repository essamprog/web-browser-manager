#include "BookmarksBST.h"

// Ahmed Fathi 2

BookmarksBST::BookmarksBST()
{
    root = NULL;
}
BNode* BookmarksBST::insert(BNode* node, string url)
{
    if (!node) return new BNode(url);

    if (url < node->url)
        node->left = insert(node->left, url);
    else
        node->right = insert(node->right, url);

    return node;
}
void BookmarksBST::insert(string url)
{
    root = insert(root, url);
}
void BookmarksBST::inorder(BNode* node)
{
    if (!node) return;

    inorder(node->left);
    cout << node->url << endl;
    inorder(node->right);
}
void BookmarksBST::display()
{
    inorder(root);
}
bool BookmarksBST::search(BNode* node, string url)
{
    if (!node) return false;

    if (url == node->url) return true;

    if (url < node->url)
        return search(node->left, url);
    else
        return search(node->right, url);
}
bool BookmarksBST::search(string url)
{
    return search(root, url);
}
int BookmarksBST::count(BNode* node)
{
    if (!node) return 0;
    return 1 + count(node->left) + count(node->right);
}
int BookmarksBST::count()
{
    return count(root);
}
bool BookmarksBST::isEmpty()
{
    return root == NULL;
}
void BookmarksBST::clear(BNode* node)
{
    if (!node) return;
    clear(node->left);
    clear(node->right);
    delete node;
}
void BookmarksBST::clear()
{
    clear(root);
    root = NULL;
}