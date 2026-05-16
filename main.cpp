#include "BrowserManager.h"

// Essam Mohamed 10 - Main UI

int main()
{
    BrowserManager browser;
    int choice;
    string url, file;

    do
    {
        browser.showMenu();
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter URL: ";
            cin >> url;
            browser.visitURL(url);
            break;

        case 2:
            browser.goBack();
            break;

        case 3:
            browser.goForward();
            break;

        case 4:
            browser.addBookmark();
            break;

        case 5:
            cout << "Enter file: ";
            cin >> file;
            browser.downloadFile(file);
            break;
        case 6:
            browser.showHistory();
            break;

        case 7:
            browser.showBookmarks();
            break;
        case 8:
            browser.printCurrentPage();
            cout << "Current page sent to Cloud Print Queue.\n";
            break;

        case 9:
            browser.processPrinting();
            break;

        case 10:
            browser.showTabs();
            break;

        case 11:
            browser.closeCurrentTab();
            break;

        case 0:
            cout << "Closing Browser...\n";
            break;
        }

    } while (choice != 0);

    return 0;
}
