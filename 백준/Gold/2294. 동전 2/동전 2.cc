#include <iostream>
#include <algorithm>
using namespace std;

int dp[10001];
int coin[100];
const int INF = 1e9;
void solution(int n, int k)
{
	// dp = 쓴동전의 최소개수
	dp[0] = 0;

	for (int i = 1; i <= k; ++i)
		dp[i] = INF;

	for (int i = 0; i < n;++i)
	{
		for (int j = coin[i]; j <= k; ++j)
		{
			dp[j] = min(dp[j], dp[j - coin[i]] + 1 );
		}
	}
	if (dp[k] != INF)
		cout << dp[k] << "\n";
	else
		cout << -1 << "\n";
}
int main()
{
	int n, k;
	cin >> n >> k;
	int p;
	for (int i = 0; i < n; ++i)
	{
		cin >> coin[i];
	}
	solution(n, k);
}