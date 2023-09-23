#include <string>
#include <vector>
#include <queue>
using namespace std;

//상하좌우
int dx[4] = {0 , 0 , 1, -1};
int dy[4] = {1 ,-1 , 0, 0};

struct Node{
    int x,y;
    //g : 시작부터 현재까지비용
    //h : 현재위치에서 목적지까지 비용
    //f : 총비용
    int g,h,f;
    Node(int x, int y, int g, int h)
        : x(x), y(y), g(g), h(h), f(g + h) {}
    bool operator>(const Node& other)const
    {
        //목적지까지 총비용이 더낮은 노드를 top으로
        return f > other.f;
    }
};

int myAbs(int n)
{
    return n > 0 ? n : n*-1;
}

int heuristic(int x, int y, int goalX, int goalY)
{
    return myAbs(x - goalX) + myAbs(y - goalY);
}

int Astar(int sX, int sY, int gX, int gY, vector<string> &m)
{
    //시작과 목적지가 같으면 0 반환
    if(sX == gX && sY == gY)
        return 0;
    
    bool check[101][101] ={0};
    int mapX = m.size();
    int mapY = m[0].size();
    priority_queue<Node, vector<Node>, greater<Node>> q;
    
    q.push(Node(sX,sY,0,0));
    check[sX][sY] = {true};
    while(!q.empty())
    {
        Node current = q.top();
        q.pop();
        
        if(current.x == gX && current.y == gY)
        {
            return current.g;
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
            int g = current.g + 1;
            int h = 0;
            int f = g + h;
            q.push(Node(x,y,g,h));
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
    int ld = Astar(sx,sy,lx,ly,maps);
    //레버에서 목적지까지 거리
    int gd = Astar(lx,ly,gx,gy,maps);

    if(ld <0 || gd < 0)
        return -1;
    
    return ld + gd;
}