#include <iostream>
using namespace std;

int apple[20];

void solution(int n, int m, int j)
{
	int start = 1;
	int end = m;
	int count = 0;

	for (int i = 0; i < j; ++i)
	{
		//사과위치
		int x = apple[i];

		//범위내면 안움직임
		if (start <= x && x <= end)
			continue;
		else if (start > x)
		{
			int sub = start - x;
			count += sub;
			start -= sub;;
			end -= sub;;
		}
		else
		{
			int sub = x - end;
			count += sub;
			start += sub;;
			end += sub;;
		}
	}
	cout << count;
}
int main()
{
	int n,m;
	cin >> n>>m;

	int j;
	cin >> j;
	for (int i = 0; i < j; ++i)
	{
		cin >> apple[i];
	}

	solution(n,m,j);
}