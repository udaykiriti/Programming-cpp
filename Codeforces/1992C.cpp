/**
 *    author:  uday
 *    created: 15 10:26:00
 **/

// g++ -std=c++17 -DLOCAL new.cpp -o new
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
    int n,m,k; cin>>n>>m>>k;
    vector<int>per;
    for(int i=n;i>=k;--i)
        per.push_back(i);
    for(int i=k-1;i>m;i--)
        per.push_back(i);
    for(int i=1;i<=m;i++)
        per.push_back(i);
    for(int i=0;i<n;i++)
        cout<<per[i]<<" ";
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0);
    cin >> t;
    while (++tcase, t--) solve();
}