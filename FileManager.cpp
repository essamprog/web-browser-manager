#include "FileManager.h"
#include <fstream>
#include <string>
// Martin Nader 7 - File I/O
using namespace std;
void FileManager::saveHistory(const string& url)
{
    fstream MyFile2;

    MyFile2.open("history.txt", ios::out | ios::app);
    if (MyFile2.is_open()) {
        MyFile2 << url << endl;
        MyFile2.close();
    }
}
void FileManager::saveBookmark(const string& url)
{
    ofstream file("bookmarks.txt", ios::app);
    if (file.is_open()) {
        file << url << endl;
        file.close();
    }
}
vector<string> FileManager::loadHistory()
{
    vector<string> historyList;
    ifstream file("history.txt");
    string url;
    if (file.is_open()) {
        while (getline(file, url)) {
            historyList.push_back(url);
        }
        file.close();
    }
    return historyList;
}
vector<string> FileManager::loadBookmarks()
{
    vector<string> bookmarkList;
    ifstream file("bookmarks.txt");
    string url;
    if (file.is_open()) {
        while (getline(file, url)) {
            bookmarkList.push_back(url);
        }
        file.close();
    }
    return bookmarkList;
}