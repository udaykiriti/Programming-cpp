#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;

        vector<int> pos;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) pos.push_back(i + 1);  // 1-based
        }

        if (pos.size() % 2 == 1) {
            cout << -1 << "\n";
            continue;
        }

        vector<pair<int,int>> ops;
        for (int i = 0; i < (int)pos.size(); i += 2) {
            ops.push_back({pos[i], pos[i+1]});
        }

        cout << ops.size() << "\n";
        for (auto &p : ops) {
            cout << p.first << " " << p.second << "\n";
        }
    }
    return 0;
}
