#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e7 + 7;
const ll mod = 998244353;
#define pi atan(1.0)*4

struct Node{
	ll x, y;
};
Node red[300];
Node yellow[300];

bool judge(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4)
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
	for(int i=0;i<n;i++)
	{
		cin >> red[i].x >> red[i].y;
		
	}
	for(int i=0;i<m;i++)
	{
		cin >> yellow[i].x >> yellow[i].y;
	}
	
//	cout << judge(1,3,3,5,2,1,4,1) << endl;
//	cout << judge(1,1,2,2,1,2,1,2) << endl;	
	
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
			for(int k=0;k<m;k++)
				for(int d=k;d<m;d++)
				{
					bool result = judge(red[i].x, red[i].y, yellow[k].x, yellow[k].y,
										 yellow[d].x, yellow[d].y, red[j].x, red[j].y);
//					cout << red[i].x << red[i].y << red[j].x << red[j].y << 
//							yellow[k].x << yellow[k].y << yellow[d].x << yellow[d].y << endl;
					if(result == 1)
					{
						cout << "YES" << endl;
						return 0;
					}
				}
	}
	cout << "NO" << endl;
	
	return 0;
}



/*
test1
3 3
1 5
1 3
4 1
2 1
4 2
3 5

NO

*/
