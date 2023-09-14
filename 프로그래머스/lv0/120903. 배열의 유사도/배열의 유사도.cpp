#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    int answer = 0;
    for(string str : s1)
    {
        auto it = find(s2.begin(),s2.end(),str);
        if(it != s2.end())
        {
            ++answer;
        }
    }

    return answer;
}