#pragma once

#include <ostream>
#include <vector>

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vector)
{
    os << "[";
    bool first = true;
    for (const auto& i : vector)
    {
        if (!first)
            os<<",";
        os<<i;
        first = false;
    }

    os << "]";

    return os;
}