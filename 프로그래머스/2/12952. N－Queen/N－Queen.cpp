#include <string>
#include <vector>

using namespace std;

//n번째 행에 놓인 퀸의 열위치
int col[13] = { 0 };
int answer = 0;

bool isValid(int row)
{
    int nextRow = 1;
    bool flag = true;
    while (nextRow < row && flag)
    {
        if (col[row] == col[nextRow] || abs(col[row] - col[nextRow]) == (row - nextRow))
            flag = false;
        nextRow += 1;
    }
    return flag;
}

void n_queens(int row, int n)
{
    if (isValid(row))
    {
        if (row == n)
            answer++;
        else
        {
            for (int j = 1; j <= n; ++j)
            {
                if (row + 1 <= n)
                {
                    col[row + 1] = j;
                    n_queens(row + 1, n);
                }

            }
        }
    }

}

int abs(int a, int b)
{
    return (a - b) > 0 ? a - b : -(a - b);
}

int solution(int n) {
    n_queens(0,n);
    return answer;
}