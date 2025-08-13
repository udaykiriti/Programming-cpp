#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n; cin >> n;
    vector<ll> a(n), m(n), s(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    m[0] = a[0];
    s[0] = m[0];
    for (int i = 1; i < n; i++) {
        m[i] = min(m[i - 1], a[i]);
        s[i] = s[i - 1] + m[i];
    }
    ll r = s[n - 1];
    const ll inf = 4e18;
    for (int i = 0; i < n - 1; i++) {
        ll p = i > 0 ? m[i - 1] : inf;
        ll q = i > 0 ? s[i - 1] : 0;
        ll c = a[i] + a[i + 1];
        ll t = min(p, c);
        r = min(r, q + t);
    }
    cout << r << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}