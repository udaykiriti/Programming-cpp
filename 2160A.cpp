#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define vi vector<int>

void solve(){
    int n; cin>>n;
    vi vec(n);
    for(auto &x : vec) cin>>x;
    unordered_set<int> ok;
    for(int i = 0; i < n; ++i)
        ok.insert(vec[i]);
    int res(0);
    while(ok.count(res))
        ++res;
    cout<<res<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1),tcase(0); cin>>t;
    while(++tcase,t--) solve();
    return 0;
}