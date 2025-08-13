#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define F(i,n) for(int i=0;i<(n);++i)
#define R(i,s,e) for(int i=(s);i<=(e);++i)
#define endl '\n'
#define vi vector<int>
#define bitset_size 200005
bitset<bitset_size> o; 

void solve() {
    int n; cin >> n;
    vi a(n);
    F(i,n) cin >> a[i];
    vector<vi> g(n);
    for (int i=1,u,v; i<n; ++i) {
        cin >> u >> v; --u; --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vi d(n), m(n), z(n);
    o.reset();
    F(i,n) {
        d[i] = (int)g[i].size();
        if (a[i]) o[a[i]] = 1;
    }
    F(v,n) for (int u : g[v])
        if (a[u]) m[v] = max(m[v], a[u]);
        else ++z[v];

    vi p(n+1);
    R(i,1,n) p[i] = p[i-1] + !o[i];
    vi nxt(n+2, n+1);
    for (int i = n; i >= 1; --i)
        nxt[i] = o[i] ? nxt[i+1] : i;
    auto fit = [&](int k, int need) {
        return p[k-1] >= need;
    };
    int ans = n+1;
    F(v,n) {
        int need = z[v];
        if (a[v]) {
            int k = a[v];
            if (d[v] < k && m[v] < k && fit(k, need))
                ans = min(ans, k);
        } else {
            int base = max({d[v]+1, m[v]+1, 2});
            if (p[n] < need) continue;
            int l = 1, r = n;
            while (l < r) {
                int mid = (l + r) / 2;
                if (p[mid] >= need) r = mid;
                else l = mid + 1;
            }
            int k = max(base, l + 1); int jumps = 0;
            while (k <= n && !fit(k, need) && jumps < 100) {
                k = nxt[k + 1];
                ++jumps;
            }
            if (k <= n && fit(k, need))
                ans = min(ans, k);
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
