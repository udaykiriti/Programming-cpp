#include <bits/stdc++.h>
using namespace std;

long long ceil_div(long long a, long long b) {
    return (a % b ? (a / b) + 1 : (a / b));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        long long n, x, mx = 0, mn = 0, sum = 0;
        cin >> n >> x;
        vector<long long> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            mx += ceil_div(a[i], x);
        }
        
        mn = ceil_div(sum, x);
        cout << min(mn, mx) << " " << max(mn, mx) << endl;
    }
    return 0;
}
