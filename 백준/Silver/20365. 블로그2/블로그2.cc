#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	int N;
	string word;

	cin >> N;
	cin >> word;

	char color = 'n';
	int blueCount = 0;
	int redCount = 0;

	for (auto c : word)
	{
		if (color == 'n')
		{
			if (c == 'B')
			{
				color = 'B';
				blueCount++;
			}
			else
			{
				color = 'R';
				redCount++;
			}
		}
		else if(color != 'n' && color != c)
		{
			if (c == 'B')
			{
				color = 'B';
				blueCount++;
			}
			else
			{
				color = 'R';
				redCount++;
			}
		}
	}

	int minCount = min(blueCount, redCount);
	cout << minCount+1 << "\n";
}
