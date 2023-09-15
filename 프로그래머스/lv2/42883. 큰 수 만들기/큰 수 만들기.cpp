#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    //결과값의 글자수
    int answerLength = number.size()-k;
    int startIndex=0;
    for(int i=0; i< answerLength; ++i)
    {
        //처음엔 시작인덱스가 최대자릿수
        int maxIndex= startIndex;
        for(int j = startIndex; j<= k+i; ++j)
        {
            //최대값이 바뀌는경우
            if(number[maxIndex] < number[j])
            {
                maxIndex = j;
            }
        }
        
        answer += number[maxIndex];
        startIndex = maxIndex + 1;
    }
    
    
    return answer;
}