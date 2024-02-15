#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	vector<pair<int, int>> students;

	int N;
	cin >> N;

	vector<int> rank(N, 1);
	for (int i = 0; i < N;++i)
	{
		int weight;
		int height;

		cin >> weight >> height;

		students.push_back({ weight,height });
	}

	for (int i = 0;i < N;++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (i == j)
				continue;
			else
			{
				if (students[i].first > students[j].first && students[i].second > students[j].second)
				{
					rank[j]++;
				}
			}
		}
	}

	for (auto r : rank)
	{
		cout << r << " ";
	}
	cout << "\n";
}
