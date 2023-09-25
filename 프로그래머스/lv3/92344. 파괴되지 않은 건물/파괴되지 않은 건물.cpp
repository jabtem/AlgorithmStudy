#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int N = board.size();
    int M = board[0].size();
    
    vector<vector<int>> change (N+1, vector<int>(M+1,0));
    
    
    for(auto s : skill)
    {
        int n = (s[0] == 1) ? s[5]*-1 : s[5];
        
        int x1 = s[1];
        int y1 = s[2];
        int x2 = s[3]+1;
        int y2 = s[4]+1;
        
        change[x1][y1] += n;change[x1][y2] -= n;
        change[x2][y1] -= n;change[x2][y2] += n;
    }
    
    //위에서 아래로 누적합
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<=M ;++j)
        {
            change[i+1][j] +=change[i][j]; 
        }
    }
    
    //왼쪽에서 오른쪽 누적합
    for(int i=0; i<=N; ++i)
    {
        for(int j=0; j<M ;++j)
        {
            change[i][j+1] +=change[i][j]; 
        }
    }
    
    //벡터 합산
    for(int i=0; i <N ; ++i)
    {
        for(int j=0; j < M; ++j)
        {
            board[i][j] += change[i][j];
            if(board[i][j] > 0)
                ++answer;
        }
    }
    

    return answer;
}