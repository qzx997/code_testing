// 1.5.4
// http://oj.saikr.com/problem/%E5%9F%BA%E7%A1%80%E7%8F%AD%E7%BB%83%E4%B9%A0-1.5.4
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e4 + 7;
const ll mod = 1e9 + 7;
#define pi atan(1.0)*4

struct Node{
	ll index, index_init, a;
};
Node N[maxn];

bool cmp(Node x, Node y)
{
	return x.a > y.a;
}

bool cmp2(Node x, Node y)
{
	return x.index_init < y.index_init;
}

int main()
{
	ll n, b[maxn];
	cin >> n;
	for(int i=0;i<n;i++)
	{
		scanf("%lld", &N[i].a);
		b[i] = N[i].a;
		N[i].index_init = i+1;
	}

	sort(N, N+n, cmp);
	for(int i=0;i<n;i++)
	{
		
		if(N[i].a == N[i-1].a)
		{
			N[i].index = i;
		}
		else
		{
			N[i].index = i+1;
		}
//		printf("%lld ",N[i].index_init);
	}
	
	// return to original sequence 
	sort(N,N+n,cmp2);
	for(int i=0;i<n;i++)
	{
		printf("%lld ",N[i].index);
	}
	
	return 0;
}
