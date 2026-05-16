#include "Security.h"

// Ahmed Rabie 9

bool Security::validate(string url)
{
    if (url.find("http") != string::npos)
        return true;

    if (url.find(".") == string::npos)
        return false;

    return true;
}
