#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> q;



    for (int i= 0; i<priorities.size();i++)
    {
        q.push(i);
    }

    while (!q.empty())
    {

        int max = *max_element(priorities.begin(), priorities.end());
        int curIndex = q.front();
        q.pop();
        if (priorities[curIndex] != max)
        {
            //최대값이 아니면 제일뒤로다시배치
            q.push(curIndex);
        }
        else
        {
            ++answer;
            if (curIndex == location)
                return answer;
            priorities[curIndex] = 0;

        }
    }

    return answer;
}