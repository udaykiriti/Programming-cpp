/******************************
 *    author:  uday           *
 *    created: 21 11:16:19    *
 ******************************/

// g++ -std=c++17 new.cpp -o new
// ./new
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
    long b, c, h; cin >> b >> c >> h;
    c += h;
    long ans = 0;
    
    if (b >= c + 1) ans = 2 * c + 1;
    else ans = 2 * b - 1;
    cout << ans << endl;
}

int main(){
//freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0); cin>>t;
    while (++tcase, t--) solve();
}