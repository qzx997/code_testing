#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e7;

int ksm(int a, int b)
{
	int ans = 1,base = a;
	while(b!=0)
	{
		if(b & 1 != 0)
		{
			ans = (ans * base) % mod;
		}
		base = (base * base) % mod;
		b >>= 1;
	}
	return ans;
}


int main()
{
	int a, b = 0;
	cin >> a;
	int i=0;
	while(a)
	{
		b += (a%8 * ksm(10,i));
		a /= 8;
		i++;
	}
	cout << b << endl;
	
	return 0;
}
