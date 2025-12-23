#include <bits/stdc++.h>
using namespace std;
using i64 = long long int;
using vi = vector<int>;
using vii = vector<i64>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vii a(n);
        for (auto &i : a) cin >> i;
        sort(a.begin(), a.end());
        
        i64 ans = 0;
        if (n >= 2) 
            ans = a[0] + a[1] - 1;
        else 
            ans = a[0];

        for (int i = 2; i < n; ++i) {
            ans = a[i] + ans - 1;
        }
        cout << ans << endl;
    }
    return 0;
}
