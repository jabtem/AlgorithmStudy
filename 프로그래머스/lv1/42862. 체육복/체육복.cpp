#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> student(n,1);
    int answer = 0;
    for(int i : reserve)
    {
        student[i-1]++;
    }
    for(int i : lost)
    {
        student[i-1]--;
    }
    
    for(int i=0; i< n ; ++i)
    {
        //첫번째학생이 아니고 앞사람이 체육복이 없는경우
        if(i != 0 && student[i-1] == 0)
        {
            if(student[i] > 1)
            {
                student[i-1]++;
                student[i]--;
            }
        }
        //마지만학생이 아니고 뒷사람이 체육복이 없는경우
        else if(i != n-1 && student[i+1] == 0)
        {
            if(student[i] > 1)
            {
                student[i+1]++;
                student[i]--;
            }
        }
    }
    
    for(int i : student)
    {
        if(i > 0)
            ++answer;
    }

    return answer;
}