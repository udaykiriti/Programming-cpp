#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<pair<int, int>> v(n);
        int g1 = 1e9 + 7, g2 = 1e9 + 7, idx = -1;

        for (int i = 0; i < n; ++i) {
            int m, a, mn = 1e9 + 7, smn = 1e9 + 7;
            cin >> m;
            for (int j = 0; j < m; ++j) {
                cin >> a;
                if (a <= mn) smn = mn, mn = a;
                else if (a < smn) smn = a;
            }
            v[i] = {mn, smn};
            g1 = min(g1, mn);
            if (smn < g2) g2 = smn, idx = i;
        }
        long long res = 0;
        for (int i = 0; i < n; ++i)
            res += (i == idx) ? g1 : v[i].second;
        cout << res << '\n';
    }
    return 0;
}
