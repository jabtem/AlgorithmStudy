#include <iostream>
using namespace std;

int DP[1000000];

void calculate(int n)
{
	DP[1] = 0;

	for (int i = 2; i <= n; ++i)
	{
		DP[i] = DP[i - 1] + 1;
		if (i % 3 == 0)
			DP[i] = min(DP[i], DP[i / 3] + 1);
		if (i % 2 == 0)
			DP[i] = min(DP[i], DP[i / 2] + 1);
	}

	cout << DP[n] << "\n";

	while (n > 1) {
		cout << n << " ";
		if (DP[n] == DP[n - 1] + 1)
			n = n - 1;
		else if (n % 2 == 0 && DP[n] == DP[n / 2] + 1)
			n = n / 2;
		else if (n % 3 == 0 && DP[n] == DP[n / 3] + 1)
			n = n / 3;
	}
	cout << 1;

}

int main()
{
	int n;

	cin >> n;
	calculate(n);
}