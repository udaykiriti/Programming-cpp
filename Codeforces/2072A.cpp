#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, k, p;
    cin >> t;
    while (t--) {
        cin >> n >> k >> p;
        if (k < -n * p || k > n * p) cout << -1 << endl;
        else cout << (k == 0 ? 0 : (abs(k) + p - 1) / p) << endl;
    }
    return 0;
}
