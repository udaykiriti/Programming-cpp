#include <bits/stdc++.h>
using namespace std;

#define lli long long
#define endl '\n'

__int128 binpower(lli base, lli exp) {
    __int128 result = 1;
    __int128 b = base;
    while (exp > 0) {
        if (exp & 1)
            result *= b;
        b *= b;
        exp >>= 1;
    }
    return result;
}

void solve() {
    lli n, c; cin >> n >> c;
    vector<lli> vec(n);
    for (auto &x : vec) cin >> x;

    lli l = 0, r = 1e10;
    while (r > l + 1) {
        lli midw = l + (r - l) / 2;
        __int128 sum = 0;
        bool ok = true;

        for (auto x : vec) {
            __int128 val = binpower(x + 2 * midw, 2);
            if (sum > c - val) {
                ok = false;
                break;
            }
            sum += val;
        }
        if (ok && sum <= c) l = midw;
        else r = midw;
    }

    cout << l << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
