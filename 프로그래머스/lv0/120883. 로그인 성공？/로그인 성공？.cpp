#include <string>
#include <vector>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    string answer = "fail";
    
    for(auto d : db)
    {
        if(d[0] == id_pw[0])
        {
            answer = (d[1] == id_pw[1]) ? "login" : "wrong pw";
        }
    }
    return answer;
}