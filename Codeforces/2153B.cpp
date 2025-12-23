#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define ull unsigned long long
#define EXIT return 0

void solve() {
    ull p,q,r; cin>>p>>q>>r;
    
    ull cp = (p&q&~r) != 0ULL;
    ull cq = (p&r&~q) != 0ULL;
    ull cr = (q&r&~p) != 0ULL;
    bool res = cp or cq or cr;
    if(res) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int main(int argc , char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while (t--) solve();
    EXIT;
}
