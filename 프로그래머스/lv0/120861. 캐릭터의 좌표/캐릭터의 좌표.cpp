#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    int boardWidth = board[0]>>1;
    int boardHeight = board[1]>>1;
    vector<int> answer = {0,0};
    
    for(string str : keyinput)
    {
        if(str == "left" && answer[0] > -boardWidth)
        {
            answer[0]--;
        }
        else if(str == "right" && answer[0] < boardWidth)
        {
            answer[0]++;          
        }
        else if(str == "up" && answer[1] < boardHeight)
        {
            answer[1]++;             
        }
        else if(str == "down" && answer[1] > -boardHeight)
        {
            answer[1]--;       
        }
    }
    

    return answer;
}