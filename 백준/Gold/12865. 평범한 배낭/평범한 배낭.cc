#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int W[101] = { 0 };
int P[101] = { 0 };
int DP[101][100001] = { 0 };

int main()
{
	int n, k;
	cin >> n >> k;

	for (int i = 1;i <= n; ++i)
	{
		int weight, price;

		cin >> weight >> price;
		W[i] = weight;
		P[i] = price;
	}

	for (int limit = 1; limit <= k; limit++)
	{
		for (int index = 1; index <= n; index++)
		{
			if (W[index] > limit)
			{
				DP[index][limit] = DP[index - 1][limit];
			}
			else
			{
				DP[index][limit] = max(DP[index - 1][limit - W[index]] + P[index], DP[index - 1][limit]);
			}
		}
	}
	cout << DP[n][k];
}