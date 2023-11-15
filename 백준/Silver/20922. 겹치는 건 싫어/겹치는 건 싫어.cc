#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


void solution(int k, vector<int> & numbers)
{
	int result = 0;
	int s = 0;
	int e = 1;
	unordered_map<int, int> map;
	map[numbers[s]]++;

	while (s <= e && e < numbers.size())
	{
		if (map[numbers[e]] < k)
		{
			map[numbers[e++]]++;
			result = max(result, e - s);
		}
		else if (map[numbers[e]] == k)
		{
			map[numbers[s++]]--;
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