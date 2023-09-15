#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(vector<int> a , vector<int> b)
{
    return a[2] < b[2];
}

int find(vector<int>&v , int n)
{
    if(v[n] == n)
        return n;
    else
        return v[n] = find(v,v[n]);
}

void unionParent(vector<int>&v, int a, int b)
{
    //더작은쪽을 부모로함
    a < b ? v[b] = a : v[a] = b;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    //각노드의 부모를 저장하는벡터
    vector<int> root(n);
    
    for(int i=0; i<n; ++i)
    {
        //기본적으로 자기자신으로 초기화
        root[i] = i;
    }
    
    sort(costs.begin(),costs.end(), compare);
    
    for(auto c : costs)
    {
        int start = find(root,c[0]);
        int end = find(root,c[1]);
        
        //시작노드와 끝노드의 부모가 같지않은경우
        if(start != end)
        {
            answer += c[2];
            unionParent(root,start,end);
        }
        
    }
    
    return answer;
}