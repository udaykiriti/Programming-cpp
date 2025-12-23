/******************************
 *    author:  -----          *
 *    created: 24 21:01:21    *
 ******************************/

#undef _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define vi vector<int>

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

void solve(){
   //solution here.........
    int n, m; cin >> n >> m;
    string str; cin >> str;
    vector<ll> vec(m);
    for (auto &x : vec) cin >> x;

    bool ok = std::count(str.begin(), str.end(), 'B') > 0;

    for (int p = 0; p < m; p++) {
        ll x = vec[p];
        if (!ok) {
            cout << x << endl;
            continue;
        }
        int pl(0); ll res(0);
        while (x > 0) {
            if (str[pl] == 'B') {
                x >>= 1;
                res++; pl++;
                if (pl == n) {
                    pl = 0;
                }
            } else {
                int pre = pl;
                int l(0);
                while (str[pre] == 'A') {
                    l++; pre++;
                    if (pre == n) pre = 0;
                }
                if (x > l) {
                    x   = x-l;
                    res = res+ l;
                    pl  = pre;
                } else {
                    res = res+ x;
                    x = 0;
                    break;
                }
            }
        }
        cout << res << endl;
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0); cin>>t;
    while (++tcase, t--) solve();
    return 0;
}
