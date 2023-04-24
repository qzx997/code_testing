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

void insert_double_dir(int u, int v, int w)
{
	insert_single_dir(u, v, w);
	insert_single_dir(v, u, w);
}

int n, m;
int indegree[N], degree[N];
int cnt = 0;
bool vis[N];
void dfs(int u)
{
	vis[u] = true;
	cnt ++;
	for(int i=head[u];i!=-1;i=e[i].next)
	{
		int v = e[i].v;
		if(!vis[v])
		{
			dfs(v);
		}
	}
}

void euler_no_dir()
{
	memset(vis, 0, sizeof(vis));
	dfs(1);
	if(cnt != n)
	{
		cout << "不存在欧拉路" << endl;
		cout << cnt << endl;
		return ;
	}
	int cntodd = 0;
	for(int i=1;i<=n;i++)
	{
		if(indegree[i] % 2 == 1)
		{
			cntodd++;
		}
	}
	if(cntodd == 0)
	{
		cout << "存在欧拉图" << endl;
	}
	else if(cntodd == 2)
	{
		cout << "存在欧拉路" << endl;
	}
	else
	{
		cout << "不存在欧拉路" << endl; 
	}
}


int euler_dir()
{
	int first = 0, last = 0;
	for(int i = 1; i <= n; i ++)
	{
		if(degree[i] < -1 || degree[i] > 1)
		{
			cout << "不存在欧拉路" << endl;
			return 0;
		}
		else if(degree[i] == -1)
		{
			if(first != 0)
			{
				cout << "不存在欧拉路" << endl;
				return 0;
			}
			else
			{
				first = i;
			}
		}
		else if(degree[i] == 1)
		{
			if(last != 0)
			{
				cout << "不存在欧拉路" << endl;
				return 0;
			}
			else
			{
				last = i;
			}
		}
	}
	if(first == 0 && last == 0)
	{
		cout << "存在欧拉图" << endl;
		return 1;
	}
	else if(first != 0 && last != 0)
	{
		cout << "存在欧拉路" << endl;
		return first;
	}
}


int main()
{
	ios::sync_with_stdio(false);
	int flag = 2; 	//  1 无向图        2 有向图 
	init();
	memset(indegree, 0, sizeof(indegree));
	cin >> n >> m;
	for (int i=0;i<m;i++)
	{
		int u, v;
		cin >> u >> v;
		if(flag == 1)
		{
			insert_double_dir(u, v, 1);
			indegree[u]++; 
			indegree[v]++;
		}
		else if(flag == 2)
		{
			insert_single_dir(u, v, 1);
			degree[u]--; 
			degree[v]++;
		}
		
	}
	if(flag == 1) euler_no_dir();
	else if(flag == 2) euler_dir();
	
	return 0;
}



/*
无向图 
in
4 4 
1 2 
3 2 
1 3
2 4
out
存在欧拉图



有向图     
in
4 4 
2 1 
3 2 
1 3
2 4
out
存在欧拉图

*/


