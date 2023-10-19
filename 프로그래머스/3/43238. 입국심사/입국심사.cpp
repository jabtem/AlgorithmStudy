#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long binarySearch(int n, vector<int> & vec)
{
    long long result = 0;
    sort(vec.begin(),vec.end());
    
    //n이 1이고 심사를 1분안에볼때
    long long start = 1;
    //제일 오래걸리는경우
    long long end = (long long)vec[vec.size()-1]*n;
    
    while(start <= end)
    {
        long long mid = (start+end)/2;
        long long cnt = 0;
        
        for(auto v : vec)
        {
            //각 시간별로 중간값동안 처리할수 있는 인원 합산
            cnt += mid / v;
        }
        
        //더적은 인원을 처리가능 
        if(cnt < n)
        {
            start = mid + 1;
        }
        //더많은 인원을 처리 가능
        else
        {
            end = mid -1;
            result = mid;
        }
    }
    return result;
}

long long solution(int n, vector<int> times) {
    long long answer = binarySearch(n,times);
    
    return answer;
}