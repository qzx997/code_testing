// ͼ��
// SPFA�ж�ͼ�еĸ��� 
// �ڽӱ�� ��Ȩͼ �� ����Ȩͼ 
// 
// SPFA �жϸ���ֻ����������ͼ��
// ���������бߵı�Ȩ��Ϊ�����Ļ� 
// ������ͼ�� һ����ȨΪ�������ڸ�������Ϊ���Է����� 
 
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
int dis[maxn], in[maxn], nr_point[maxn];
bool vis[maxn], nag_vis[maxn];
bool spfa_judge_nagtive_ring(int now)
{
	memset(vis, false, sizeof(vis));
	vis[now] = true;
	memset(dis, 0x3f, sizeof(dis));
	dis[now] = 0;
	memset(in, 0, sizeof(in));
	in[now] = 1;
	
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
			if(dis[now] + t.len < dis[t.v]) // ����dis 
			{
				dis[t.v] = dis[now] + t.len;
				if(!vis[t.v])
				{
					q.push(t.v);
					vis[t.v] = true;
					++in[t.v];
					if(in[t.v] > n)
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

void spfa_nagtive_ring_node(int now)
{
	memset(vis, false, sizeof(vis));
	vis[now] = true;
	memset(dis, 0x3f, sizeof(dis));
	dis[now] = 0;
	memset(in, 0, sizeof(in));
	in[now] = 1;
	memset(nr_point, 0, sizeof(nr_point));
	int num = 0;
	memset(nag_vis, false, sizeof(nag_vis));
	
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
			if(dis[now] + t.len < dis[t.v]) // ����dis 
			{
				dis[t.v] = dis[now] + t.len;
				if(!vis[t.v] && !nag_vis[t.v])
				{
					q.push(t.v);
					vis[t.v] = true;
					++in[t.v];
					if(in[t.v] > n)
					{
						nag_vis[t.v] = true;
						nr_point[++num] = t.v;
//						continue;
					}
				}
			}
		}
	}
	
	if(num == 0)
	{
		cout << endl << "ͼ�в����ڸ���" << endl; 
	}
	else
	{
		cout << endl << "ͼ�и����ϵĵ�ֱ��ǣ�" << endl;
		for(int i=1;i<=num;i++)
		{
			cout << nr_point[i] << " ";
		}
		cout << endl;
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
		insert_double_dir(u, v, w); 
//		insert_single_dir(u, v, w); 
	}
	
	spfa_nagtive_ring_node(1);
	
	
	
	return 0;
}
/*
�������� 

����ͼ 
in 
4 4
1 2 1
2 3 -1
1 3 -3
3 4 1
out 
yes


in 
3 3 
1 2 5
2 3 5
3 1 2
out 
no

����ͼ 
in 
4 5
1 2 1
2 3 -1
1 3 -3
3 4 1
4 2 -1
out 
yes

*/

