#include <string>
#include <vector>
#include <cmath>
using namespace std;
string decimalToN(int decimal, int n) {
    if (decimal == 0) {
        return "0";
    }

    string digits = "0123456789";

    string result = "";

    while (decimal > 0) {
        result = digits[decimal % n] + result;
        decimal /= n;
    }

    return result;
}

bool isPrime(long long n)
{
    if(n <2)
        return false;
    
    for(int i=2; i<= sqrt(n);++i)
    {
        if(n%i == 0)
            return false;
    }
    
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    
    string str = decimalToN(n,k);
    string temp ="";
    
    for(auto c : str)
    {
        if(c =='0')
        {
            if(temp!= "" && isPrime(stoll(temp)))
                ++answer;
            temp ="";
        }
        else
            temp += c;
    }
    
    if(temp!= "" && isPrime(stoll(temp)))
        ++answer;
    return answer;
}