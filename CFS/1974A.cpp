#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int x, y; cin >> x >> y;
        int ans = y / 2 + (y % 2);
        int r = 15 * ans - 4 * y;
        int v = (x > r) ? (x - r + 14) / 15 : 0;
        cout << ans + v << "\n";
    } return 0;
}
