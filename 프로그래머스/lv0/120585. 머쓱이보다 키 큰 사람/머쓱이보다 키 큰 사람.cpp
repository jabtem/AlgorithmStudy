#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> array, int height) {
    
    sort(array.begin(),array.end(),[](int a,int b)
         {
             return a > b;
         });
        
    int answer = 0;
    
    for(int n : array)
    {
        if(n > height)
        {
            ++answer;            
        }
        else
            break;
    }
    return answer;
}