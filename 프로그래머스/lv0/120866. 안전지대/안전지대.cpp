#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board) {
    vector<vector<int>> direction = 
    {
        {-1,1},//오른위
        {-1,0},//위
        {-1,-1},//왼위
        {0,1},//오른
        {0,-1},//왼
        {1,0},//아래
        {1,1},//오른아래
        {1,-1},//왼아래
    };
    int n = board.size();
    int answer = 0;
    
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            if(board[i][j] == 1)
            {
                for(auto d : direction)
                {
                    //보드 크기 넘어가는것 방지
                    if(i+d[0] >= 0 && i+d[0] < n && j+d[1] >= 0 && j+d[1] < n)
                    {
                        if(board[i+d[0]][j+d[1]] !=1)
                            board[i+d[0]][j+d[1]] =2;
                        
                    }
                }
            }
        }
    }
    
    for(auto v : board)
    {
        answer += count(v.begin(),v.end(),0);
    }
    
    return answer;
}