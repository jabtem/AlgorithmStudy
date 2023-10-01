#include <iostream>

using namespace std;
long long DP[91];
void fibo(int n)
{
	DP[0] = 0;

	DP[1] = 1;

	for (int i = 2; i <= n; ++i)
	{
		DP[i] = DP[i - 1] + DP[i - 2];
	}

	cout << DP[n];
}

int main()
{
	int n;
	cin >> n;

	fibo(n);
}