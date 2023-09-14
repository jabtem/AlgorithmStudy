#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sides) {
    int maxSide = max(sides[0],sides[1]);
    int minSide = min(sides[0],sides[1]);
    
    int answer = 0;
    
    
    //가장긴변이 max인경우
    for(int i= maxSide; i>0 ; --i)
    {
        if(i+minSide > maxSide)
        {
            ++answer;
        }
        else
            break;
    }
    
    //나머지 변이 가장긴 변인경우
    for(int i= maxSide+1; i < maxSide + minSide; ++i)
    {
            ++answer;
    }
    return answer;
}