#include <string>
#include <vector>

using namespace std;

int solution(int chicken) {
    int coupon = chicken;
    int answer = 0;
    
    while(coupon>=10)
    {
        int service = coupon/10;
        answer+= service;
        coupon = coupon%10 + service;
    }
    return answer;
}