#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void solution(int n, int m , vector<int> & vec)
{
	int result = 0;

	int start = 0;
	int end = *max_element(vec.begin(), vec.end());

	while (start <= end)
	{
		int mid = (start + end) / 2;
		long long int sum = 0;

		for (auto v : vec)
		{
			if (v - mid > 0)
				sum += v - mid;
		}

		if (sum < m)
			end = mid - 1;
		else
		{
			start = mid + 1;
			result = mid;
		}
	}

	cout << result;
}
int main()
{
	int n,m;
	cin >> n>>m;

	vector<int> trees(n,0);

	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		trees[i] = num;
	}

	solution(n,m, trees);
}