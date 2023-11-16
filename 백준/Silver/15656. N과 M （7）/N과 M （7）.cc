#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Permutation(vector<int> arr, vector<int> perm, int depth = 0)
{
	if (perm.size() == depth)
	{
		for (int i = 0; i < perm.size();++i)
		{
			cout << perm[i] << " ";
		}
		cout << "\n";

		return;
	}

	for (int i = 0; i < arr.size();++i)
	{
		perm[depth] = arr[i];
		Permutation(arr, perm, depth + 1);
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

	Permutation(arr, perm);
}