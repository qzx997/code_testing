// 图论test1
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

ios::sync_with_stdio(false);
int main()
{
	
	
	return 0;
}

