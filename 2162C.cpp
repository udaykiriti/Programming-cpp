/******************************
 *    author:  uday           *
 *    created: 17 21:20:25    *
 ******************************/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define exor(a,b) a^b
#define endl '\n'

void solve() {
    ll p, q; cin >> p >> q;

    if (p == q) {
        cout << 0 << endl;
        return;
    }
    ll temp = p;
    int l(0);
    while ((1LL << l) <= temp) l++;
    l--;

    ll res = (1LL << l + 1) - 1;

    if (q > res) {
        cout << -1 << endl;
        return;
    }

    ll s = exor(p , q);

    if (s <= p) {
        cout << 1 << endl;
        cout << s << endl;
    } else {
        ll b = exor(res,q);
        ll a = exor(res,p);
        cout << 2 << endl;
        cout << a << " " << b << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1),tcase(0); cin >> t;
    while (++tcase,t--) solve();
    return 0;
}
