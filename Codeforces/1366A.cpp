#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve(){
    int x,y; cin>>x>>y;
    int res(0);
    if(x < y) swap(x,y);
    if(x/2 >= y) res=y;
    else res = (x+y)/3;
    cout<<res<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
