#include <string>
#include <vector>

using namespace std;

//2~n까지의 소수
vector<int> IsPrime(int n) {
	bool* isPrime = new bool[n + 1];
	vector<int> vec;
	for (int i = 0; i <= n; i++) {
		isPrime[i] = true;
	}


	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {
			vec.push_back(i);
			for (int j = i * 2; j <= n; j += i) {
				isPrime[j] = false;
			}
		}
	}

	delete[] isPrime;
	return vec;
}

//최대공약수
int GCD(int a, int b)
{
    int gcd = a%b;
    while(gcd !=0)
    {
        a = b;
        b = gcd;
        gcd = a % b;
    }
    
    return b;
}

int solution(int a, int b) {
    int gcd = GCD(a,b);
    vector<int> vec;
    b /= gcd;
    int answer = 1;
    vec = IsPrime(b);
    
    for(int n : vec)
    {
        if(n != 2 && n!= 5)
        {
            if(b%n == 0)
            {
                return 2;
            }
        }
    }
    
    return answer;
}