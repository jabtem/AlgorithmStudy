#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int solution(vector<vector<int>> lines) {
    int answer = 0;
    unordered_map<int,int>map;
    
    for(auto l : lines)
    {
        for(int i=l[0] ; i<l[1];++i)
        {
            if(map.count(i))
            {
                map[i]++;
            }
            else
                map.insert({i,1});
        }
    }
    
    for(auto m : map)
    {
        if(m.second >1)
        {
            ++answer;
        }
    }
    
    return answer;
}