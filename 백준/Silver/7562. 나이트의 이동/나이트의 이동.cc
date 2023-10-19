#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct Node
{
	int x, y, d;
	Node(int x, int y, int d = 0) :x(x), y(y), d(d) {}

	bool operator>(const Node& other)const
	{
		return d > other.d;
	}
};
bool check[301][301] = { false };
//나이트 이동가능한 8방향
int dx[8] = { 1,1,-1,-1,2,2,-2,-2 };
int dy[8] = { -2,2,2,-2,-1,1,1,-1 };

int knightMove(vector<vector<int>>& map, Node start, Node end)
{

	int n = map.size();
	int m = map[0].size();

	priority_queue<Node, vector<Node>, std::greater<>> q;

	q.push(start);
	check[start.x][start.y] = true;

	while (!q.empty())
	{
		Node current = q.top();
		q.pop();

		if (current.x == end.x && current.y == end.y)
		{
			return current.d;
		}

		for (int i = 0; i < 8; ++i)
		{
			int x = current.x + dx[i];
			int y = current.y + dy[i];

			if (x >= 0 && x < n && y >= 0 && y < m && !check[x][y])
			{
				int d = current.d + 1;
				check[x][y] = true;
				q.push(Node(x, y, d));
			}
		}
	}

	return -1;
}

void checkReset(int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			check[i][j] = false;
		}
	}
}

int main()
{
	vector<int>result;

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int size;
		cin >> size;

		vector<vector<int>> map(size + 1, vector<int>(size + 1, 0));

		int sX, sY;
		cin >> sX >> sY;

		int eX, eY;
		cin >> eX >> eY;
		Node start(sX, sY, 0);
		Node end(eX, eY, 0);
		checkReset(size);
		result.push_back(knightMove(map, start, end));
	}

	for (auto n : result)
	{
		cout << n << endl;
	}
}

