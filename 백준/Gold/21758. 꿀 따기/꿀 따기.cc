#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


int main()
{
	int N;
	cin >> N;

	vector<int> honey(N + 1, 0);
	vector<int> sum(N + 1, 0);

	for (int i = 1; i <= N;++i)
	{
		cin >> honey[i];
		sum[i] = sum[i - 1] + honey[i];
	}
	int result = 0;

	for (int i = 2; i < N; ++i)
	{
		//벌 벌 꿀통
		int value1 = (sum[N] - sum[1] - honey[i]) + (sum[N] - sum[i]);
		//꿀통 벌 벌
		int value2 = (sum[N - 1] - honey[i]) + sum[i - 1];
		//벌 꿀통 벌
		int value3 = (sum[i] - honey[1]) + (sum[N - 1] - sum[i - 1]);

		result = max(result, max(max(value1, value2), value3));
	}

	cout << result << "\n";
}
