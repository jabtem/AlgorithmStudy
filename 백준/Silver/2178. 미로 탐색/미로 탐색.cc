#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct Node
{
	int x, y, d;
	Node(int x, int y, int d = 0) :x(x), y(y), d(d) {}
	Node() { d = 0; }

	bool operator>(const Node& other)const
	{
		return d > other.d;
	}
};

template <typename T>
int dijkstar(vector<vector<T>>& map,Node start, Node end, T w)
{

	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };

	bool check[101][101] = { false };
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

		for (int i = 0; i < 4; ++i)
		{
			int x = current.x + dx[i];
			int y = current.y + dy[i];

			if (x >= 0 && x < n && y >= 0 && y < m && !check[x][y] && map[x][y] != w)
			{
				int d = current.d + 1;
				check[x][y] = true;
				q.push(Node(x, y, d));
			}
		}
	}

	return -1;
}

int main()
{
	int n, m;

	cin >> n >> m;

	vector<vector<char>> map(n);


	for (int i = 0; i < n;++i)
	{
		for (int j = 0; j < m; ++j)
		{
			char t;
			cin >> t;
			map[i].push_back(t);
		}
	}

	Node start(0, 0, 1);
	Node end(n - 1, m - 1, 0);

	int distance = dijkstar(map, start, end, '0');

	cout << distance;
}