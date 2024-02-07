#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int dp[101][10];
int main() 
{
	int N;
	int result = 0;
	cin >> N;

	for (int i = 1; i < 10;++i)
	{
		dp[1][i] = 1;
	}

	//i = 자리수 , j = j로 끝나는수 ex) i=2 j=1 2자리수중 1로끝나는수중에 계단수
	for (int i = 2;i <= N;++i)
	{
		for (int j = 0; j < 10;++j)
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][j + 1];
			else if (j == 9)
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];

			dp[i][j] %= 1000000000;
		}
	}

	for (int i = 0; i < 10; ++i)
		result = (result + dp[N][i])% 1000000000;

	cout << result << "\n";
}
