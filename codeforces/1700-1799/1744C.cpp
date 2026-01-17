#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll t; cin >> t;
    while (t--) {
        ll n; char c; string s; 
        cin >> n >> c >> s;
        s += s;
        vector<ll> g_pos;
        for (ll i = 0; i < s.size(); ++i)
            if (s[i] == 'g')
                g_pos.push_back(i);
        ll ans = 0;

        for (ll i = 0; i < n; ++i)
            if (s[i] == c) {
                auto it = lower_bound(g_pos.begin(), g_pos.end(), i);
                if (it != g_pos.end())
                    ans = max(ans, *it - i);
            }

        cout << ans << '\n';
    }
    return 0;
}
