#include <bits/stdc++.h>
using namespace std;
#define int long long
#define V vector
#define A array
#define F first
#define S second
#define PB push_back
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define ALL(x) (x).begin(),(x).end()
#define R(x) scanf("%lld",&x)

void solve() {
    int n, m; R(n); R(m);
    V<A<int,3>> e(m);
    FOR(i,0,m) R(e[i][0]), R(e[i][1]), R(e[i][2]);
    sort(ALL(e), [](auto &x, auto &y){ return x[2] < y[2]; });
    
    V<int> p(n+1), r(n+1,0), M(n+1,LLONG_MAX);
    iota(p.begin(), p.end(), 0);

    function<int(int)> f = [&](int x){ return p[x]==x ? x : p[x]=f(p[x]); };

    int ans = LLONG_MAX;
    for(auto &x : e) {
        int u = f(x[0]), v = f(x[1]), w = x[2];
        if(u != v) {
            int mm = min({M[u], M[v], w});
            if(r[u] < r[v]) swap(u,v);
            p[v] = u;
            M[u] = mm;
            if(r[u] == r[v]) r[u]++;
        }
        int c = f(1);
        if(c == f(n)) ans = min(ans, M[c] + w);
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int T; R(T);
    while(T--) solve();
    return 0;
}
