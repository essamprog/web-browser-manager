#ifndef BROWSER_MANAGER_H
#define BROWSER_MANAGER_H

#include <iostream>
#include "History.h"
#include "NavigationStack.h"
#include "DownloadsQueue.h"
#include "BookmarksBST.h"
#include "Security.h"
#include "Analytics.h"
#include "FileManager.h"
#include "PrintQueue.h"
#include "OpenTabs.h"

using namespace std;

// Essam Mohamed 10 - Integration

class BrowserManager
{
private:
    string currentPage;

    History history;
    NavigationStack backStack;
    NavigationStack forwardStack;
    DownloadsQueue downloads;
    BookmarksBST bookmarks;
    Security security;
    Analytics analytics;
    FileManager fileManager;
    PrintQueue printer;
    OpenTabs tabs;

public:
    BrowserManager();

    void visitURL(string url);
    void goBack();
    void goForward();
    void addBookmark();
    void downloadFile(string file);
    void showMenu();
    void showHistory();
    void showBookmarks();
    void printCurrentPage();
    void processPrinting();
    void showTabs();
    void closeCurrentTab();
};

#endif
