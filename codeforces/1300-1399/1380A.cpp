#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];

    for (int j = 1; j < n - 1; ++j)
        if (p[j-1] < p[j] && p[j] > p[j+1]) {
            cout << "YES\n" << j << " " << j+1 << " " << j+2 << endl;
            return;
        }

    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
