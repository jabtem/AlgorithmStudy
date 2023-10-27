#include <iostream>
#include <algorithm>
using namespace std;

int dp[10001];
int coin[100];

void solution(int n, int k)
{
	//아무동전도 안쓴경우 1가지
	dp[0] = 1;
	for (int i = 0; i < n;++i)
	{
		for (int j = coin[i]; j <= k; ++j)
		{
			dp[j] += dp[j - coin[i]];
		}
	}
	cout << dp[k] << "\n";
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