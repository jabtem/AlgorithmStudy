#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() 
{
	long long result;
	int N;
	cin >> N;
	vector<long long> vec(N, 0);
	for (int i = 0;i < N; ++i)
	{
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());


	if (vec.size() % 2 == 0)
	{	
		result = vec[0] + vec[vec.size() - 1];
		for (int i = 1; i < vec.size()/2;++i)
		{
			result = max(result, vec[i] + vec[vec.size() -1 -i]);
		}
	}
	else
	{
		result = vec[0] + vec[vec.size() - 2];
		for (int i = 1; i < vec.size() / 2;++i)
		{
			result = max(result, vec[i] + vec[vec.size() -2 -i]);
		}

		result = max(result, vec[vec.size() - 1]);
	}

	cout << result << "\n";
}
