// 判断无向图是否是完全图 
 
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll;
const ll maxn = 1e6 + 7;
const ll mod = 1e9 + 7;
#define pi atan(1.0)*4

int G[110][110];

int main()
{
	memset(G, 0, sizeof(G));
	int n, m; 	// n < 100 , m < 20000
	cin >> n >> m;
	if(m != n*(n-1)/2) 
	{
		cout << "No" << endl;
		return 0;
	}  
	for(int i=0;i<m;i++)
	{
		int u, v;
		cin >> u >> v;
		G[u][v] = G[v][u] = 1;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)  
			{
				if(G[i][j] != 0) {
					cout << "No" << endl;
					return 0;
				}
			}
			else if(G[i][j] == 0) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	
	return 0;
}

