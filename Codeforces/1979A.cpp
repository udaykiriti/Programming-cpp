/**
 *    author:  uday
 *    created: 15 16:12:22
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

#define pb push_back

void solve(){
    int n; cin>>n;
    vector<int>vec(n),res;
    for(auto &x : vec) cin>>x;
    for(int i=0;i<n-1;i++){
        res.pb(max(vec[i],vec[i+1]));
    }
    sort(res.begin(),res.end());
    cout <<  res[0] -1 << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0);
    cin >> t;
    while (++tcase, t--) solve();
}