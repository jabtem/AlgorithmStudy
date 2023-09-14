#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

string solution(string bin1, string bin2) {
    bitset<10> bs1(bin1);
    bitset<10> bs2(bin2);
    
    int result = bs1.to_ulong() + bs2.to_ulong();
    string answer = "";
    
    if(result == 0)
    {
        answer = "0";
    }
    
    while(result >0)
    {
        answer = to_string(result % 2)+answer;
        result >>=1;
    }
    
    return answer;
}