// 朋友关系 
// 邻接表存带权图 
 
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll;
const ll maxn = 1e6 + 7;
const ll mod = 1e9 + 7;
#define pi atan(1.0)*4

struct Node{
	int v;
	ll len;
};

vector<Node> G[110]; 

void insert_single_dir(int u, int v, int w)
{
	Node temp;
	temp.v = v;
	temp.len = w;
	G[u].push_back(temp);
}

void insert_double_dir(int u, int v, int w)
{
	insert_single_dir(u, v, w);
	insert_single_dir(v, u, w);
}

set<int> cnt;
void search(int i)
{
	if(cnt.count(i) > 0) return;
	cnt.insert(i);
	cout << i << " ";
	int min_ids = i;
	ll min_num = maxn;
	for(int j=0;j<G[i].size();j++)
	{
		if(G[i][j].len < min_num)
		{
			min_num = G[i][j].len;
			min_ids = G[i][j].v;
		}
	}
	
	search(min_ids);
}

int main()
{
	int n, m;
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int u, v;
		ll w;
		cin >> u >> v >> w;
		insert_double_dir(u, v, w);
	}
	
	search(1);
	
	return 0;
}

