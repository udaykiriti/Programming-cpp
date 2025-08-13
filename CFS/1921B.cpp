#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define ln "\n"
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define scan(x) cin >> x

void solve() {
    i64 n;
    scan(n);
    string x, y;
    scan(x);
    scan(y);

    i64 plus = 0, minus = 0;
    FOR(p, 0, n) {
        if (x[p] == '1' && y[p] == '0') {
            ++plus;
        } else if (x[p] == '0' && y[p] == '1') {
            ++minus;
        }
    }

    cout << max(plus, minus) << ln;
}

int main() {
    fast_io;
    int t; cin>>t;
    while(t--) solve();
    return 0;
}