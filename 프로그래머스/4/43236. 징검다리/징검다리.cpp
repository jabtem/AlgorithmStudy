#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int parametricSearch(int distance, vector<int>& vec, int n)
{
    int result =0;
    
    int start = 0;
    int end = distance;
    sort(vec.begin(),vec.end());
    
    while(start <= end)
    {
        int mid = (start+end)/2;
        int cnt = 0;
        int prev = 0;
        
        for(auto v : vec)
        {
            if(v-prev < mid)
                cnt++;
            else
                prev = v;
        }
        if(distance - prev < mid)
            cnt++;
        
        if(cnt <=n)
        {
            result = max(mid,result);
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    
    return result;
}

int solution(int distance, vector<int> rocks, int n) {
    int answer = parametricSearch(distance, rocks, n);
    return answer;
}