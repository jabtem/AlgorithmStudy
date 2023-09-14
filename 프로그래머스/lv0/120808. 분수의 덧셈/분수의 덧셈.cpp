#include <string>
#include <vector>

using namespace std;

int GCD(int a, int b)
{
    int gcd = a % b;
    
    while(gcd!=0)
    {
        a = b;
        b = gcd;
        gcd = a % b;
    }
    
    return b;
}

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    
    int numer3 = (numer1*denom2) + (numer2*denom1); 
    int denom3 = denom1*denom2;
    
    int gcd = GCD(numer3,denom3);
    
    if(gcd == 1)
    {
        answer.push_back(numer3);
        answer.push_back(denom3);
    }
    else
    {
        answer.push_back(numer3/gcd);
        answer.push_back(denom3/gcd);
    }
    return answer;
}