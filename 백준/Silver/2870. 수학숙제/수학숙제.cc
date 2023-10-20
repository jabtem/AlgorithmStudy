#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//문자열 오름차순 정렬 
bool cmp(string a, string b) {
	if (a.length() < b.length()) 
		return true;
	if (a.length() == b.length()) 
		return a.compare(b) < 0;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	vector<string> nums;
	while (N--) {
		string input;
		cin >> input;

		vector<string> tmp;
		string num = "";
		int len = input.length();
		for (int i = 0; i < len; ++i) {
			if (('0' <= input[i]) && (input[i] <= '9')) {
				num += input[i];
			}
			else {
				if (num == "") continue;
				tmp.push_back(num);
				num = "";
			}
		}
		if (num != "") tmp.push_back(num);


		//숫자 앞에 0이 있는 경우 정리
		for (int i = 0; i < tmp.size(); ++i) {
			string num = tmp[i];
			string newNum = "";

			int len = num.length();
			for (int j = 0; j < len; ++j) {
				if (num[j] == '0') continue;
				else {
                	//num.substr(j): num의 인덱스 j부터 끝까지 문자열로 반환
					newNum = num.substr(j);
					break;
				}
			}
			if (newNum == "") newNum = "0";
			nums.push_back(newNum);
		}
	}

	sort(nums.begin(), nums.end(), cmp);
	for (int i = 0; i < nums.size(); ++i) {
		cout << nums[i] << "\n";
	}
	return 0;
}