#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> st;

    for (int i=0; i<prices.size();i++)
    {
        //스택이 비어있지않고 주식값이 감소한경우
        while (!st.empty()&&prices[st.top()]>prices[i])
        {

                answer[st.top()] = i - st.top(); //시간흐름차이
                st.pop();
        }
        st.push(i);
    }
    //끝까지 주식값이 감소하지않은인덱스

    while (!st.empty())
    {
        answer[st.top()] = prices.size() - st.top() - 1;
        st.pop();
    }

    return answer;
}