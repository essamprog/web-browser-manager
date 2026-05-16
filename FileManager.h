#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Martin Nader 7 - File I/O

class FileManager
{
public:
    void saveHistory(const string& url);
    void saveBookmark(const string& url);
    vector<string> loadHistory();
    vector<string> loadBookmarks();
};

#endif
