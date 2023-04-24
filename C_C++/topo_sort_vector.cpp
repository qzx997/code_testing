#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e4 + 7;
const ll mod = 1e9 + 7;
#define pi atan(1.0)*4


const int N = 1001;
const int M = 10001;

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
		
		for(vector<Node>:: iterator k = G[now].begin(); k != G[now].end(); ++k)
		{
			Node t = *k;
			int v = t.v;
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


