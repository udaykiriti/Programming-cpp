/******************************
 *    author:  -----          *
 *    created: 19 11:26:50    *
 ******************************/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve() {
    ll n; cin >> n;
    string s; cin >> s;

    ll sqr = sqrt(n);
    if (sqr * sqr != n) {
        cout << "NO" << endl;
        return;
    }

    ll count1 = count(s.begin(), s.end(), '1');
    ll exp = sqr * 2 + (sqr - 2) * 2;

    if (count1 == exp)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    ll t(1),tcase(0); cin >> t;
    while (++tcase,t--) solve();
    return 0;
}
