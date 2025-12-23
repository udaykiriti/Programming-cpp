#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll p, q, u, v; cin >> p >> q >> u >> v;
    if (p == q) {
        cout<<(0);
    } else if (p > q) {
        cout<<((p % 2 == 1 && q == p - 1) ? v : -1);
    } else {
        ll d = q - p;
        ll m = (d + (p % 2)) / 2;
        ll n = d - m;
        cout<<(m * u + n * min(u, v));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll t; cin>>t;
    while(t--) solve();
    return 0;
}