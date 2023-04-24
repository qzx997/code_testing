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
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin >> G[i][j];
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			G[i][j] = max(G[i][j],G[j][i]);
			cout << G[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}

