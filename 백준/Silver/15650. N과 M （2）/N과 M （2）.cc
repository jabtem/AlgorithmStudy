#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{    
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);

    for (int i = 0; i < arr.size();++i)
        arr[i] = i + 1;

    vector<bool> v(n);
    for (int i = 0; i < m; ++i)
        v[i] = true;

    do
    {
        for (int i = 0; i < arr.size(); ++i)
        {
            if(v[i])
                cout << arr[i] << " ";
        }
        cout << "\n";

    } while (prev_permutation(v.begin(), v.end()));
}