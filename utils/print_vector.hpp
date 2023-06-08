#pragma once

#include <ostream>
#include <vector>

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vector) 
{
    os << "[";
    bool first = true;
    for (const int i : vector)
    {
        if (!first)
            os<<",";
        os<<i;
        first = false;
    }

    os << "]";

    return os;
}