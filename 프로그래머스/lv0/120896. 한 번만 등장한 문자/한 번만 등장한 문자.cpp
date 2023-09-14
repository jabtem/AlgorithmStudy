#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(string s) {
    string answer = "";
    map <char,int>map;
    
    for(char c : s)
    {
        map[c]++;
    }
    
    for(auto ch : map)
    {
        if(ch.second <2)
        {
            answer += ch.first;
        }
    }
    
    return answer;
}