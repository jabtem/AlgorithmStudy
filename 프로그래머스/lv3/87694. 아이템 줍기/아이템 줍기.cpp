#include <string>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

struct Node
{
    int x,y,d;
    Node(int x,int y, int d)
        :x(x),y(y),d(d){}
    
    bool operator>(const Node& other)const
    {
        return d > other.d;
    }
};


int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int max_x =0;
    int max_y =0;
    
    //사각형 최소크기를 1로 할경우 경로가제대로안나옴 2배로키움
    for(auto rect : rectangle)
    {
        max_x = max(max_x,rect[2]*2);
        max_y = max(max_y,rect[3]*2);
    }
    
    int answer = 0;
    vector<vector<int>> board(max_x+1, vector<int>(max_y+1, 0));
    vector<vector<bool>> check(max_x+1, vector<bool>(max_y+1, false));
    priority_queue<Node, vector<Node>, greater<>> q;
    
    for(auto rect : rectangle)
    {
		int x1 = rect[0]*2;
		int y1 = rect[1]*2;
		int x2 = rect[2]*2;
		int y2 = rect[3]*2;

		for (int x = x1; x <= x2; ++x) {
			for (int y = y1; y <= y2; ++y) {
				if (x == x1 || x == x2 || y == y1 || y == y2) {
                    if(board[x][y] != 1)
					    board[x][y] = 2;
				}
				else {
					board[x][y] = 1;
				}
			}
		}
    }
    //시작점 설정
    q.push(Node(characterX*2,characterY*2,0));
    check[characterX*2][characterY*2] = true;
    
    while(!q.empty())
    {
        Node current = q.top();
        q.pop();
        
        if(current.x == itemX*2 && current.y == itemY*2)
        {
            return current.d*0.5;
        }
        
        for(int i=0; i<4;++i)
        {
            int x = current.x + dx[i];
            int y = current.y + dy[i];
            
            if(x > max_x || x < 0 || y > max_y || y < 0)
                continue;
            
            //테두리만 따라감
            if(board[x][y] == 2 && !check[x][y])
            {
                check[x][y] = true;
                int d = current.d +1;
                q.push(Node(x,y,d));
            }
        }
    }
    
    return 0;
}