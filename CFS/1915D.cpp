#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n;
    string s, ans = "";
    cin >> n >> s;

    reverse(s.begin(), s.end());

    for (int i = 0; i < n; i++) {
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e';
        };

        if (i + 2 < n && !isVowel(s[i]) && isVowel(s[i + 1]) && !isVowel(s[i + 2])) {
            ans += s[i];
            ans += s[i + 1];
            ans += s[i + 2];
            ans += '.';
            i += 2;
        } else if (i + 1 < n) {
            ans += s[i];
            ans += s[i + 1];
            ans += '.';
            i += 1;
        } else {
            ans += s[i]; 
        }
    }

    reverse(ans.begin(), ans.end());
    if (!ans.empty() && ans.front() == '.')
        ans.erase(ans.begin());

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T(1); cin >> T;
    while (T--) solve();
    return 0;
}
