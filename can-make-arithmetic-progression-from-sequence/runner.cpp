#include <iostream>
#include <vector>

#include "solution.hpp"

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

int main()
{
    std::vector<int> input = {1,2,3,1};
    Solution s;
    std::cout << "\"" << input << "\": " << (s.canMakeArithmeticProgression(input) ? "true" : "false") << std::endl;

    return 0;
}