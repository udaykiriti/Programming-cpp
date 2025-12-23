#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;
int main(int argc , char *argv[]){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        vector<array<ll, 2>> dp(n + 1);
        dp[1][0] = 1;
        dp[1][1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i][0] = dp[i][1] = 0;
            for (int p = 0; p < 2; p++){
                int Aprev = p ? b[i - 1] : a[i - 1];
                int Bprev = p ? a[i - 1] : b[i - 1];
                for (int c = 0; c < 2; c++) {
                    int Acur = c ? b[i] : a[i];
                    int Bcur = c ? a[i] : b[i];
                    if (Aprev <= Acur && Bprev <= Bcur)
                        dp[i][c] = (dp[i][c] + dp[i - 1][p]) % MOD;
                }
            }
        }
        ll ans = (dp[n][0] + dp[n][1]) % MOD;
        cout << ans << "\n";
    }
    return 0;
}
