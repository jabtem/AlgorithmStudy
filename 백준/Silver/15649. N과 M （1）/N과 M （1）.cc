#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{    
    int n, m;
    cin >> n >> m;
    vector<int> d(n);

    for (int i = 0; i < d.size();++i)
        d[i] = i + 1;

    do
    {
        for (int i = 0; i < m; ++i)
        {
            cout << d[i] << " ";
        }
        cout << "\n";

        reverse(d.begin() + m, d.end());

    } while (next_permutation(d.begin(), d.end()));
}