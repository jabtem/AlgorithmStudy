#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void solution(int k, vector<int> & numbers)
{
	int result = -10000001;
	int s = 0;
	int e = k-1;
	int sum = 0;

	for (int i = 0; i <= k - 1; ++i)
	{
		sum += numbers[i];
	}

	while (e < numbers.size())
	{
		result = max(result, sum);
		if (e == numbers.size() - 1)
			break;
		else
		{
			sum -= numbers[s++];
			sum += numbers[++e];
		}
	}

	cout << result;
}
int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> numbers(n, 0);
	for (int i = 0; i < n;++i)
	{
		cin >> numbers[i];
	}

	solution(k, numbers);
}