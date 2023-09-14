#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool compare(int a,int b, int n)
{
    int an = abs(a-n);
    int bn = abs(b-n);
    
    if(an == bn)
        return a > b;
    
    return an < bn;
}

vector<int> solution(vector<int> numlist, int n) {
    
    sort(numlist.begin(),numlist.end(), [&](int a, int b)
         {
            return compare(a,b,n); 
         });
    
    return numlist;
}