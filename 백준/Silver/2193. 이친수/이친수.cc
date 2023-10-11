#include <iostream>
using namespace std;

long long DP[91];

void pinaryNumber(int n)
{
	DP[1] = 1;
	DP[2] = 1;

	for (int i = 3; i <= n;++i)
	{
		DP[i] = DP[i - 1] + DP[i - 2];
	}

	cout << DP[n];

}

int main()
{
	int n;

	cin >> n;

	pinaryNumber(n);
}