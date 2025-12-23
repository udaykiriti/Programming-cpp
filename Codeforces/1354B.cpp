#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int n = s.size();
    int ans = INT_MAX;

    vector<int> last_pos(3, -1);

    for (int i = 0; i < n; i++) {
        last_pos[s[i] - '1'] = i;
        if (last_pos[0] != -1 && last_pos[1] != -1 && last_pos[2] != -1) {
            int mn = min({last_pos[0], last_pos[1], last_pos[2]});
            int mx = max({last_pos[0], last_pos[1], last_pos[2]});
            ans = min(ans, mx - mn + 1);
        }
    }

    cout << (ans == INT_MAX ? 0 : ans) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
