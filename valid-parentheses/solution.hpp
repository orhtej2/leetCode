#pragma once

#include <stack>
#include <string>

class Solution {
public:
    bool isValid(const std::string& s) {
        std::stack<char> st;
        for (char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
                st.push(c);
            else
            {
                if (st.empty())
                    return false;
                char curr = st.top();
                st.pop();
                if (c == ')' && curr != '(')
                    return false;
                else if (c == ']' && curr != '[')
                    return false;
                else if (c == '}' && curr != '{')
                    return false;
            }
        }

        return st.empty();        
    }
};