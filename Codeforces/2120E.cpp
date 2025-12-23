#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define in(x) cin >> x
#define out(x) cout << x << '\n'

void solve() {
    ll n,k; cin>>n>>k;
    vector<ll> a(n);
    ll s = 0, m = 0;
    FOR(i, n) {
        cin>>a[i];
        s += a[i];
        m = max(m, a[i]);
    }

    auto f = [&](ll c) {
        ll t = 0;
        FOR(i, n) {
            if (c + k >= 1) t += min(a[i], c + k);
            if (c > a[i]) t += c - a[i];
        }
        return t;
    };

    ll l = 1 - k, r = m + s;
    while (l < r) {
        ll mid = (l + r) >> 1;
        if (f(mid) >= s) r = mid;
        else l = mid + 1;
    }

    ll x = l;
    vector<ll> len(n);
    ll p = 0;
    FOR(i, n) {
        ll c = x - 1, t = 0;
        if (c + k >= 1) t += min(a[i], c + k);
        if (c > a[i]) t += c - a[i];
        len[i] = t;
        p += t;
    }

    ll need = s - p;
    FOR(i, n) {
        if (need == 0) break;
        ll next = len[i] < a[i] ? len[i] + 1 - k : len[i] + 1;
        if (next == x) {
            ++len[i];
            --need;
        }
    }

    ll ag = 0, mv = 0;
    FOR(i, n) {
        ag += len[i] * (len[i] + 1) / 2;
        if (a[i] > len[i]) mv += a[i] - len[i];
    }

    out(ag + k * mv);
}

int main() {
    fast_io; int t;
    if (!(cin >> t)) return 0;
    while (t--) solve();
    return 0;
}