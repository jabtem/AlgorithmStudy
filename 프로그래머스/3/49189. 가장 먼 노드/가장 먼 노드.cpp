#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int index, distance;
    Node(int index, int distance) : index(index),distance(distance) {}
    bool operator>(const Node& other) const {
        return distance > other.distance;
    }
};

const int INF = 1e9;
vector<Node> vec[20001];
int dist[20001];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(int i=1; i<=n;++i)
    {
        vec[i].clear();
        dist[i] = INF;
    }
    
    for(auto e : edge)
    {
        int start = e[0];
        int end = e[1];
        
        vec[start].push_back(Node(end,1));
        vec[end].push_back(Node(start,1));
    }
    
    priority_queue<Node,vector<Node>,greater<Node>> pq;
    pq.push(Node(1,0));
    dist[1] =0;
    
    while(!pq.empty())
    {
        Node curNode = pq.top();
        pq.pop();
        int curIndex = curNode.index;
        int curDist = curNode.distance;
        if(dist[curIndex] < curDist)
            continue;;
        
        for(auto n : vec[curIndex])
        {
            int nextIndex = n.index;
            int nextDist = n.distance + curDist;
            
            if(dist[nextIndex] > nextDist)
            {
                dist[nextIndex] = nextDist;
                pq.push(Node(nextIndex,nextDist));
            }
        }
    }
    
    //제일 긴거리 저장용
    int max = 0;
    for(int i=1; i<=n; ++i)
    {
        if(dist[i] == INF)
            continue;
        
        max = max > dist[i] ? max : dist[i];
    }
    
    for(int i=1; i<=n; ++i)
    {
        if(dist[i] == max)
            answer++;
    }
    
    return answer;
}