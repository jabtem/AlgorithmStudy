#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
using namespace std;


int main() 
{
	int N, X;
	cin >> N >> X;
	vector<int> vec(N, 0);
	int maxNum = 0;
	int result;
	int count = 1;
	for (int i = 0; i < vec.size();++i)
	{
		cin >> vec[i];
	}

	int sum = accumulate(vec.begin(), vec.begin() + X, 0);
	result = sum;

	for (int i = X; i < N;++i)
	{
		sum = sum + vec[i] - vec[i-X];
		if (result == sum)
		{
			++count;
		}
		else if (sum > result)
		{
			result = sum;
			count = 1;
		}
	}

	if (result)
	{
		cout << result << "\n";
		cout << count;
	}
	else
		cout << "SAD";
	
}
