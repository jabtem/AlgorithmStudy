#include <iostream>
#include <algorithm>
using namespace std;

int dp[101];
string word[101];

void solution(string s,int n)
{
	dp[s.length()] = 1;

	for (int pos = s.length() - 1; pos >= 0; --pos)
	{
		for (int i = 0; i < n;++i)
		{
			if (s.find(word[i], pos) == pos && dp[pos + word[i].length()] == 1)
			{
				dp[pos] = 1;
				break;
			}
			else
			{
				dp[pos] = 0;
			}
		}
	}

	cout << dp[0];
}
int main()
{
	string str;
	cin >> str;
	int n;
	cin >> n;

	for (int i = 0; i < n;++i)
	{
		cin >> word[i];
	}

	solution(str,n);
}