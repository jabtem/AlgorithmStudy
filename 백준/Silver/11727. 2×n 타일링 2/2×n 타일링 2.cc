#include <iostream>
using namespace std;

long long DP[1001];

void solution(int n)
{
	DP[1] = 1;
	DP[2] = 3;
	for (int i = 3; i <= n;++i)
	{
		DP[i] = (DP[i - 1] + DP[i - 2]*2)%10007;
	}
	cout << DP[n];
}

int main()
{
	int n;
	cin >> n;
	solution(n);
}