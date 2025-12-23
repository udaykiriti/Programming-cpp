#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    vector<int> freq(26, 0);

    for (char c : s) freq[c - 'a']++;
    for (char c : t) freq[c - 'a']--;

    bool ok = true;
    for (int c : freq) {
        if (c != 0) {
            ok = false;
            break;
        }
    }
    if(ok) cout << "YES" <<'\n';
    else cout << "NO" <<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
