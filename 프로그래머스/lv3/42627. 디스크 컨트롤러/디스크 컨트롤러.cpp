#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct compare {
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<vector<int>, vector<vector<int>>,compare> pq; // 소요시간을 기준으로 오름차순
    sort(jobs.begin(),jobs.end());
    int index = 0, curTime = 0;
    
    while(index < jobs.size() || !pq.empty())
    {
        //작업이 남아있고 작업의 요청시간이 현재시간보다 작거나 같을시
        if(index < jobs.size() && curTime >= jobs[index][0])
        {
            //작업 등록
            pq.push(jobs[index++]);
        }
        //대기중인 작업이있는경우
        else if(!pq.empty())
        {
            //현재시간에 작업소요시간 추가
            curTime += pq.top()[1];
            //전체소요시간에 현재시간 - 요청시간 추가
            answer += curTime - pq.top()[0];
            //작업 제거
            pq.pop();
        }
        else
            curTime = jobs[index][0];
    }
    
    
    return answer / jobs.size();
}