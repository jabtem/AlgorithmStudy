#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string) {
    transform(my_string.begin(), my_string.end(), my_string.begin(), [](unsigned char c) {
        return tolower(c);
    });
    
    sort(my_string.begin(),my_string.end());
    return my_string;
}