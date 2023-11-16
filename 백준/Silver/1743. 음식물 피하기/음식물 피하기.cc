#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int map[101][101] = { 0 };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n, m, k;
int cnt;
int maxSize = -1;
void dfs(int x, int y)
{
	map[x][y] = 0;
	cnt++;
	for (int i = 0;i < 4;++i)
	{
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		if (nextX <= n && nextX >= 0 && nextY <= m && nextY >= 0 && map[nextX][nextY] == 1)
		{
			dfs(nextX, nextY);
		}
	}

}

int main()
{
	cin >> n >> m >> k;

	for (int i = 0; i < k;++i)
	{
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
	}

	for (int i = 1; i <= n;++i)
	{
		for (int j = 1; j <= m;++j)
		{
			cnt = 0;
			if (map[i][j] == 1)
			{
				dfs(i, j);
			}
			maxSize = max(maxSize, cnt);
		}
	}

	cout << maxSize;
}