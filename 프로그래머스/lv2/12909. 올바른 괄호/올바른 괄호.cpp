#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    stack<char> st;
    
    for(auto c : s)
    {
        if(!st.empty() && c == ')')
        {
            if(st.top() == '(')
                st.pop();
            else
                st.push(c);
        }
        else
            st.push(c);
    }
    
    if(!st.empty())
        return false;

    return true;
}