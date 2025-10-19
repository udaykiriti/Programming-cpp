#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll ok(int a, int b, int c) {
    cout << a << " " << b << " " << c << endl << flush;
    ll l; cin >> l;
    return l;
}

void solve(){
    int n; cin >> n;

    ll xx = (ll)n * (n + 1) / 2;

    ll a = ok(2, 1, n);
    ll k = a - xx;

    int l = 1, h = n;
    int ans = n;
    while (l <= h) {
        int m = l + (h - l) / 2;

        ll lp = ok(2, 1, m);

        ll pa = ok(1, 1, m);

        if (lp > pa) {
            ans = m;
            h = m - 1;
        } else {
            l = m + 1;
        }
    }
    ll res = (ll)ans + k - 1;
    
    cout << "! " << ans << " " << res << endl << flush;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1),tcase(0); cin >> t;
    while (++tcase,t--) solve();
    return 0;
}
