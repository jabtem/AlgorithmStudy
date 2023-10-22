#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Combination(vector<int> arr, vector<int> comb,int index = 0, int depth = 0)
{
    if (depth == comb.size())
    {
        for (int i = 0; i < comb.size();++i)
        {
            cout << comb[i] << " ";
        }
        cout << "\n";

        return;
    }

    for (int i = index; i<arr.size();++i)
    {
        comb[depth] = arr[i];
        Combination(arr, comb, i,depth + 1);
    }
}

int main() 
{    
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);

    for (int i = 0; i < arr.size();++i)
        arr[i] = i + 1;

    vector<int> comb(m);

    Combination(arr, comb);
}