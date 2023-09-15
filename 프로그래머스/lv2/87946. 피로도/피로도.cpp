#include <string>
#include <vector>
#include <algorithm>
using namespace std;


bool check[8] = {};
int result = 0;
void dfs(int k, int cnt, vector<vector<int>> &d)
{

    for(int i=0; i< d.size(); ++i)
    {
        //방문한적 없고 피로도 조건 만족시
        if(!check[i]&&k>=d[i][0])
        {
            check[i] = true;
            dfs(k-d[i][1], cnt+1,d);
            //다른경우 재방문 가능하도록 체크해제
            check[i] = false;
            
        }
    }
    result = max(result,cnt);
}

int solution(int k, vector<vector<int>> dungeons) {
    dfs(k,0,dungeons);
    int answer = result;
    return answer;
}