#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;  cin >> t;
    while (t--)
    {
        int n, i; cin >> n;
        int a[n];
        vector<int> dp(n);
        for (auto &u : a) cin >> u;
        for (i = n - 1; i >= 0; i--){
            dp[i] = a[i];
            int j = i + a[i];
            if (j < n)
                dp[i] += dp[j];
        }
        cout << *max_element(dp.begin(), dp.end()) << endl;
    }
    return 0;
}
