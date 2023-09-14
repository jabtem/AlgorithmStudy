#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue <int,vector<int>,greater<int>> pq;//minHeap, 오름차순정렬
    int answer = 0;
    int newsco = 0;
    int fMin;//제일작은수
	int sMin;//그다음작은수
    
    for (auto i : scoville) {
		pq.push(i);
	}

	while (pq.top() < K) {

        
		fMin = pq.top();
		pq.pop();
		sMin = pq.top();
		pq.pop();
		newsco = fMin + sMin * 2;
        
		pq.push(newsco);
		answer++;

		if (pq.size() == 1) {
			if (pq.top() < K)
				return answer = -1;
		}
	}
    
    return answer;
}