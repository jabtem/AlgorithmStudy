#include <string>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int solution(int num, int k) {
    
    string s = to_string(num);
    string strK = to_string(k);
    int answer = 0;
    
    if(s.find(strK) != string::npos)
    {
        answer = s.find(strK) + 1;
    }
    else
        answer = -1;
    
    return answer;
}