#include <string>
#include <vector>
#include <regex>
using namespace std;

int solution(string my_string) {
    int answer = 0;
    regex re("\\d+");
    sregex_iterator iter(my_string.begin(),my_string.end(),re);
    sregex_iterator end;
    
    while(iter != end)
    {
        answer+= stoi(iter->str());
        ++iter;
    }
    
    return answer;
}