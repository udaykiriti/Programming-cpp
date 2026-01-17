#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t(1); cin >> t;
    while (t--) {
        int n, a, b; cin >> n >> a >> b;
        cout << ((a + b) % 2 ? "NO\n" : "YES\n");
    }
    return 0;
}
