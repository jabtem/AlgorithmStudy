#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool compareII(pair<int, int> a, pair<int, int>b)
{
	return a.second > b.second;
}

bool compareSI(pair<string, int> a, pair<string, int>b)
{
	return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string,vector<pair<int, int>>> playList;
    unordered_map<string,int> playTotal;
    
    for(int i=0; i< genres.size(); ++i)
    {
        //장르 인덱스 플레이수 순으로 기록
        playList[genres[i]].push_back({i,plays[i]});
        //장르의 총 플레이수 합산
        playTotal[genres[i]] += plays[i];
    }
    
    //Vector로 저장 후 장르 총재생 횟수 내림차순 정렬
    vector<pair<string,int>> playTotalVec(playTotal.begin(),playTotal.end());
    sort(playTotalVec.begin(),playTotalVec.end(),compareSI);
    
    for(auto p : playTotalVec)
    {
        //재생횟수 기준으로 내림차순
        sort(playList[p.first].begin(), playList[p.first].end(), compareII);
        answer.push_back(playList[p.first][0].first);
        if(playList[p.first].size() > 1)
            answer.push_back(playList[p.first][1].first);
    }
    
    return answer;
}