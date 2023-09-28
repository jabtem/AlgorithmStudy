#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 101;

bool check[MAX];
vector<int> graph[MAX];
void dfs(int v)
{
	for (int i = 0; i < graph[v].size(); ++i)
	{
		if (graph[v][i] == 1 && !check[i])
		{
			check[i] = true;
			dfs(i);
		}
	}
}

void reset()
{
	for (int i = 0; i < MAX; ++i)
	{
		check[i] = false;
	}
}

int main()
{

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int v;
			cin >> v;
			graph[i].emplace_back(v);
		}
	}


	for (int i = 0; i < n; ++i)
	{
		dfs(i);
		for (int j = 0; j < n; ++j)
		{
			cout << check[j] << " ";
		}
		cout << endl;
		reset();
	}


}