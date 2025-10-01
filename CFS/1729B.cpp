#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    string ans;
    for (int i = n - 1; i >= 0;) {
        if (s[i] == '0') {
            int num = stoi(s.substr(i - 2, 2));
            ans += char(96 + num);
            i -= 3;
        } else {
            ans += char(96 + (s[i] - '0'));
            i--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
