// https://ac.nowcoder.com/acm/problem/13583
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e5 + 7;
const ll mod = 1e9 + 7;
#define pi atan(1.0)*4

int main(){
    int n;
    int m;
    while(cin>>n){
        cin>>m;
        int res=n;
        vector<int> pos(m);
 
        for(int i=0;i<m;i++){
            cin>>pos[i];
            pos[i]--;
        }
        sort(pos.begin(),pos.end());
        res=min(res,max(abs(pos[0]-(pos[0]+pos.back())/2),abs(pos.back()-(pos[0]+pos.back())/2)));
        for(int i=0;i<m;i++){
            pos.push_back(pos[i]+n);
            res=min(res,max(abs(pos[i+1]-(pos[i+1]+pos.back())/2),abs(pos.back()-(pos[i+1]+pos.back())/2)));
        }
        cout<<res<<endl;
         
    }
    return 0;
}
