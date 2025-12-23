#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define SUM(v) accumulate((v).begin(), (v).end(), 0LL)
#define ll long long
#define SQ(x) ((ll)(x)*(x))

void solve() {
    int n; cin >> n;
    int p, q, r, s; cin >> p >> q >> r >> s;
    vector<int> v(n);
    int m = 0;
    FOR(i,0,n) {
        cin >> v[i];
        m = MAX(m, v[i]);
    }
    ll t = SUM(v);
    ll x = p - r;
    ll y = q - s;
    ll d = SQ(x) + SQ(y);
    ll R = t;
    ll L = 0;
    if (n > 0) {
        ll u = t - m;
        L = max(0LL, (ll)m - u);
    }
    ll LL = SQ(L);
    ll RR = SQ(R);
    if (d >= LL && d <= RR) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) solve();
}