#include <iostream>
#include <algorithm>
using namespace std;

int DP[1001][3]{ 0, };
int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n;++i)
	{
		int r, g, b;
		cin >> r >> g >> b;
		DP[i][0] = min(DP[i - 1][1], DP[i - 1][2]) + r;
		DP[i][1] = min(DP[i - 1][0], DP[i - 1][2]) + g;
		DP[i][2] = min(DP[i - 1][0], DP[i - 1][1]) + b;
	}

	cout << min(DP[n][0], min(DP[n][1], DP[n][2]));
}