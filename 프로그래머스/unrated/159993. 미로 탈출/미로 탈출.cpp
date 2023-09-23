#include <string>
#include <vector>
#include <queue>
using namespace std;

//상하좌우
int dx[4] = {0 , 0 , 1, -1};
int dy[4] = {1 ,-1 , 0, 0};

struct Node{
    int x,y;
    int d;
    Node(int x, int y, int d)
        : x(x), y(y), d(d) {}
    bool operator>(const Node& other)const
    {
        //목적지까지 총비용이 더낮은 노드를 top으로
        return d > other.d;
    }
};


int bfs(int sX, int sY, int gX, int gY, vector<string> &m)
{
    //시작과 목적지가 같으면 0 반환
    if(sX == gX && sY == gY)
        return 0;
    
    bool check[101][101] ={0};
    int mapX = m.size();
    int mapY = m[0].size();
    priority_queue<Node, vector<Node>, greater<Node>> q;
    
    q.push(Node(sX,sY,0));
    check[sX][sY] = {true};
    while(!q.empty())
    {
        Node current = q.top();
        q.pop();
        
        if(current.x == gX && current.y == gY)
        {
            return current.d;
        }
        //상하좌우검사
        for(int i=0 ; i < 4 ; ++i)
        {
            int x = current.x + dx[i];
            int y = current.y + dy[i];
            
            //범위밖, 이미 지난곳, 벽이면 제외 
            if( x < 0 ||x >= mapX || y < 0 || y >= mapY)
                continue;
            if(check[x][y])
                continue;
            if(m[x][y] == 'X') 
                continue;
        
            check[x][y] = true;
            int d = current.d + 1;
            q.push(Node(x,y,d));
        }
        
    }
    //목적지에 도달불가면 -1
    return -1;
}

int solution(vector<string> maps) {
    int answer = 0;
    //시작좌표
    int sx;
    int sy;
    //레버좌표
    int lx;
    int ly;
    //골좌표
    int gx;
    int gy;

    for(int i=0; i< maps.size(); ++i)
    {
        for(int j=0; j< maps[0].size(); ++j)
        {
            if(maps[i][j] == 'S')
            {
                sx = i;
                sy = j;
            }
            else if(maps[i][j] == 'L')
            {
                lx = i;
                ly = j;
            }
            else if(maps[i][j] == 'E')
            {
                gx = i;
                gy = j;
            }
        }
    }
    
    //시작점에서 레버까지 거리
    int ld = bfs(sx,sy,lx,ly,maps);
    //레버에서 목적지까지 거리
    int gd = bfs(lx,ly,gx,gy,maps);

    if(ld <0 || gd < 0)
        return -1;
    
    return ld + gd;
}