#include<vector>
#include<queue>
using namespace std;

struct Node
{
    int x,y,d;
    Node(int x,int y,int d):x(x),y(y),d(d){}
    
    bool operator > (const Node& other)const
    {
        return d > other.d;
    }
};

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int bfs(vector<vector<int>> &map)
{
    int n= map.size();
    int m = map[0].size();
    
    bool check[101][101] ={false};
    priority_queue<Node,vector<Node>,greater<>> q;
    
    q.push(Node(0,0,1));
    check[0][0] = true;
    
    while(!q.empty())
    {
        Node current = q.top();
        q.pop();
        
        if(current.x == n-1 && current.y == m-1)
        {
            return current.d;
        }
        
        for(int i=0; i<4; ++i)
        {
            int x = current.x + dx[i];
            int y = current.y + dy[i];
            
            if(x < n && x>= 0 && y < m && y >=0 && map[x][y] != 0&& !check[x][y])
            {
                check[x][y] = true;
                int d = current.d +1;
                q.push(Node(x,y,d));
            }
        }
    }
    
    return -1;
}

int solution(vector<vector<int> > maps)
{
    int answer = bfs(maps);
    return answer;
}