#include <iostream>
#include <algorithm>
using namespace std;

long long dp[31][31];

void solution()
{
	//알약이 반개씩만남은경우
	for (int i = 0; i <= 30; ++i)
		dp[0][i] = 1;

	//반알은 없는경우도 존재하기때문에 
	for (int w = 1; w <= 30; ++w)
	{
		for (int h = 0; h <= 30; ++h)
		{
			if (h == 0)
				dp[w][0] = dp[w - 1][1];
			else
				dp[w][h] = dp[w - 1][h + 1] + dp[w][h - 1];
		}
	}
}
int main()
{
	int n;
	solution();
	while (true)
	{
		cin >> n;
		if (n == 0)
			break;

		cout << dp[n][0] << "\n";
	}
}