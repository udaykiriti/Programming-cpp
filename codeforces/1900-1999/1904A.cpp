#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int64 a, b;
        cin >> a >> b;
        int64 xK, yK, xQ, yQ;
        cin >> xK >> yK;
        cin >> xQ >> yQ;
        
        vector<pair<int64,int64>> offs;
        offs.reserve(8);
        int64 dxs[2] = {a, b};
        int64 dys[2] = {b, a};
        for (int k = 0; k < 2; ++k) {
            int64 dx = dxs[k];
            int64 dy = dys[k];
            for (int sx : { -1, 1 }) {
                for (int sy : { -1, 1 }) {
                    offs.emplace_back(sx * dx, sy * dy);
                }
            }
        }
        sort(offs.begin(), offs.end());
        offs.erase(unique(offs.begin(), offs.end()), offs.end());
        
        int ans = 0;
        for (auto [ox, oy] : offs) {
            int64 px = xK + ox;
            int64 py = yK + oy;
            int64 dxq = llabs(px - xQ);
            int64 dyq = llabs(py - yQ);
            if ((dxq == a && dyq == b) || (dxq == b && dyq == a)) ++ans;
        }
        cout << ans << '\n';
    }
    return 0;
}
