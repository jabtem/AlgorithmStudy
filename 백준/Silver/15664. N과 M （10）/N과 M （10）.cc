#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Combination(vector<int> arr, vector<int> comb,int index =0, int depth = 0)
{
	if (comb.size() == depth)
	{
		for (int i = 0; i < comb.size();++i)
		{
			cout << comb[i] << " ";
		}
		cout << "\n";

		return;
	}

	int prev = 0;

	for (int i = index; i < arr.size();++i)
	{
		if (arr[i] == prev)
			continue;

		prev = arr[i];
		comb[depth] = arr[i];
		Combination(arr, comb,i+1, depth + 1);
	}
}


int main()
{
	int n, r;
	cin >> n >> r;

	vector<int> arr(n,0);
	vector<int> perm(r);
	for (int i = 0; i < n;++i)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	Combination(arr, perm);
}