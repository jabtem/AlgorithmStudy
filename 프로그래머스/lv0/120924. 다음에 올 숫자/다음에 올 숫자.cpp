#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    
    //등차수열
    if((common[1]-common[0]) == (common[2]-common[1]))
    {
        return common.back() + (common[1]-common[0]);
    }
    //등비수열
    else
    {
        int n = common[1]/common[0];
        
        return common.back()*n;
    }
    
}