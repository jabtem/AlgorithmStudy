#include <iostream>
#include <algorithm>
using namespace std;

int DP[10001][4]{ 0, };

void solution()
{
	DP[1][1] = 1;

	DP[2][1] = 1;
	DP[2][2] = 1;

	DP[3][1] = 1;
	DP[3][2] = 1;
	DP[3][3] = 1;

	for (int i = 4; i <= 10000; ++i)
	{
		DP[i][1] = DP[i - 1][1];
		DP[i][2] = DP[i - 2][1] + DP[i - 2][2];
		DP[i][3] = DP[i - 3][1] + DP[i - 3][2] + DP[i - 3][3];
	}
}
int main()
{
	int n;
	cin >> n;

	solution();

	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		cout << DP[num][1] + DP[num][2] + DP[num][3] <<"\n";
	}
}