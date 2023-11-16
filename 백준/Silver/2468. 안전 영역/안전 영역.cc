#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int map[101][101] = { 0 };
bool visited[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n;
int maxSize = -1;
void dfs(int x, int y, int height)
{
	visited[x][y] = true;

	for (int i = 0;i < 4;++i)
	{
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		if (visited[nextX][nextY])
			continue;

		if (nextX < n && nextX >= 0 && nextY < n && nextY >= 0 && map[nextX][nextY]>height)
		{
			dfs(nextX, nextY,height);
		}
	}
}

void visitedReset()
{
	for (int i = 0;i < n;++i)
	{
		for (int j = 0;j < n;++j)
		{
			visited[i][j] = false;
		}
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i <n;++i)
	{
		for (int j = 0;j < n;++j)
		{
			cin >> map[i][j];
		}
	}


	for (int k = 0; k <= 100;++k)
	{
		int cnt = 0;
		visitedReset();
		for (int i = 0;i < n;++i)
		{
			for (int j = 0; j < n;++j)
			{
				if (map[i][j] > k && !visited[i][j])
				{
					cnt++;
					dfs(i, j, k);
				}
			}
		}

		maxSize = max(cnt, maxSize);
	}

	cout << maxSize;
}