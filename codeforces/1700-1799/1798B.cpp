#include <bits/stdc++.h>
using namespace std;

int main(int argc , char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    const long N = 50007;
    long t; cin >> t;
    while (t--) {
        long m;
        cin >> m;
        vector<vector<long>> v(m);
        for (long p = 0; p < m; p++) {
            long n; cin >> n;
            v[p].resize(n);
            for (long u = 0; u < n; u++) cin >> v[p][u];
        }
        vector<bool> f(N, false);
        vector<long> w(m, -1);
        for (long p = m - 1; p >= 0; p--) {
            for (long u = 0; u < v[p].size(); u++) {
                long x = v[p][u];
                if (!f[x] && w[p] < 0) w[p] = x;
                f[x] = true;
            }
            if (w[p] < 0) break;
        }
        if (w[0] < 0) cout << "-1\n";
        else { for (long p = 0; p < m; p++) cout << w[p] << " "; cout << "\n"; }
    }
    return 0;
}
