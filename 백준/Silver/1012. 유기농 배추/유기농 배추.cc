#include <iostream>
#include <vector>
using namespace std;
int map[51][51] = { 0 };

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int t,m, n, k;

vector<int> answer;
void dfs(int x, int y)
{
	map[x][y] = 0;

	for (int i = 0; i < 4; ++i)
	{
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		if (nextX < m && nextX >= 0 && nextY < n && nextY >= 0 && map[nextX][nextY] == 1)
		{
			dfs(nextX, nextY);
		}
	}

}

int main()
{
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int count = 0;
		cin >> m >> n >> k;

		for (int i = 0; i < k; ++i)
		{
			int x, y;
			cin >> x >> y;
			map[x][y] = 1;
		}



		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (map[i][j] == 1)
				{
					dfs(i, j);
					count++;
				}
			}
		}
		answer.emplace_back(count);
	}

	for (auto n : answer)
	{
		cout << n << endl;
	}

}