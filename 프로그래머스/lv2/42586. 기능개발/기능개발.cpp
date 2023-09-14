#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    queue<int> days;
    int count;//중복개수검사용

    for (int i = 0; i < progresses.size();i++)
    {
        int n = (100 - progresses[i]) % speeds[i];
        if (n ==0)
        {
            int day = (100 - progresses[i]) / speeds[i];
            days.push(day);
        }
        else
        {
            int day = (100 - progresses[i]) / speeds[i] + 1;
            days.push(day);
        }
            

    }

    while (!days.empty())
    {
        count = 1;
        //큐 가장 앞에있는 값
        int cur = days.front();
        days.pop();//값 제거

        //앞에 작업보다 뒤의 작업이 빠를경우 앞의 작업과 일수를 일치시킨다
        //pop으로 값을 제거햇기때문에 현재의 front는 cur의 다음작업
        //다음작업이 선작업보다 배포일수가 느릴때까지 계속 반복
        while (cur >= days.front() && !days.empty())
        {
            count++;
            days.pop();
        }
        answer.push_back(count);
    }


    return answer;
}