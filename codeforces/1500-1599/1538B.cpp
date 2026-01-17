#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
ll aarray[1000005];

void solve() {
    ll n, sum = 0, ans = 0;
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        ll x; cin >> x;
        aarray[i] = x;
        sum += x;
    }
    if (sum % n != 0) {
        cout << -1 << "\n";
        return;
    }
    ll eq = sum / n;
    for (ll i = 1; i <= n; i++) {
        if (aarray[i] > eq)
            ans++;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}
