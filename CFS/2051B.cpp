#include <bits/stdc++.h>
using namespace std;
#define ln "\n"

const int MOD = 1e9 + 7;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--){
        int n, a, b, c; cin >> n >> a >> b >> c;
        int ans = 3 * (n / (a + b + c));
        n %= (a + b + c);

        if (n > 0) {
            ++ans;
            n -= a;
        }
        if (n > 0) {
            ++ans;
            n -= b;
        }
        if (n > 0) {
            ++ans;
            n -= c;
        }
        cout << ans << ln;
    } return 0;
}
