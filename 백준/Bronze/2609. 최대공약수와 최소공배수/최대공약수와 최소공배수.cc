#include <iostream>

using namespace std;
int GCD(int a, int b)
{
	int gcd = a % b;

	while (gcd != 0)
	{
		a = b;
		b = gcd;
		gcd = a % b;
	}

	return b;
}

int main()
{
    int a,b;
    cin >> a >> b;
    
    int gcd = GCD(a,b);
    
    cout << gcd << endl;
    cout << a*b/gcd;
}