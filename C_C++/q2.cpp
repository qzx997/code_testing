// https://ac.nowcoder.com/acm/problem/13223
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e9 + 7;
const ll mod = 1e9 + 7;
#define pi atan(1.0)*4

ll a[maxn];
int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		scanf("%lld", &a[i]);
	}
	int cnt = 1;
	for(int i=1;i<n;i++)
	{
		if(a[0] >= a[i]) cnt++;
	}
	
	cout << floor(log(cnt)*1.0/log(2)) << endl;
//	cout << cnt << endl;
	
	return 0;
}
