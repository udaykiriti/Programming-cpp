#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n; cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];

    vector<vector<ll>> dp(n + 1, vector<ll>(3, INT_MAX));

    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;

    for (ll i = 1; i <= n; i++) {
        dp[i][0] = 1 + min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});

        if (a[i - 1] == 1 || a[i - 1] == 3) {
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
        }
        if (a[i - 1] == 2 || a[i - 1] == 3) {
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
        }
    }

    cout << min({dp[n][0], dp[n][1], dp[n][2]}) << endl;

    return 0;
}
