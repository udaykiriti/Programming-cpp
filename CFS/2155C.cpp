#include <bits/stdc++.h>
using namespace std;
const int MOD = 676767677;
#define ll long long
#define vi vector<int>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)

bool valid(int n, const vi& q, int L) {
    if (L < 0 || L > n) return false;
    int prev(0);
    FOR(i, 1, n) {
        int r = L + q[i] - prev;
        int s = r - prev;
        if (s != 0 && s != 1) return false;
        if (r < 0 || r > i) return false;
        prev = r;
    }
    return prev == L;
}

void solve() {
    int n(1); cin >> n;
    vi p(n + 1), q(n + 1);
    FOR(i, 1, n) cin >> p[i];
    FOR(i, 1, n) q[i] = p[i] - (n - i + 1);

    ll ans (0);
    int c1 = -q[1];
    int c2 = 1 - q[1];
    if (valid(n, q, c1)) ++ans;
    if (c1 != c2 && valid(n, q, c2)) ++ans;

    cout << ans % MOD << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T(1),tcase(0); cin >> T;
    while (tcase++,T--) solve();
    return 0;
}
