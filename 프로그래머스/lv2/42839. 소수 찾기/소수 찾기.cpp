#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
bool isPrime(int n) {
    if (n < 2) return false;

    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;

    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<char> v;
    vector<int> nums;
    
    for(auto c : numbers)
    {
        v.push_back(c);
    }
    sort(v.begin(),v.end());
    
    do
    {
        string temp="";
        for(auto c : v)
        {
            temp+=c;
            nums.push_back(stoi(temp));
        }
        
    }while(next_permutation(v.begin(),v.end()));
    sort(nums.begin(),nums.end());
    //중복제거 정렬필요
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    
    for(int n : nums)
    {
        if(isPrime(n))
            ++answer;
    }
    
    return answer;
}