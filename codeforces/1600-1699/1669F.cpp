#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve(){
    ll n; cin>>n;
    vector<ll>vec(n+1);
    for(ll i=0;i<n;i++) cin>>vec[i];
    ll l=0,r=n-1;
    ll p=0,q=0;
    int res=0;
    while(l<=r){
        if(q<p) q+=vec[l++];
        else p+=vec[r--];
        if(p==q) res=l+(n-r-1);
    } cout<<res<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
