#include <iostream>

using namespace std;

int main() 
{
	string result = "";
	string board;
	cin >> board;
	int cnt = 0;
	board += " ";

	for (auto c : board)
	{
		if (cnt == 2 && c != 'X')
		{
			result += "BB";
			cnt = 0;
		}
		else if (cnt == 4)
		{
			result += "AAAA";
			cnt = 0;
		}

		if (c == 'X')
			cnt++;
		else if (c == '.')
		{
			result += c;
			if (cnt % 2 != 0)
				break;
			else
				cnt = 0;
		}
	}

	if (cnt % 2 == 1)
		cout << -1;
	else
		cout << result;

}