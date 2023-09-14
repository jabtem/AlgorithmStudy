#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    int answer = 2;
    string word ="";
    
    sort(spell.begin(),spell.end());
    
    for(string s : spell)
    {
        word += s;
    }
    
    for(string &s : dic)
    {
        sort(s.begin(),s.end());
    }
    
    for(string s : dic)
    {
        if(s == word)
            return 1;
    }
    
    return answer;
}