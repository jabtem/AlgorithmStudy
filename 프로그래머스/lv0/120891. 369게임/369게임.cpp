#include <string>
#include <vector>

using namespace std;

int solution(int order) {
    int answer = 0;
    
    do
    {
        int n = order%10;
        if(n%3 == 0 && n>0)
        {
            ++answer;
        }
        order /= 10;
    }while(order>0);
    
    return answer;
}