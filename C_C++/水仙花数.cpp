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
	for(int a=100;a<=999;a++)
	{
		if(ksm(a/100,3) + ksm(a/10%10,3) + ksm(a%10,3) == a)
		{
			cout << a << endl;
		}
	}
	
	return 0;
}
