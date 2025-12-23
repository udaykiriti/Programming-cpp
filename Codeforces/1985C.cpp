#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n; cin>>n;
    ll cs(0), mx(-1), cnt(0);
    for(ll p = 0; p < n; p++){
        ll x; cin>>x;
        mx = (mx > x ? mx : x);
        cs += x;
        cnt += (cs == 2 * mx);
    }
    cout<<cnt<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    ll t; cin>>t;
    while(t--) solve();
}