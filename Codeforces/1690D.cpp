#include <bits/stdc++.h>
using namespace std;
#define ll long long 

void solve() {
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    vector<ll> prefix_sum(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        prefix_sum[i] = prefix_sum[i - 1] + (s[i - 1] == 'W');
    ll result = LLONG_MAX;
    for (int i = k; i <= n; ++i)
        result = min(result, prefix_sum[i] - prefix_sum[i - k]);
    cout << result << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}