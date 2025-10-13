#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main() {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    vector<vector<ll>> dp(2, vector<ll>(n + 1, 0));

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    for (int i = 1; i <= n; i++) {
        dp[0][i] = max(1LL * a[i] + dp[1][i - 1], dp[0][i - 1]);
        dp[1][i] = max(1LL * b[i] + dp[0][i - 1], dp[1][i - 1]);
    }
    cout << max(dp[0][n], dp[1][n]) << endl;

    return 0;
}