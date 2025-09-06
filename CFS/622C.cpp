#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    vector<int> next_diff(n + 2, n + 1);
    for (int i = n - 1; i >= 1; --i)
        next_diff[i] = (a[i] != a[i + 1]) ? i + 1 : next_diff[i + 1];
    while (m--) {
        int l, r, x;
        cin >> l >> r >> x;
        if (a[l] != x) cout << l << '\n';
        else if (next_diff[l] > r) cout << -1 << '\n';
        else cout << next_diff[l] << '\n';
    }
}
