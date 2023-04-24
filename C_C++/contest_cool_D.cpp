#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e7 + 7;
const ll mod = 555555555;
#define pi atan(1.0)*4

ll ksc(ll a,ll b)
{
	ll ans = 0;
	while(b != 0)
	{
		if(b & 1 != 0 )
		{
			ans = (ans + a) % maxn;
		}
		a = (a + a) % maxn;
		b >>= 1;
	}
	return ans;
}

ll factorial(int n)
{
	ll m = 1;
	for (int i = 1; i <= n; i++){
		m = ksc(m,i);
	}
    return m;
}
 
ll C(int n, int m)
{
	return factorial(n) / ksc(factorial(m),factorial(n - m));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n, m, p, q;
	ll t;
	cin >> n >> m >> p >> q >> t;
	cout << ksc(C(n,p),C(m,q))%mod << endl;
	
	return 0;
}


