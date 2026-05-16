#include "Analytics.h"

// Student 8 - Mariam Mahmoud

Analytics::Analytics()
{
    comCount = 0;
    orgCount = 0;
}

void Analytics::analyzeDomain(string url)
{
    if (url.find(".com") != string::npos)
        comCount++;
    else if (url.find(".org") != string::npos)
        orgCount++;
}

void Analytics::showStats()
{
    cout << ".com visits: " << comCount << endl;
    cout << ".org visits: " << orgCount << endl;
}
