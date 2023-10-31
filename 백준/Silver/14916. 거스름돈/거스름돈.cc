#include <iostream>
using namespace std;


void solution(int n)
{
	//5원개수
	int count = n * 0.2;
	//잔돈
	int rest = n % 5;

	while (count > 0 && rest % 2 != 0)
	{
		count--;
		rest += 5;
	}

	count += rest * 0.5;

	if (rest % 2 == 0)
		cout << count;
	else
		cout << -1;
}
int main()
{
	int n;
	cin >> n;
	solution(n);
}