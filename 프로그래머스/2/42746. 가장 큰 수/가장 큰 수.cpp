#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//문자를 합쳤을때 더큰쪽을 기준으로 정렬
bool compare(string a, string b) {
    return stoi(a + b) > stoi(b + a);
}


string solution(vector<int> numbers) {
    string answer = "";
    vector <string> numString;

    for (auto i : numbers) {
        numString.push_back(to_string(i)); //numbers를 String으로 변환
    }
    sort(numString.begin(), numString.end(), compare);

    if (numString[0] == "0")
    {
        return "0";
    }

    for (auto i : numString)
        answer += i;

    return answer;
}