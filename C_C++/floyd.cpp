#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll;
const ll maxn = 1e6 + 7;
const ll mod = 1e9 + 7;
#define pi atan(1.0)*4

const int N = 101;

int g[N][N];
void floyd(int n)
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	
	memset(g, 0x3f, sizeof(g));
	for(int i=0;i<N;i++)
	{
		g[i][i] = 0;
	}
	
	int n, m;
	int u, v, w;
	cin >> n >> m;
	while(m--)
	{
		cin >> u >> v >> w;
		g[u][v] = g[v][u] = w;
	}
	floyd(n);
	cout << endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
	
	
	return 0;
}




/*
ÑùÀý

in
3 3
1 2 5
2 3 5
3 1 2
out
0 5 2
5 0 5
2 5 0

*/ 

