#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int x, n; cin >> x >> n;
        if (n % 2 == 0) cout << 0 << endl;
        else cout << x << endl;
    }
    return 0;
}