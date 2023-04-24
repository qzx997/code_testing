#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 7;
const int M = 1e4 + 7;
const int inf = 0x3f3f3f3f;
#define pi atan(1.0)*4

struct edge{
	int v, w, fail;
	edge(){}
	edge(int _v, int _w, int _fail)
	{
		v = _v;
		w = _w;
		fail = _fail;
	}
}e[M << 1];
int head[N], len;
void init(){
	memset(head, -1, sizeof(head));
	len = 0;
}
void insert_single_dir(int u, int v, int w)
{
	e[len] = edge(v, w, head[u]);
	head[u] = len++;
}

void insert_double_dir(int u, int v, int w)
{
	insert_single_dir(u,v,w);
	insert_single_dir(v,u,w);
}

int n, m;
int dis[N];
bool vis[N];
void spfa(int u)
{
	memset(vis, false, sizeof(vis));
	vis[u] = true;
	memset(dis, 0x3f, sizeof(dis));
	dis[u] = 0;
	queue<int> q;
	q.push(u);
	while(!q.empty())
	{
		u = q.front();
		q.pop();
		vis[u] = false;
		for(int j=head[u];~j;j=e[j].fail)
		{
			int v = e[j].v;
			int w = e[j].w;
			if(dis[v] > dis[u] + w )
			{
				dis[v] = dis[u] + w;
				if(!vis[v])
				{
					q.push(v);
					vis[v] = true;
				}
			}
		}
	}
}

int main()
{
	int u, v, w;
	cin >> n >> m;
	while(m--)
	{
		cin >> u >> v >> w;
		insert_double_dir(u, v, w);
//		insert_single_dir(u, v, w);
	}
	spfa(1);
	for (int i=1;i<=n;i++)
	{
		cout << dis[i] << " ";
	}
	cout << endl;
	
	return 0;
}



/*
²âÊÔÑùÀı 
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



ÓĞÏòÍ¼ 
in
5 10
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
out
0 2 2 1 2 3
*/

