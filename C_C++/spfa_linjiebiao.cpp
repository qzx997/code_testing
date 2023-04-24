// 图论
// SPFA
// 邻接表存 带权图 和 不带权图 
 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e4 + 7;
const ll mod = 1e9 + 7;
#define pi atan(1.0)*4

struct Node{
	int v, len;
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

int n, m;
int dis[maxn];
bool vis[maxn];
void spfa(int now)
{
	memset(vis, false, sizeof(vis));
	vis[now] = true;
	memset(dis, 0x3f, sizeof(dis));
	dis[now] = 0;
	queue<int> q;
	q.push(now);
	while(!q.empty())
	{
		now = q.front();
		q.pop();
		vis[now] = false;
		for(vector<Node>:: iterator k = G[now].begin(); k != G[now].end(); ++k)
		{
			Node t = *k;
			if(dis[now] + t.len < dis[t.v]) // 计算dis 
			{
				dis[t.v] = dis[now] + t.len;
				if(!vis[t.v])
				{
					q.push(t.v);
					vis[t.v] = true;
				}
			}
		}
	}
}




int main()
{
	ios::sync_with_stdio(false);
	
	int u, v, w;
	cin >> n >> m;
	while(m--)
	{
		cin >> u >> v >> w;
//		insert_double_dir(u, v, w);
		insert_single_dir(u, v, w);
	}
	
	
	cout << endl << "邻接表：" << endl;
	for(int i = 1; i <= n; ++i)
	{
		for(vector<Node>:: iterator k = G[i].begin(); k != G[i].end(); ++k)
		{
			Node t = *k;
			cout << i << " " << t.v << " " << t.len << endl;
		}
		cout << endl;
	}
	
	cout << endl << endl;
	
	spfa(1);
	cout << endl << "到每个点的最短路径：" << endl;
	for (int i=1;i<=n;i++)
		cout << dis[i] << " ";
	cout << endl << endl;

	
	
	return 0;
}




/*
测试样例 
in 
4 6
1 3 5
1 4 9
1 2 3
3 2 2
3 4 4
2 4 1
out 
0 3 5 4


 
in
3 3
1 2 5
2 3 5
3 1 2
out
0 5 2


in
4 4
1 2 4
1 3 4
2 3 8
3 4 1
out 
0 4 4 5









有向图 
in
6 10
1 2 2 
1 3 5
1 6 9
2 4 -1
3 2 4
3 6 1
3 5 5
4 3 1
4 5 1
6 5 2
out
0 2 2 1 2 3



6 10
0 1 2 
0 2 5
0 5 9
1 3 -1
2 1 4
2 5 1
2 4 5
3 2 1
3 4 1
5 4 2

*/

