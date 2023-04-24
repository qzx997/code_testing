#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e6 + 7;
const ll mod = 1e9 + 7;
#define pi atan(1.0)*4

const int N = 32;
vector<int> v;
int qmi(int a, int k)
{
    int res = 1;
    while (k)
    {
        if (k & 1)
            res = res * a;
        a = a * a;
        k >>= 1;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    
    int x;
    cin >> x;
    
    int fa = x / 160;
    int cnt = fa;
    int r = 0, l = 0;
    int tp;
    while (fa / 10) {
        r = fa % 10;
        fa /= 10;
        cnt += (3 * fa + l) / 5;
        tp = l;
        l = (3 * fa + l) % 5;
        fa = r +(3 * fa + tp) / 5;
    }
    
    cout << cnt << endl;
    return 0;
}
