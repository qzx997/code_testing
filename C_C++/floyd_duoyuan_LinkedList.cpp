// 多源最短路
// Floyd

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


int main()
{
	ios::sync_with_stdio(false);
	
	return 0;
}
