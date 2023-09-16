#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	//보석개수, 가방개수
	int n, k;
	//보석 정보
	vector<vector<int>> jewel;
	priority_queue<int> pq;
	
	//가방용량
	vector<int> capacity;
	cin >> n >> k;

	for (int i = 0;i < n; ++i)
	{
		int weight, price;

		cin >> weight >> price;
		jewel.push_back({weight ,price});
	}

	for (int i = 0; i < k; ++i)
	{
		int c;
		cin >> c;
		capacity.push_back(c);
	}
	sort(jewel.begin(), jewel.end());
	sort(capacity.begin(), capacity.end());

	int index = 0;
	long long answer = 0;

	for (auto c : capacity)
	{
		while (index < n && jewel[index][0] <= c)
		{
			pq.push(jewel[index++][1]);
		}

		if (!pq.empty())
		{
			answer += pq.top();
			pq.pop();
		}
	}

	cout << answer << endl;
}