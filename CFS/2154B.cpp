/******************************
 *    author:  uday           *
 *    created: 19 21:39:08    *
 ******************************/

// g++ -std=c++17 new.cpp -o new
// ./new
#undef _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define vi vector<int>
#define FOR(i,a,b) for(int i=a;i<b;i++)

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

void solve() {
    //Solution here........
    int n; cin >> n;
    vector<ll> vec(n);
    for (ll &x : vec) cin >> x;

    vector<ll> pre(n);
    pre[0] = vec[0];
    FOR (p , 1 , n)
        pre[p] = max(pre[p - 1], vec[p]);

    ll res(0);
    for (int i = 0; i < n; i += 2) {
        ll lim = (i == 0 ? pre[1] : pre[i - 1]) - 1;
        if (vec[i] > lim)
            res += vec[i] - lim;
    }
    cout << res << endl;
}

int main(){
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0); cin>>t;
    while (++tcase, t--) solve();
}