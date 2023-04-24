#include<cstdio>
#include<cstring>
#include<algorithm>
#define _Clr(x, y) memset(x, y, sizeof(x))
#define INF 0x3f3f3f3f
#define N 5000
using namespace std;

int head[N], tot;
struct Edge
{
    int to, next;
    Edge(){}
    Edge(int a, int b):to(b), next(head[a]){}
}edge[N<<1];
int n, ans;

void Init()
{
    tot = 0;
    _Clr(head, -1);
}

void Add_edge(int a, int b)
{
    edge[tot] = Edge(a, b);
    head[a] = tot++;
}

bool used[N];
int dist[N];
void dfs(int u, int len)
{
    used[u] = 1;
    dist[u] = len;
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
         int v = edge[i].to;
         if(used[v])
            ans = max(ans, dist[v]-dist[u]+1);
        else
            dfs(v, len+1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    int t = n-1; t*=2;
    while(t--)
    {
    	int x, y;
    	cin >> x >> y;
    	if(t<=n-1) x += n, y += n;
    	Add_edge(x, y);
    	Add_edge()
	}
    
    return 0;
}
