/******************************
 *    author:  uday           *
 *    created: 24 21:08:18    *
 ******************************/

// g++ -std=c++17 new.cpp -o new
// ./new
//g++ -std=c++17 -Wall -Wextra -O2 s.cpp -o file-name 
//./file-name
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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin>>x;

    vector<int> freq(n + 1, 0);
    for (int x : a)
        freq[x]++;
    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        pref[i] = pref[i - 1] + freq[i];

    int ans = 1;
    for (int g = n; g >= 1; --g)
    {
        int upto = min(n, 4 * g - 1);
        int tot = (upto >= 1 ? pref[upto] : 0);
        int mulcnt = 0;
        if (g <= n)
            mulcnt += freq[g];
        if (2 * g <= n)
            mulcnt += freq[2 * g];
        if (3 * g <= n)
            mulcnt += freq[3 * g];
        int bad = tot - mulcnt;
        if (bad <= k)
        {
            ans = g;
            break;
        }
    }
    cout << ans << endl;
}

int main(){
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0); cin>>t;
    while (++tcase, t--) solve();
}