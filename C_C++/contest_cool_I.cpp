#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e6 + 7;
const ll mod = 1e9 + 7;
#define pi atan(1.0)*4

struct edge{
	int v, d, next;
} e[M];
int p[N], eid;

struct studentList{
	int a, p, q;
};

int N, MAX, currity;
studentList stu[maxn];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int n;
	cin >> n;
	N = n;
	for(int i=0;i<n;i++)
	{
		cin >> stu[i].a >> stu[i].p >> stu[i].q;
	}
	
	
	return 0;
}
