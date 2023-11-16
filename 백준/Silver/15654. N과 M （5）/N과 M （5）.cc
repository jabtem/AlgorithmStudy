#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void Permutation(vector<int>arr, vector<int>perm, vector<bool>visited, int depth = 0)
{
	if (depth == perm.size())
	{
		for (int i = 0; i < perm.size();++i)
			cout << perm[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < arr.size();++i)
	{
		if (visited[i])
			continue;

		visited[i] = true;
		perm[depth] = arr[i];
		Permutation(arr, perm, visited, depth + 1);
		visited[i] = false;

	}
}
int main()
{
	int n, r;
	cin >> n >> r;

	vector<int> arr(n,0);
	vector<bool>visited(n);
	vector<int> perm(r);
	
	for (int i = 0; i < n;++i)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());


	Permutation(arr, perm, visited);
}