#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve() {
    int n; string s;
    cin >> n >> s;

    int total_a = count(s.begin(), s.end(), 'a');
    int total_b = n - total_a;
    int diff = total_a - total_b;

    if (diff == 0) {
        cout << 0 << '\n';
        return;  
    }

    unordered_map<int, int> pos;  
    pos[0] = 0;

    vector<int> prefix(n + 1, 0);
    bool found = false;
    int min_len = n + 1;

    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + (s[i - 1] == 'a' ? 1 : -1);
        int target = prefix[i] - diff;

        if (pos.find(target) != pos.end()) {
            int len = i - pos[target];
            min_len = min(min_len, len);
            found = true;
        }

        if (pos.find(prefix[i]) == pos.end())
            pos[prefix[i]] = i; 
    }

    if (found && min_len != n + 1 && min_len != n) 
        cout << min_len << '\n';
    else
        cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t(1),tcase(0); cin >> t;
    while (tcase++,t--) solve();
    return 0;
}
