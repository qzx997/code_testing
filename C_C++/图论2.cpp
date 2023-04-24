// 图论test2
// 链表的邻接表存带权图 
 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e6 + 7;
const ll mod = 1e9 + 7;
#define pi atan(1.0)*4

const int M = 1000000;
const int N = 10000;

struct edge{
	int v, d, next;
} e[M];

int p[N], eid;
void init()
{
	memset(p, -1, sizeof(p));
	eid = 0;
}

void insert_single_dir(int u, int v, int d)
{
	e[eid].v = v;
	e[eid].d = d;
	e[eid].next = p[u];
	p[u] = eid++;
}

void insert_double_dir(int u, int v, int w)
{
	insert_single_dir(u, v, w);
	insert_single_dir(v, u, w);
}

void output(int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=p[i];j!=-1;j=e[j].next)
		{
			cout << i << "->" << e[j].v << ", " << e[j].d << endl;
		}
	}
}

ios::sync_with_stdio(false);
int main()
{
	
	
	return 0;
}

