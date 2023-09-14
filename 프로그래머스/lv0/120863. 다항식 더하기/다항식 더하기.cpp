#include <string>
#include <vector>
#include <regex>

using namespace std;

string solution(string polynomial) {
    
    int x = 0;
    int num = 0;
    
    regex re("(\\d+x|\\d+|x)");
    sregex_iterator iter(polynomial.begin(),polynomial.end(),re);
    sregex_iterator end;
    
    while(iter != end)
    {
        string temp = iter->str();
        //숫자x형태인지 구분
        if(regex_match(temp,regex("\\d+x")))
        {
            //끝에 x삭제
            temp.pop_back();
            x+= stoi(temp);
        }
        //숫자인지 구분
        else if (regex_match(temp, std::regex("\\d+"))) 
        {
            num += stoi(temp);
        } 
        else if (temp == "x") 
        {
            ++x;
        }
        ++iter;
    }
    string xStr = x>1 ? to_string(x)+"x" : "x";
    
    if(num == 0)
    {
        return xStr;
    }
    else if(x == 0)
    {
        return to_string(num);
    }
    
    return xStr + " + " + to_string(num);
}