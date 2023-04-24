#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e4 + 7;
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

int n, m;
int indegree[N];

void topo()
{
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(indegree[i] == 0)
		{
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int now = q.front();
		cout << now << endl;
		q.pop();
		for(int i=head[now]; i!=-1;i=e[i].next)
		{
			int v = e[i].v;
			indegree[v]--;
			if(indegree[v] == 0)
			{
				q.push(v);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	init();
	memset(indegree, 0, sizeof(indegree));
	cin >> n >> m;
	for (int i=0;i<m;i++)
	{
		int u, v;
		cin >> u >> v;
		insert_single_dir(u, v, 1);
		indegree[v]++;
	}
	topo();
	
	return 0;
}



/*

in
4 3 
1 2 
3 2 
2 4
out
1 3 2 4
*/


