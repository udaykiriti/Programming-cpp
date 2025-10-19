#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int M = 400005;
const int INF = 1e9;
vector<int> s(M);

void Sieve(){
    iota(s.begin(), s.end(), 0);
    for (ll i = 2; i * i < M; ++i)
        if (s[i] == i)
            for (ll j = i * i; j < M; j += i)
                if (s[j] == j) s[j] = i;
}

void g(int n, vector<int>& f){
    f.clear();
    if (n <= 1) return;
    while (n > 1){
        int p = s[n];
        f.push_back(p);
        while (n % p == 0) n /= p;
    }
}

vector<pair<int,int>> m1(M, {INF, -1}), m2(M, {INF, -1});
vector<int> tp;

void u(int p, int c, int idx){
    if (m1[p].first == INF) tp.push_back(p);
    if (c < m1[p].first){
        if (m1[p].second != idx) m2[p] = m1[p];
        m1[p] = {c, idx};
    } else if (c < m2[p].first && m1[p].second != idx){
        m2[p] = {c, idx};
    }
}

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    vector<int> f;
    for (int i = 0; i < n; ++i){
        g(a[i], f);
        for (int p : f) u(p, 0, i);
        g(a[i] + 1, f);
        for (int p : f) u(p, 1, i);
    }
    int ans = INF;
    for (int p : tp) if (m2[p].first != INF) ans = min(ans, m1[p].first + m2[p].first);
    cout << ans << '\n';
    for (int p : tp){ m1[p] = {INF, -1}; m2[p] = {INF, -1}; }
    tp.clear();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Sieve();
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
