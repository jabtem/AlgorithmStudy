#include <vector>
#include <iostream>
#include <stack>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> stack;
    
    for(int n : arr)
    {
        if(!stack.empty())
        {
            if(stack.top() != n)
            {
                stack.push(n);
                answer.push_back(n);
            }
            else
                continue;
        }
        else
        {
            stack.push(n);
            answer.push_back(n);
        }
    }

    return answer;
}