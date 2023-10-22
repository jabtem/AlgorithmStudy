#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Permutation(vector<int> arr, vector<int> perm, int depth = 0)
{
    if (depth == perm.size())
    {
        for (int i = 0; i < perm.size();++i)
        {
            cout << perm[i] << " ";
        }
        cout << "\n";

        return;
    }

    for (int i = 0; i<arr.size();++i)
    {
        perm[depth] = arr[i];
        Permutation(arr, perm, depth + 1);
    }
}

int main() 
{    
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);

    for (int i = 0; i < arr.size();++i)
        arr[i] = i + 1;

    vector<int> perm(m);

    Permutation(arr, perm);
}