#include <bits/stdc++.h>
using namespace std;

using i64 = long long int;
using vii = vector<i64>;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vii a(n);
        for (auto &i : a) cin >> i;

        vii mx(n), pf(n);
        for (int i = 0; i < n; ++i) {
            mx[i] = (i > 0 ? max(a[i], mx[i - 1]) : a[i]);
            pf[i] = a[i] + (i > 0 ? pf[i - 1] : 0);
        }

        while (m--) {
            int Qi;  cin >> Qi;

            int l = -1, r = n;
            while (r > l + 1) {
                int mid = l + (r - l) / 2;
                if (mx[mid] <= Qi) l = mid;
                else r = mid;
            }

            if (r == 0) cout << 0 << ' ';
            else cout << pf[r - 1] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
