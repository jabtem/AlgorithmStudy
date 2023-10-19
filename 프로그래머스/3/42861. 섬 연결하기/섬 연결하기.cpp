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

bool check[101] = {false};
vector<Node> vec[101];

int Prim(int startNode,vector<vector<int>> & v)
{
    int result =0;
    priority_queue<Node,vector<Node>,greater<Node>> pq;
    
    for(auto c : v)
    {
        int start = c[0];
        int end = c[1];
        int cost = c[2];
        
        vec[start].push_back(Node(end,cost));
        vec[end].push_back(Node(start,cost));
    }
    pq.push(Node(0,0));
    while(!pq.empty())
    {
        Node curNode = pq.top();
        pq.pop();
        
        int curIdx = curNode.index;
        int curDist = curNode.distance;
        
        if(check[curIdx])
            continue;
        
        check[curIdx] = true;
        result += curDist;
        
        for(auto n : vec[curIdx])
        {
            int nextIdx = n.index;
            int nextDist = n.distance;
            
            if(!check[nextIdx])
                pq.push(Node(nextIdx,nextDist));
        }
    }
    
    return result;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = Prim(0,costs);


    return answer;
}