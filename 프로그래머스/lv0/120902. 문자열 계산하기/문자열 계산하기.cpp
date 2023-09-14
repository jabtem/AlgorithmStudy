#include <string>
#include <vector>
#include <sstream>

using namespace std;


int solution(string my_string) {
    int answer = 0;
    istringstream ss(my_string);
    string oper="";
    int num=0;
    ss >> answer;
    
    while(ss >> oper >> num)
    {
        if(oper == "+")
        {
            answer += num;
        }
        else if(oper == "-")
        {
            answer -= num;
        }
    }
    
    return answer;
}