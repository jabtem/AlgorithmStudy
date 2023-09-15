#include <string>
#include <vector>

using namespace std;
int result =0;


int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int length = triangle.size();
    vector<vector<int>> dp(length, vector<int>(length));
    //삼각형 제일위
    dp[0][0] = triangle[0][0];
    
    for(int i = 1 ; i<length; ++i)
    {
        for(int j = 0; j <=i ; ++j)
        {
            //제일왼쪽
            if(j==0)
            {
                dp[i][j] = dp[i-1][j];
            }
            //제일오른쪽
            else if(j==i)
            {
                dp[i][j] = dp[i-1][j-1];
            }
            //중간이면 왼쪽 오른쪽중에 큰수
            else
                dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]);
            
            dp[i][j] += triangle[i][j];
        }
    }
    
    for(int i=0; i<length; ++i)
    {
        answer = answer > dp[length-1][i] ? answer : dp[length-1][i];
    }
    
    return answer;
}