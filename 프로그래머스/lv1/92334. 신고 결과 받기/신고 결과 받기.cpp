#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(),0);
    //신고된사람 신고한사람
    unordered_map<string,set<string>> reported;
    //id 인덱스
    unordered_map<string,int> index;
    
    for(int i=0; i < id_list.size(); ++i)
    {
        index[id_list[i]] = i;
    }
    
    for(auto r : report)
    {
        istringstream ss(r);
        
        //신고자
        string name1 = "";
        //신고대상
        string name2 = "";
        
        ss >> name1 >> name2;
        
        reported[name2].insert(name1);
    }
    
    for(auto r : reported)
    {
        if(r.second.size() >=k)
        {
            for(auto repoter : r.second)
            {
                answer[index[repoter]]++;
            }
        }
    }
    
    return answer;
}