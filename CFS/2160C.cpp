#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

bool isok(uint32_t z) {
    int l = 32 - __builtin_clz(z);
    for (int p = 0; p < l / 2; ++p)
        if (((z >> p) & 1) != ((z >> (l - 1 - p)) & 1))
            return false;
    return l % 2 == 0 || ((z >> (l / 2)) & 1) == 0;
}

void solve() {
    uint32_t n; cin >> n;
    if (n) n >>= __builtin_ctz(n);
    cout << (isok(n) ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0); cin >> t;
    while (++tcase, t--) solve();
    return 0;
}