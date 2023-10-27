#include <iostream>
#include <algorithm>
using namespace std;

int dp[31][1001][2];
int plum[1001];

void solution(int t, int w)
{
	int result = 0;

	for (int i = 0;i <= w;++i)
	{
		for (int j = 1; j <= t;++j)
		{
			if (i == 0)
			{
				dp[i][j][0] = dp[i][j - 1][0] + (plum[j] == 1);
			}
			else
			{
				dp[i][j][0] = max(dp[i][j - 1][0] + (plum[j] == 1), dp[i - 1][j - 1][1] + (plum[j] == 1));
				dp[i][j][1] = max(dp[i][j - 1][1] + (plum[j] == 2), dp[i - 1][j - 1][0] + (plum[j] == 2));
			}
		}
	}

	for (int i = 0; i <= w;++i)
	{
		result =  max(result, max(dp[i][t][0], dp[i][t][1]));
	}
	cout << result << "\n";
}
int main()
{
	int t, w;
	cin >> t >> w;

	//매초마다 자두떨어지는 나무위치
	for (int i = 1; i <= t; ++i)
	{
		cin >> plum[i];
	}

	solution(t, w);
}