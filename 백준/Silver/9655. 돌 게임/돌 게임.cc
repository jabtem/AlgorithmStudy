#include <iostream>
using namespace std;

void stoneGame(int n)
{
	if (n % 2 == 0)
	{
		cout << "CY";
	}
	else
	{
		cout << "SK";
	}
}

int main()
{

	int count = 0;

	int n;

	cin >> n;

	stoneGame(n);
}