#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<(n);++i)
#define all(x) begin(x), end(x)
#define pb push_back
#define R(x) reverse(all(x))
#define B bitset<300>
#define V vector
#define G V<V<int>>

int Gt(int v,bool b){return v*2+(b?0:1);}
int N;

void solve(){
    int n,k; cin>>n>>k;
    N=2*n;
    G g(N),gr(N);

    FOR(z,k){
        B a[300]; int m; cin>>m;
        while(m--){
            int u,v; cin>>u>>v; --u,--v;
            a[u][v]=a[v][u]=1;
        }
        FOR(u,n)FOR(v,u){
            B au=a[u],av=a[v];
            au[u]=au[v]=av[u]=av[v]=0;
            if(au!=av) continue;
            bool h=a[u][v];
            if(h){
                int a1=Gt(u,1),b1=Gt(v,0);
                g[a1].pb(b1); gr[b1].pb(a1);
                int a2=Gt(v,1),b2=Gt(u,0);
                g[a2].pb(b2); gr[b2].pb(a2);
            }else{
                int a1=Gt(u,0),b1=Gt(v,1);
                g[a1].pb(b1); gr[b1].pb(a1);
                int a2=Gt(v,0),b2=Gt(u,1);
                g[a2].pb(b2); gr[b2].pb(a2);
            }
        }
    }

    V<bool> vis(N,0); V<int> ord;
    function<void(int)> dfs1=[&](int x){
        vis[x]=1;
        for(int y:g[x]) if(!vis[y]) dfs1(y);
        ord.pb(x);
    };
    FOR(i,N) if(!vis[i]) dfs1(i);

    V<int> comp(N,-1); int cid=0;
    function<void(int)> dfs2=[&](int x){
        comp[x]=cid;
        for(int y:gr[x]) if(comp[y]==-1) dfs2(y);
    };
    R(ord);
    for(int x:ord) if(comp[x]==-1) dfs2(x), ++cid;

    bool ok=1;
    FOR(i,n) if(comp[Gt(i,0)]==comp[Gt(i,1)]) ok=0;
    cout<<(ok?"Yes\n":"No\n");
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; if(!cin>>t) return 0;
    while(t--) solve();
    return 0;
}