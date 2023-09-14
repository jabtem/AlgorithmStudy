#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 2;
    if(n < 3)
    {
        return n;
    }
    
    for(int i= 3; i<=n; ++i)
    {
        ++answer;
        while(answer%3 == 0 || to_string(answer).find("3") != string::npos)
        {
            ++answer;
        }
    }
    return answer;
}