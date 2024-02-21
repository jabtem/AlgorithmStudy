#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


int main()
{
	int N;
	cin >> N;

	vector<int> vec(N, 0);

	for (int i = 0; i < N;++i)
	{
		cin >> vec[i];
	}
	int result = 0;

	for (int i = 1; i < N - 1;++i)
	{
		//벌 벌 꿀통
		int value1 = accumulate(vec.begin() + 1, vec.end(), 0) - vec[i] + accumulate(vec.begin() + i + 1, vec.end(), 0);
		//꿀통 벌 벌
		int value2 = accumulate(vec.begin(), vec.end() - 1, 0) - vec[N - 1 - i] + accumulate(vec.begin(), vec.end() - 1 - i, 0);
		//벌 꿀통 벌
		int value3 = accumulate(vec.begin() + 1, vec.begin() + 1 + i, 0) + accumulate(vec.begin() + i, vec.end() - 1, 0);
		
		result = max(result,max(max(value1, value2),value3));
	}

	cout << result << "\n";
}
