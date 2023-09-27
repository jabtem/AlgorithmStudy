#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void dfs(int v, vector<int>& ans, vector<bool>& check, vector<vector<int>>g)
{
	ans.push_back(v);
	check[v] = true;
	for (auto n : g[v])
	{
		if (!check[n])
		{
			dfs(n, ans, check, g);
		}
	}

}
void bfs(int v, vector<int>& ans, vector<bool>& check, vector<vector<int>>g)
{

	ans.push_back(v);
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
				ans.push_back(i);
			}
		}
	}
}

int main()
{
	int n, m, v;
	cin >> n >> m >> v;
	vector<vector<int>> graph(n + 1);
	vector<int> dfsAns;
	vector<bool> dfsCheck(n + 1, false);
	vector<int> bfsAns;
	vector<bool> bfsCheck(n + 1, false);

	for (int i = 0; i < m; ++i)
	{
		int s, e;
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	for (auto& g : graph)
	{
		std::sort(g.begin(), g.end());
	}


	dfs(v, dfsAns, dfsCheck, graph);
	bfs(v, bfsAns, bfsCheck, graph);


	for (auto n : dfsAns)
	{
		cout << n << " ";
	}
	cout << endl;
	for (auto n : bfsAns)
	{
		cout << n << " ";
	}
}