#include<vector>
#include<queue>
using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int solution(vector<vector<int> > maps)
{
    bool check[101][101] = {0};//방문여부
    int dist[101][101] = {0};//해당 좌표까지 거리
    queue<pair<int,int>> q;
    
    //보드 y크기
    int m = maps.size();
    //보드 x크기
    int n = maps[0].size();
    int answer = 0;

    //시작설정
    q.push({0,0});
    check[0][0] = true;
    dist[0][0] = 1;
    
    while(!q.empty())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        
        for(int i=0; i<4; ++i)
        {
            int x = curX + dx[i];
            int y = curY + dy[i];
            
            //보드범위초과
            if(x< 0 || x >=n || y < 0 || y >= m)
                continue;
            //이미간곳
            if(check[y][x])
                continue;
            //막힌곳
            if(maps[y][x] == 0)
                continue;
            
            check[y][x] = true;
            q.push({y,x});
            dist[y][x] = dist[curY][curX]+1;
        }
    }

    answer = dist[m-1][n-1] == 0 ? -1 : dist[m-1][n-1];
    
    return answer;
}