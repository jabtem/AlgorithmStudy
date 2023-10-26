#include <iostream>
using namespace std;

int DP[1001];
int pack[1001];
void solution(int n)
{
	DP[1] = pack[1];

	for (int i = 2;i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			DP[i] = max(DP[i], DP[i - j] + pack[j]);
		}
	}

	cout << DP[n];
}

int main()
{
	int n;
	cin >> n;

	pack[0] = 0;
	for (int i = 1; i <= n;++i)
	{
		int price;
		cin >> price;
		pack[i] = price;
	}
	solution(n);
}