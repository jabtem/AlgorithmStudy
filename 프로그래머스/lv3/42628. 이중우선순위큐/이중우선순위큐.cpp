#include <string>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> maxHeap; // 최대 힙 (기본값)
    priority_queue<int, vector<int>, greater<int>> minHeap; // 최소 힙
    int count = 0; //이중 우선순위 큐 개수 판단용
    
    string s; int n;
    for(auto str : operations)
    {
        stringstream ss(str);
        ss >> s; //I , D 키워드 저장
        ss >> n; //숫자 저장
        
        if(s == "I")
        {
            maxHeap.push(n);
            minHeap.push(n);
            ++count;
        }
        else if(s == "D")
        {
            //이미 비어있으면 삭제불가
            if(count == 0)
                continue;
            
            if(n > 0)
            {
                maxHeap.pop();
                --count;

            }
            else
            {
                minHeap.pop();
                --count;
            }
            //pop후 카운트가 0이되었으므로 큐 클리어
            if(count == 0)
            {
                minHeap =  priority_queue<int, vector<int>, greater<int>>();
                maxHeap =  priority_queue<int>();
            }
        }
        
    }
    
    if(count > 0)
    {
        answer = {maxHeap.top(),minHeap.top()};
    }
    else
    {
        answer = {0,0};   
    }
    
    return answer;
}