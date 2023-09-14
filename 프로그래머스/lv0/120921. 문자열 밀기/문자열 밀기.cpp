#include <string>
#include <vector>
using namespace std;

int solution(string A, string B) {
    if(A == B)
        return 0;
    string origin = A;
    int answer = 0;
    do
    {
        A = A.substr(A.length()-1) + A.substr(0,A.length()-1);
        ++answer;
        if(A == B)
        {
            return answer;
        }
    }while(A != origin);

    return -1;
}