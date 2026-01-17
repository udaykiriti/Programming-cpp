#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
    x = max(0, x - a);
    y = max(0, y - b);
    cout << (x + y <= c ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}