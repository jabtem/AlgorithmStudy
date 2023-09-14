#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> s;
    
    for(auto n : nums)
    {
        if(s.count(n) == 0)
        {
            s.insert(n);
        }
    }
    
    int typeNums = s.size();
    int limit = nums.size()/2;
    
    int answer = typeNums < limit ? typeNums : limit;
    return answer;
}