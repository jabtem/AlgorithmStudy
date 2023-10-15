#include <string>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> pairII;
bool check[101] = {false};

int Prim(int startNode,vector<vector<int>> & v)
{
    int result = 0;
    priority_queue<pairII,vector<pairII>,greater<pairII>> pq;
    
    
    pq.push({startNode,0});

    
    while(!pq.empty())
    {
        int curNode = pq.top().second;
        int curCost = pq.top().first;
        pq.pop();
        
        if(!check[curNode])
        {
            check[curNode] = true;
            result += curCost;
            
            for(auto c : v)
            {
                
                int start = c[0];
                int end = c[1];
                int cost = c[2];
        
                if(start == curNode && !check[end])
                {
                    pq.push({cost,end});
                }
                else if(end == curNode && !check[start])
                {
                    pq.push({cost,start});
                }
            }
        }
    }
    
    return result;
}

int solution(int n, vector<vector<int>> costs) {

    int answer =  Prim(0, costs);
    return answer;
}