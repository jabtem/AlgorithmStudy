#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


char map[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n;
int cnt;
int maxSize = -1;
void dfs(int x, int y)
{
	map[x][y] = '0';
	cnt++;
	for (int i = 0;i < 4;++i)
	{
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		if (nextX < n && nextX >= 0 && nextY < n && nextY >= 0 && map[nextX][nextY] == '1')
		{
			dfs(nextX, nextY);
		}
	}

}

int main()
{
	cin >> n;

	vector<int> answer;
	for (int i = 0; i < n;++i)
	{
		for (int j = 0; j < n;++j)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n;++i)
	{
		for (int j = 0; j < n;++j)
		{
			cnt = 0;
			if (map[i][j] == '1')
			{
				dfs(i, j);
			}

			if (cnt > 0)
				answer.emplace_back(cnt);
		}
	}

	sort(answer.begin(), answer.end());
	cout << answer.size() << "\n";

	for (auto ans : answer)
	{
		cout << ans << "\n";
	}
}