#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map <string, int> hashMap;

    //각행이 의상이름, 의상종류로 이뤄져있음, 동일의상 X
    for (auto vec : clothes)
    {
        //의상 종류, 개수 순으로 저장
        hashMap[vec[1]]++;
    }
    //해쉬맵 처음부터 끝가지 반복
    for (auto type : hashMap)
    {
        //타입개수 + 타입 하나도 사용안하는경우
        //예 모자 2개 -> 모자를쓰는경우 2가지 + 모자를 안쓰는경우 1가지
        answer *= type.second + 1;
    }

    //아무것도 안입는경우는 없으므로 결과에서 -1
    return answer-1;
}