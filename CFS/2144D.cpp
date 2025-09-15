#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int argc , char *argv[]){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;cin >> t;
    while (t--) {
        int n;ll y;
        cin >> n >> y;
        vector<int> a(n);
        int m = 0;
        for (int i = 0; i < n; ++i){
            cin >> a[i];
            if (a[i] > m)
                m = a[i];
        }
        vector<int> f(m + 1, 0);
        for (int v : a)
            f[v]++;
        vector<int> p(m + 1, 0);
        for (int i = 1; i <= m; ++i)
            p[i] = p[i - 1] + f[i];
        long long b = LLONG_MIN;
        for (int x = 2; x <= m + 1; ++x) {
            int mk = (m + x - 1) / x;
            long long s = 0;
            long long r = 0;
            for (int k = 1; k <= mk; ++k) {
                int L = (k - 1) * x + 1;
                int R = min(k * x, m);
                if (L > R)
                    continue;
                int z = p[R] - p[L - 1];
                if (!z)
                    continue;
                s += 1LL * k * z;
                if (k <= m)
                    r += min(z, f[k]);
            }
            long long pr = (long long)n - r;
            long long inc = s - y * pr;
            if (inc > b)
                b = inc;
        }
        cout << b << "\n";
    }
    return 0;
}
