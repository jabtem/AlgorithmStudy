#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> score) {
    vector<float> avg;
    vector<int> answer;
    
    for(auto s : score)
    {
        float sum = (float)(s[0]+s[1]);
        answer.push_back(1);
        avg.push_back(sum/2);
    }
    
    for(int i = 0; i <avg.size(); ++i)
    {
        for(int j = 0; j <avg.size(); ++j)
        {
            if(i==j)
                continue;
            
            if(avg[i] < avg[j])
                answer[i]++;
        }
    }
    
    return answer;
}