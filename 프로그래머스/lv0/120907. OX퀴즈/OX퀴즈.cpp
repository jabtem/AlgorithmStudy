#include <string>
#include <vector>
#include <sstream>
using namespace std;

string QuizAnswer(string input)
{
    stringstream ss(input);
    int a,b,result;
    string oper,equal;
    
    ss >> a >> oper >> b >> equal >> result;
    
    if(oper == "+")
    {
        return (a+b) == result ? "O" : "X";
    }
    else if(oper == "-")
    {
        return (a-b) == result ? "O" : "X";
    }
}

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    for(string str : quiz)
    {
        answer.push_back(QuizAnswer(str));
    }

    return answer;
}