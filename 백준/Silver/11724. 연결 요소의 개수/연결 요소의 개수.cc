#include <iostream>
#include <vector>
using namespace std;

vector<int> Node[1001];
bool Check[1001] = { false };


void dfs(int num)
{
	Check[num] = true;

	for (auto next : Node[num])
	{
		if (!Check[next])
			dfs(next);
	}
}

int main()
{
	int m, n;

	cin >> m >> n;

	int count = 0;

	for (int i = 0; i < n; ++i)
	{
		int start, end;

		cin >> start >> end;

		Node[start].push_back(end);
		Node[end].push_back(start);
	}

	for (int i = 1;i <= m;++i)
	{
		if (!Check[i])
		{
			dfs(i);
			count++;
		}
	}

	cout << count;

}