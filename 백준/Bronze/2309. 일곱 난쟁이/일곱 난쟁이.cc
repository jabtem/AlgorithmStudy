#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int num[9];
	int sum = 0;
	int except[2];
	vector<int> v;

	for (int i = 0; i < 9; ++i)
	{
		int n;
		cin >> n;
		num[i] = n;
		sum += n;
	}

	for (int i = 0; i < 8;++i)
	{
		for (int j = i+1; j < 9;++j)
		{
			if (sum - (num[i] + num[j]) == 100)
			{
				except[0] = i;
				except[1] = j;
				break;
			}
		}
	}

	for (int i = 0; i < 9; ++i)
	{
		if (i == except[0] || i == except[1])
			continue;

		v.push_back(num[i]);
	}

	sort(v.begin(), v.end());

	for (auto n : v)
	{
		cout << n << endl;
	}

}