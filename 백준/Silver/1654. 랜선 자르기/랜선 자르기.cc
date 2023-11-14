#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void solution(int n, vector<int> & cables)
{
	long long result = 0;

	long long start = 1;
	long long end = *max_element(cables.begin(), cables.end());

	while (start <= end)
	{
		long long mid = (start + end) / 2;
		int cnt = 0;

		for (auto cable : cables)
		{
			cnt += cable / mid;
		}

		if (cnt < n)
			end = mid - 1;
		else
		{
			start = mid + 1;
			result = max(mid, result);
		}
	}

	cout << result;
}
int main()
{
	int k,n;
	cin >> k>>n;

	vector<int> cables(k,0);

	for (int i = 0; i < k; ++i)
	{
		int num;
		cin >> num;
		cables[i] = num;
	}

	solution(n, cables);
}