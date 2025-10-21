/******************************
 *    author:  -----          *
 *    created: 22 03:29:55    *
 ******************************/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using i64 = long long int;

void solve() {
    i64 x, y, k;
    cin >> x >> y >> k;
    i64 res = 0;
    if (x > y) {
        res = (x + k - 1) / k;
        res += max((y + k - 1) / k, res - 1);
    } else {
        res = (y + k - 1) / k;
        res += max(res, (x + k - 1) / k);
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1),tcase(0); cin >> t;
    while (++tcase,t--) solve();
    return 0;
}