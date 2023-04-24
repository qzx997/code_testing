#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e7 + 7;
const ll mod = 998244353;
#define pi atan(1.0)*4

int G[300][300];

bool gimp_transform_polygon_is_convex(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4)
{
	ll z1, z2, z3, z4;
 
	z1 = ((x2 - x1) * (y4 - y1) - (x4 - x1) * (y2 - y1));
	z2 = ((x4 - x1) * (y3 - y1) - (x3 - x1) * (y4 - y1));
	z3 = ((x4 - x2) * (y3 - y2) - (x3 - x2) * (y4 - y2));
	z4 = ((x3 - x2) * (y1 - y2) - (x1 - x2) * (y3 - y2));
 
	return (z1 * z2 > 0) && (z3 * z4 > 0);
}

int main()
{
	ios::sync_with_stdio(false);
	
	int n,m;
	cin >> n >> m;
	while(n--)
	{
		ll x, y;
		cin >> x >> y;
		G[x][y] = 1; // red
	}
	while(m--)
	{
		ll x, y;
		cin >> x >> y;
		G[x][y] = 2;
	}
	
	
//	cout << G[1][2] << endl;
	
	return 0;
}
