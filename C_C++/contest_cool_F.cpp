#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

ll quick_pow(ll a,ll b)
{
	ll ans = 1,base = a;
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
	ios::sync_with_stdio(false);
	
	ll t, num, cnt;
	cin >> t;
	ll i = 1;
	while(t>0){
		if(t - quick_pow(2,i) >= 0) num = quick_pow(2,i);
		else num = t;
		cnt += i*num;
		t -= quick_pow(2,i);
		i++;
	}
	
	
	cout << cnt << endl;
	
	return 0;
}
