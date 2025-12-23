#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

i64 lcm(i64 a, i64 b) {
    return a / __gcd(a, b) * b;
}

i64 Nsum(i64 n) {
    return (n * (n + 1)) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        i64 n, x, y; cin >> n >> x >> y;

        i64 lcm_xy = lcm(x, y);
        i64 a = n / x - n / lcm_xy;
        i64 b = n / y - n / lcm_xy;

        i64 ans = Nsum(n) - Nsum(n - a); 
        ans -= Nsum(b);         

        cout << ans << '\n';
    }

    return 0;
}
