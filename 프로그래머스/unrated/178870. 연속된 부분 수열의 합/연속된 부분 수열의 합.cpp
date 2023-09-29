#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int s = 0;
    int e = 0;

    int sum = sequence[0];
    vector<int> answer;

    int minSize = sequence.size() + 1;
    int minS = 0;
    int minE = 0;
    while (s<=e && e < sequence.size())
    {
        if (sum < k)
        {
            sum += sequence[++e];

            if (e >= sequence.size())
                break;
        }
        else
            sum -= sequence[s++];

        if (sum == k && e - s < minSize)
        {
            minSize = e - s;
            minS = s;
            minE = e;
        }
    }
    
    answer.push_back(minS);
    answer.push_back(minE);
    
    return answer;
}