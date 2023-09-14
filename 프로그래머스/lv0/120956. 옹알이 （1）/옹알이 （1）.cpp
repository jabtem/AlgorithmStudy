#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    for(string s : babbling)
    {
        bool possible = true;
        for(int i = 0; i < s.length();)
        {
            if(s.compare(i,3, "aya") == 0 || s.compare(i,3, "woo") == 0)
                i+=3;
            else if(s.compare(i,2, "ye") == 0 || s.compare(i,2, "ma") == 0)
                i+=2;
            else
            {
                possible = false;
                break;
            }
                
        }
        if(possible)
            ++answer;
    }
    return answer;
}