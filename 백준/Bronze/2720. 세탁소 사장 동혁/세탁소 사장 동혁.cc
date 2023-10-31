#include <iostream>
#include <vector>
using namespace std;


void solution(int n)
{
	vector<int> v(4);

	v[0] = n*0.04;
	n %= 25;
	v[1] = n*0.1;
	n %= 10;
	v[2] = n*0.2;
	n %= 5;
	v[3] = n;

	for (auto num : v)
	{
		cout << num << " ";
	}
	cout << "\n";
}
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int num;
		cin >> num;
		solution(num);
	}
}