#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void solution(int n, vector<int> & hubs)
{
	int result = 0;

	sort(hubs.begin(), hubs.end());
	int start = 1;
	int end = hubs[hubs.size() - 1] - hubs[0];


	while (start <= end)
	{
		int mid = (start + end) / 2;
		int cnt = 1;
		int prev = hubs[0];

		for (int i = 1;i < hubs.size();++i)
		{
			if (hubs[i] - prev >= mid)
			{
				cnt++;
				prev = hubs[i];
			}
		}

		if (cnt >= n)
		{
			result = max(mid, result);
			start = mid + 1;
		}
		else
			end = mid - 1;
	}

	cout << result;
}
int main()
{
	int n,c;
	cin >> n>>c;

	vector<int> hubs(n,0);

	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		hubs[i] = num;
	}

	solution(c, hubs);
}