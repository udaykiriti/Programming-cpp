/**
 *    author:  uday
 *    created: 15 16:03:50
 **/

// g++ -std=c++17 new.cpp -o new
// ./new
#undef _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

void solve(){
    int n; cin>>n;
    cout<< 2*n <<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0);
    cin >> t;
    while (++tcase, t--) solve();
}