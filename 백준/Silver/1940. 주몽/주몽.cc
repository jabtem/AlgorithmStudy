#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void solution(int n, vector<int> & materials)
{
	int result = 0;
	int s = 0;
	int e = materials.size() - 1;

	int sum;
	sort(materials.begin(), materials.end());
	while (s < e)
	{
		sum = materials[s] + materials[e];

		if (sum == n)
		{
			s++;
			e--;
			result++;
		}
		else if (sum <= n)
			s++;
		else
			e--;
	}

	cout << result;
}
int main()
{
	int n,m;
	cin >> n>>m;

	vector<int> materials(n,0);

	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		materials[i] = num;
	}

	solution(m, materials);
}