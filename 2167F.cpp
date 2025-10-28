#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long
#define pb push_back

void dfs(int u , int p, vi G[],vi &s){
    s[u] = 1;
    for(int v : G[u]){
        if(v==p) continue;
        dfs(v,u,G,s);
        s[u]+=s[v];
    }
}

void solve(){
    int n,k;
    cin >> n>> k;

    vi G[n+1];
    vi s(n+1);

    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >>v;
        G[u].pb(v);
        G[v].pb(u);
    }

    dfs(1,0,G,s);
    ll res = n;
    for(int i=2;i<=n;i++){
        ll Sb = s[i];
        ll OuTS = n-Sb;

        if(Sb >= k) {
            res+=OuTS;
        }
        if(OuTS >= k){
            res+=Sb;
        } 
    }
    cout<<res<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}