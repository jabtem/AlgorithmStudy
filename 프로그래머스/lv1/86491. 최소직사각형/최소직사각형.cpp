#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int width = 0;
    int height = 0;
    for(auto n : sizes)
    {
        //가로가 세로보다큰경우
        if(n[0] > n[1])
        {
            width=max(width,n[0]);
            height= max(height,n[1]);
        }
        //가로가 세로보다 작은경우
        else
        {
            width=max(width,n[1]);
            height= max(height,n[0]);
        }
    }
    return width*height;
}