#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int map[101][101] = { 0 };

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int rect = 0;
int m, n, k;
void dfs(int x, int y)
{
	map[x][y] = 1;

	for (int i = 0; i < 4; ++i)
	{
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		if (nextX < n && nextX >= 0 && nextY < m && nextY >= 0 && map[nextX][nextY] == 0)
		{
			rect++;
			dfs(nextX, nextY);
		}
	}

}

int main()
{

	int count = 0;
	vector<int>answer;
	cin >> m >> n >> k;

	for (int i = 0; i < k; ++i)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int x = x1; x < x2; ++x)
		{
			for (int y = y1; y < y2; ++y)
			{
				map[x][y] = 1;
			}
		}
	}


	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (map[i][j] == 0)
			{
				rect = 1;
				dfs(i, j);
				count++;
				answer.push_back(rect);
			}
		}
	}

	cout << count << endl;

	sort(answer.begin(), answer.end());

	for (auto n : answer)
	{
		cout << n << " ";
	}
	
}