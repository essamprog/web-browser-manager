#ifndef ANALYTICS_H
#define ANALYTICS_H
// Student 8 - Mariam Mahmoud

#include <iostream>
using namespace std;

// Student 8 - Mariam Mahmoud

class Analytics
{
private:
    int comCount;
    int orgCount;

public:
    Analytics();
    void analyzeDomain(string url);
    void showStats();
};

#endif
