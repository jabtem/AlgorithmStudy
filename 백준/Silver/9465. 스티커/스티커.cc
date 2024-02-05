#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[2][100001] = { 0, };
int main() 
{
	int T, n;

	cin >> T;

	while (T--)
	{
		cin >> n;
		vector<int> vec[2];
		int lastIndex = n - 1;
		for (int i = 0; i < 2;++i)
		{
			for (int j = 0; j < n;++j)
			{
				int num;
				cin >> num;
				vec[i].push_back(num);
			}
		}

		dp[0][0] = vec[0][0];
		dp[1][0] = vec[1][0];
		dp[0][1] = vec[0][1] + dp[1][0];
		dp[1][1] = vec[1][1] + dp[0][0];

		for (int i = 2; i < n;++i)
		{
			dp[0][i] = vec[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
			dp[1][i] = vec[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
		}

		int result =  max(dp[0][lastIndex], dp[1][lastIndex]);
		cout << result <<"\n";
	}
}
