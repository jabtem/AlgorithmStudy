#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int solution(vector<vector<int>> dots) {
    
    //선분 기울기
    float m1;
    float m2;
    //선분 01 23
    m1 = (float)(dots[1][1]-dots[0][1]) / (float)(dots[1][0]-dots[0][0]);
    m2 = (float)(dots[3][1]-dots[2][1]) / (float)(dots[3][0]-dots[2][0]);
    if(m1 == m2)
        return 1;

    //선분 02 13
    m1 = (float)(dots[2][1]-dots[0][1]) / (float)(dots[2][0]-dots[0][0]);
    m2 = (float)(dots[3][1]-dots[1][1]) / (float)(dots[3][0]-dots[1][0]);
    if(m1 == m2)
        return 1;
    
    //선분 03 12
    m1 = (float)(dots[3][1]-dots[0][1]) / (float)(dots[3][0]-dots[0][0]);
    m2 = (float)(dots[2][1]-dots[1][1]) / (float)(dots[2][0]-dots[1][0]);
    if(m1 == m2)
        return 1;

    return 0;
}