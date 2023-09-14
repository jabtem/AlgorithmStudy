#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int solution(vector<int> array, int n) {
    int min = 100;
    int answer = 100;
    
    for(int num : array)
    {
        if(abs(n-num) < min)
        {
            min = abs(n-num);
            answer = num;
        }
        else if(abs(n-num) == min)
        {
            answer = (answer < num) ? answer : num;
        }
    }
    
    return answer;
}