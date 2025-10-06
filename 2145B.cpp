#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define FOR(i, a, b) for (int i = a; i < b; ++i)

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;

    if (n == k) {
        cout << string(n, '-') << endl;
        continue;
    }

    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (char c : s)
        if (c == '0') cnt0++;
        else if (c == '1') cnt1++;
        else cnt2++;

    string res(n, '?');

    FOR(i, 0, cnt0)
        res[i] = '-';

    FOR(i, 0, cnt1)
        res[n - 1 - i] = '-';

    FOR(i, 0, n)
        if (res[i] == '?' && i >= cnt0 + cnt2 && i < n - (cnt1 + cnt2))
            res[i] = '+';

    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t(1),tcase(0); cin >> t;
    while (tcase++,t--) solve();
    return 0;
}