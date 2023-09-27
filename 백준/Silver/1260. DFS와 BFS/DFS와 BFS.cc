#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 1001;

bool check[MAX];

void dfs(int v, vector<int> g[])
{
	cout << v << " ";
	check[v] = true;
	for (auto n : g[v])
	{
		if (!check[n])
		{
			dfs(n, g);
		}
	}

}
void bfs(int v, vector<int> g[])
{

	cout << v << " ";
	queue<int> q;
	check[v] = 1;
	q.push(v);

	while (!q.empty())
	{
		int n = q.front();
		q.pop();

		for (auto i : g[n])
		{
			if (!check[i])
			{
				q.push(i);
				check[i] = true;
				cout << i << " ";
			}
		}
	}
}

int main()
{
	int n, m, v;
	cin >> n >> m >> v;

	vector<int> graph[MAX];

	for (int i = 0; i < m; ++i)
	{
		int s, e;
		cin >> s >> e;
		graph[s].emplace_back(e);
		graph[e].emplace_back(s);
	}

	for (int i = 1; i <= n;++i)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(v, graph);
	cout << endl;

	for (int i = 1;i <= n;++i)
	{
		check[i] = false;
	}
	bfs(v, graph);

}
