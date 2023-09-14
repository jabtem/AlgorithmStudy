#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    int size = numbers.size();
    if(size >2)
    {
        sort(numbers.begin(),numbers.end());
        int max1 = numbers[0]*numbers[1];
        int max2 = numbers[size-1]*numbers[size-2];
        
        return max1 > max2 ? max1 : max2;
        
    }
    else
    {
        return numbers[0]*numbers[1];
    }
}