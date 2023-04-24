// 朋友关系 
// 邻接表存带权图 
 
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
//ios::sync_with_stdio(false);
typedef long long ll;
const ll maxn = 1e4 + 7;
const ll mod = 1e9 + 7;
#define pi atan(1.0)*4

map<string, int> m;

int G[110][110];

int ids = 0;
int find(string a)
{
	if (m.count(a) == 0)
	{
		m[a] = ++ids;
	}
	else
	{
		return m[a];
	}
}
 

int main()
{
	memset(G, 0, sizeof(G));
	int n;
	cin >> n;
	while(n--)
	{
		string a, b;
		cin >> a >> b;
		int x = find(a), y = find(b);
		G[x][y] = G[y][x] = 1;
	}
	
	int m;
	cin >> m;
	while(m--)
	{
		string a, b;
		cin >> a >> b;
		int x = find(a), y = find(b);
		if(G[x][y] == 1)
		{
			cout << "Yes" << endl;
		}
		else cout << "No" << endl;
	}
	
	return 0;
}

