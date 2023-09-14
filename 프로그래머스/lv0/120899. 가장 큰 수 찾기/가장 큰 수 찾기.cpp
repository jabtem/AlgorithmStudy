#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array) {
    int max = *max_element(array.begin(),array.end());
    int index = max_element(array.begin(),array.end()) - array.begin();
    
    vector<int> answer;
    
    answer.push_back(max);
    answer.push_back(index);
    return answer;
}