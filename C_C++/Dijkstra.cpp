#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll;
const ll maxn = 1e6 + 7;
const ll mod = 1e9 + 7;
#define pi atan(1.0)*4

const int N = 1001;
const int M = 10001;

struct edge{
	int v, w, next;
	edge(){}
	edge(int _v, int _w, int _next)
	{
		v = _v;
		w = _w;
		next = _next;
	}
}e[M*2];

int head[N], size;

void init()
{
	memset(head, -1, sizeof(head));
	size = 0;
}

void insert_single_dir(int u, int v, int w)
{
	e[size] = edge(v, w, head[u]);
	head[u] = size++;
}

void insert_double_dir(int u, int v, int w)
{
	insert_single_dir(u,v,w);
	insert_single_dir(v,u,w);
}

int n, m;
int dis[N]; 	// distance
bool vis[N];	// visit	
void dijkstra(int u)
{
	memset(vis, false, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	dis[u] = 0;
	for(int i=0;i<n;i++)
	{
		int mind = 100000000, minj = -1;	// d 距离 	j 编号
		for (int j=1;j<=n;j++)
		{
			if(!vis[j] && dis[j] < mind) // 找到相邻最短的点 
			{
				minj = j;
				mind = dis[j];
			}
		}
		if(minj == -1)
		{
			return;
		}
		vis[minj] = true;		// 标记 
		for(int j=head[minj]; ~j; j = e[j].next) // ~j  ====   j != -1
		{
			int v = e[j].v;
			int w = e[j].w;
			if(!vis[v] && dis[v] > dis[minj] + w)
			{
				dis[v] = dis[minj] + w;
			}
		}
	}
}



int main()
{
	ios::sync_with_stdio(false);
	init();
	
	int u, v, w;
	cin >> n >> m;
	while(m--)
	{
		cin >> u >> v >> w;
		insert_double_dir(u, v, w);
	}
	dijkstra(1);
	cout << endl << "到每个点的最短路径：" << endl;
	for (int i=1;i<=n;i++)
		cout << dis[i] << " ";
	cout << endl << endl;
	
	cout << "e:" << endl;
	for (int i=1;i<=3;i++)
	{
		cout << e[i].v << " " << e[i].w << " " << e[i].next << endl;
	}
	
	for (int i=1; i<=6;i++)
	{
		cout << head[i] << " ";
	}
	
	return 0;
}

