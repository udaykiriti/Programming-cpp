#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
using vii = vector<lli>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        lli n, k; cin >> n >> k;
        vii a(n), b(n);
        for (lli i = 0; i < n; ++i) cin >> a[i];
        for (lli i = 0; i < n; ++i) cin >> b[i];

        lli ans = 0, mx = b[0], sum = 0;
        for (lli i = 0; i < n && i < k; ++i) {
            mx = max(mx, b[i]);
            sum += a[i];
            ans = max(ans, sum + mx * (k - i - 1));
        }
        cout << ans << "\n";
    }
    return 0;
}
