#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    int n = num > total ? num : total;
    
    if(num < 2)
    {
        answer.push_back(total);
        return answer;
    }
    
    for(int i = -n; i <=n ; ++i)
    {
        int sum = 0 ;
        vector<int> temp;
        for(int j = i; j < i+num; ++j)
        {
            sum += j;
            temp.push_back(j);
        }
        if(sum == total)
            return temp;
    }
    
    return answer;
}