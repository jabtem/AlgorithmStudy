#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

//선물기록
int giftLog[50][50];

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    //이름별 인덱스
    map<string,int> nameIndex;
    //선물지수
    map<string,int> giftFactor;
    
    //다음달 선물개수
    vector<int> nextMonth(friends.size(),0);
    
    for(int i=0; i < friends.size(); ++i)
    {
        nameIndex[friends[i]] = i;
    }
    
    for(string gift : gifts)
    {
        stringstream ss(gift);
        string sender,recipient;
        ss >> sender >> recipient;
        
        giftFactor[sender]++;
        giftFactor[recipient]--;
        giftLog[nameIndex[sender]][nameIndex[recipient]]++;
    }
    
    for(int i=0; i< friends.size(); ++i)
    {
        for(int j=i+1; j< friends.size(); ++j)
        {
            string sender = friends[i];
            string recipient = friends[j];
            int senderIndex = nameIndex[sender];
            int recipientIndex = nameIndex[recipient];
            
            //선물을 받은것보다 준게 더 많은경우
            if(giftLog[senderIndex][recipientIndex] > giftLog[recipientIndex][senderIndex])
            {
                nextMonth[senderIndex]++;
            }
            //선물 준거보다 받은게 더 많은경우
            else if(giftLog[senderIndex][recipientIndex] < giftLog[recipientIndex][senderIndex])
            {
                nextMonth[recipientIndex]++;
            }
            //선물준개수가 같은경우
            else
            {
                //선물지수가 준사람이 더높은경우
                if(giftFactor[sender] > giftFactor[recipient])
                {
                    nextMonth[senderIndex]++;
                }
                //선물지수가 받은사람이 더높은경우
                else if(giftFactor[sender] < giftFactor[recipient])
                {
                    nextMonth[recipientIndex]++;
                }
            }
        }
    }
    
    answer = *max_element(nextMonth.begin(),nextMonth.end());
    return answer;
}