#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; char c;
    cin >> s >> c;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == c && i % 2 == 0) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}