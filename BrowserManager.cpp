#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "BrowserManager.h"
#include <iomanip>
#include <iostream>

using namespace std;

// Essam Mohamed 10

void displayBrowserUI(string url, bool isBookmarked = false)
{
    system("cls");

    const int WIDTH = 56;

    string star = isBookmarked ? " [*]" : "";

    string tabText = " " + (url.length() < 12 ? url : url.substr(0, 9) + "...") + star + "   ";
    string topControls = "- [] X";

    string addressText = "  [<] [>] [R]  Address: https://" + url;
    if (addressText.length() > WIDTH) {
        addressText = addressText.substr(0, WIDTH - 3) + "...";
    }

    string welcomeText = "         Welcome to " + (url.length() < 25 ? url : url.substr(0, 22) + "...");

    cout << "__________________________________________________________" << endl;
    cout << "|" << left << setw(WIDTH - topControls.length()) << tabText << topControls << "|" << endl;
    cout << "==========================================================" << endl;
    cout << "|" << left << setw(WIDTH) << addressText << "|" << endl;
    cout << "==========================================================" << endl;
    cout << "|" << left << setw(WIDTH) << " " << "|" << endl;

    if (url.find("google") != string::npos) {
        cout << "|" << left << setw(WIDTH) << "                      G O O G L E" << "|" << endl;
        cout << "|" << left << setw(WIDTH) << "    ----------------------------------------------" << "|" << endl;
        cout << "|" << left << setw(WIDTH) << "   |   Search Google or URL              AI Mode  |" << "|" << endl;
        cout << "|" << left << setw(WIDTH) << "    ----------------------------------------------" << "|" << endl;
    }
    else {
        cout << "|" << left << setw(WIDTH) << " " << "|" << endl;
        cout << "|" << left << setw(WIDTH) << welcomeText << "|" << endl;
        cout << "|" << left << setw(WIDTH) << " " << "|" << endl;
    }

    cout << "|" << left << setw(WIDTH) << " " << "|" << endl;
    cout << "==========================================================" << endl;
}

void displayDownloadUI(string filename)
{
    system("cls");

    cout << "\n==========================================================\n";
    cout << "                    FILE DOWNLOADER                       \n";
    cout << "==========================================================\n\n";
    cout << "                      ________ \n";
    cout << "                     |-----   |\\ \n";
    cout << "                     |------- |_\\ \n";
    cout << "                     |-----   |  \n";
    cout << "                     |---     |  \n";
    cout << "                     |________|  \n";

    cout << "\n              Downloading: " << filename << "\n\n";

    for (int i = 0; i <= 20; i++)
    {
        cout << "\r      Progress: [";

        for (int j = 0; j < i; j++) cout << "#";
        for (int j = i; j < 20; j++) cout << ".";

        cout << "] " << (i * 5) << "%";
        Sleep(300);
    }

    cout << "\n\n       Download Completed Successfully!\n";
    cout << "==========================================================\n";

    Sleep(1500);
    system("cls");
}

BrowserManager::BrowserManager()
{
    currentPage = "www.google.com";
    backStack.push(currentPage);

    vector<string> savedHistory = fileManager.loadHistory();
    for (int i = 0; i < savedHistory.size(); i++) {
        history.insert(savedHistory[i]);
    }

    vector<string> savedBookmarks = fileManager.loadBookmarks();
    for (int i = 0; i < savedBookmarks.size(); i++) {
        bookmarks.insert(savedBookmarks[i]);
    }


}

void BrowserManager::visitURL(string url)
{
    if (!security.validate(url))
    {
        cout << "\n[!] Blocked: " << url << " is restricted or invalid.\n";
        return;
    }

    currentPage = url;
    tabs.openTab(url);

    history.insert(url);
    backStack.push(url);
    analytics.analyzeDomain(url);
    fileManager.saveHistory(url);

    while (!forwardStack.isEmpty())
        forwardStack.pop();

    displayBrowserUI(currentPage);
}

void BrowserManager::goBack()
{
    if (backStack.isEmpty()) return;

    string current = backStack.top();
    backStack.pop();

    if (backStack.isEmpty())
    {
        backStack.push(current);
        cout << "\n[!] Already at the first page.\n";
        return;
    }

    forwardStack.push(current);
    currentPage = backStack.top();

    displayBrowserUI(currentPage);
}

void BrowserManager::goForward()
{
    if (forwardStack.isEmpty()) {
        cout << "\n[!] No forward history.\n";
        return;
    }

    string next = forwardStack.top();
    forwardStack.pop();
    backStack.push(next);

    currentPage = next;

    displayBrowserUI(currentPage);
}

void BrowserManager::addBookmark()
{
    bookmarks.insert(currentPage);
    fileManager.saveBookmark(currentPage);

    displayBrowserUI(currentPage, true);

    cout << "Bookmarked: " << currentPage << " [Added to Favorites]" << endl;
}

void BrowserManager::downloadFile(string file)
{
    downloads.enqueue(file);
    displayDownloadUI(file);
}

void BrowserManager::showHistory() {
    cout << "\n========== Browsing History ==========\n";
    history.display();
    cout << "======================================\n";
}

void BrowserManager::showBookmarks() {
    cout << "\n========== Saved Bookmarks ==========\n";
    bookmarks.display();
    cout << "=====================================\n";

}
// Mai(printCurrentPage)
void BrowserManager::printCurrentPage()
{
    if (!currentPage.empty()) {
        printer.addJob(currentPage);
        cout << "\n[Browser] Sending '" << currentPage << "' to Cloud Print Queue...\n";
    } else {
        cout << "\n[!] No page loaded to print.\n";
    }
}
void BrowserManager::processPrinting()
{
    printer.printJob();
}

void BrowserManager::showTabs()
{

    cout << "\n=====================================\n";
    cout << "           OPEN BROWSER TABS                     \n";
    cout << "=====================================\n";
    tabs.display();
    cout << "=====================================\n";
}

void BrowserManager::closeCurrentTab()
{
    cout << "\n=====================================\n";
    cout << "            CLOSE CURRENT TAB                       \n";
    cout << "=====================================\n\n";

    if (tabs.isEmpty())
    {
        cout <<"No tabs to close.\n";
    }
    else
    {
        string closed = tabs.closeTab();

        cout << "Closed: " << closed << "\n";
        cout << "Tab closed successfully.\n";
        if (tabs.isEmpty())
        {
            currentPage = "www.google.com";
        }
        else
        {
            currentPage = tabs.getCurrentTab();
        }
    }

    cout << "\n=====================================\n";
}



void BrowserManager::showMenu()
{
    cout << "\n====== Web Browser ======\n";
    cout << "Current: " << currentPage << endl;
    cout << "1. Visit URL\n";
    cout << "2. Back\n";
    cout << "3. Forward\n";
    cout << "4. Bookmark\n";
    cout << "5. Download\n";
    cout << "6. Show History\n";
    cout << "7. Show Bookmarks\n";
    cout << "8. Print Current Page \n";
    cout << "9. Process Cloud Printing (Print Next)\n";
    cout << "10. Show Open Tabs\n";
    cout << "11. Close Current Tab\n";
    cout << "0. Exit\n";
}
