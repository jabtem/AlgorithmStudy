#include <string>
#include <vector>

using namespace std;

string solution(string cipher, int code) {
    string answer = "";
    int count=0;
    for(char c : cipher)
    {
        ++count;
        if(count%code == 0)
        {
            answer +=c;
        }
    }
    return answer;
}