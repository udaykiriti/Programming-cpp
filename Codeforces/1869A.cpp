#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve() {
    long n;  cin >> n;

    for (long p = 0; p < n; p++) {
        long x; 
        cin >> x;
    }

    if (n % 2) {
        cout << 4 << endl;
        cout << 2 << " " << n << endl;
        cout << 2 << " " << n << endl;
        cout << 1 << " " << 2 << endl;
        cout << 1 << " " << 2 << endl;
    } else {
        cout << 2 << endl;
        cout << 1 << " " << n << endl;
        cout << 1 << " " << n << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(0);
    long t; cin >> t;
    while (t--) solve();
    return 0;
}
