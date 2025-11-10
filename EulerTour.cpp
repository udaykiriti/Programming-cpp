/* Euler Tour (entry-only) + iterative DFS + Fenwick (BIT)
Supports: point update (change node value) and subtree sum query.
Input format (example usage):
n q
a1 a2 ... an
n-1 edges (u v)
then q queries of form:
1 v x   -> set node v to x (point update)
2 v     -> print sum over subtree of v */

/*
 https://en.wikipedia.org/wiki/Euler_tour_technique
 https://en.wikipedia.org/wiki/File:Stirling_permutation_Euler_tour.svg
 https://codeforces.com/blog/entry/68138
 https://codeforces.com/blog/entry/18369
*/

/* 
 Tree:
      1
     / \
    2   3
   / \
  4   5

Flattened Array:
idx: 1  2  3  4  5
val: 1  2  4  5  3 
*/

/* Intution:
Euler Tour works by recording the order in which nodes are entered during a DFS, so every subtree’s nodes appear contiguously in this order.
This lets you turn subtree queries on a tree into range queries on an array. 
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Fenwick {
    int n;
    vector<ll> f;
    Fenwick(int n=0){init(n);}
    void init(int N){ n=N; f.assign(n+1,0); }
    void add(int i, ll delta){ for(; i<=n; i += i&-i) f[i]+=delta; }
    ll sum(int i){ ll s=0; for(; i>0; i -= i&-i) s+=f[i]; return s; }
    ll sum(int l, int r){ if(r<l) return 0; return sum(r)-sum(l-1); }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    if(!(cin>>n>>q)) return 0;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];

    vector<vector<int>> g(n+1);
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // iterative DFS to compute tin, tout, subsz and flatten values
    vector<int> tin(n+1,0), tout(n+1,0), parent(n+1,0), order; order.reserve(n);
    vector<int> stk;
    stk.reserve(n*2);
    stk.push_back(1);
    parent[1]=0;
    // iterative stack to build parent + traversal order (preorder)
    while(!stk.empty()){
        int u = stk.back(); stk.pop_back();
        order.push_back(u);
        for(int v: g[u]){
            if(v==parent[u]) continue;
            parent[v]=u;
            stk.push_back(v);
        }
    }
    // order is a preorder but children were pushed in adjacency order reversed;
    // compute tin/tout using another stack (postorder style) to compute sizes
    int timer=0;
    vector<int> subsz(n+1,0);
    // simulate recursion: pair(node, state) state=0 enter, state=1 exit
    vector<pair<int,int>> s2; s2.reserve(2*n);
    s2.emplace_back(1,0);
    while(!s2.empty()){
        auto [u,st]=s2.back(); s2.pop_back();
        if(st==0){
            tin[u]=++timer;
            s2.emplace_back(u,1);
            for(int v: g[u]){
                if(v==parent[u]) continue;
                s2.emplace_back(v,0);
            }
        } else {
            subsz[u]=1;
            for(int v: g[u]) if(parent[v]==u) subsz[u]+=subsz[v];
            tout[u]=tin[u]+subsz[u]-1;
        }
    }

    // build flattened values and fenwick
    vector<ll> flat(n+1,0);
    for(int i=1;i<=n;i++) flat[tin[i]] = a[i];
    Fenwick bit(n);
    for(int i=1;i<=n;i++) if(flat[i]) bit.add(i, flat[i]);

    // process queries
    while(q--){
        int type; cin>>type;
        if(type==1){
            int v; ll x; cin>>v>>x; // set node v to x
            ll cur = bit.sum(tin[v], tin[v]);
            ll delta = x - cur;
            if(delta) bit.add(tin[v], delta);
        } else if(type==2){
            int v; cin>>v;
            cout << bit.sum(tin[v], tout[v]) << '\n';
        } else {
            // optional: support more ops if needed
        }
    }
    return 0;
}
