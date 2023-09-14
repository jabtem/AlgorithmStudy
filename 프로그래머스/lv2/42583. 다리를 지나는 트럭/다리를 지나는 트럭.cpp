#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = bridge_length;
    queue<int> q;
    int totalWeight = 0;

    for (auto curWeight : truck_weights)
    {
        while (true)
        {
            //다리위에 아무트럭도없을때
            if (q.empty())
            {
                q.push(curWeight);
                totalWeight += curWeight;
                answer++;
                break;
            }
            //트럭이 다도착하면 큐에서 제거
            else if(q.size() == bridge_length)
            {
                totalWeight -= q.front();
                q.pop();
            }
            else
            {
                //다른트럭이 올라오면 다리 중량을 초과하는경우
                if (curWeight + totalWeight > weight)
                {
                    q.push(0);
                    answer++;
                }
                else
                {
                    q.push(curWeight);
                    totalWeight += curWeight;
                    answer++;
                    break;
                }
            }
        }
    }



    return answer;
}