#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
#define ln "\n"
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr)
#define GG return 0
#define PRINT(x) cout << x << ln
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define SORT(v) sort((v).begin(), (v).end())

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    FOR(i, 0, n) cin >> a[i];
    SORT(a);
    int cnt = 0;
    FOR(i, 0, (n + 1) / 2) cnt += a[n - 1 - i] - a[i];
    PRINT(cnt);
}

int main() {
    fast_io;
    int t; cin >> t;
    while (t--) solve();
    GG;
}
