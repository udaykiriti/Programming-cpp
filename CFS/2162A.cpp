/******************************
 *    author:  uday           *
 *    created: 17 20:39:03    *
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
   int n; cin>>n;
   vi vec(n);
   for(auto &x : vec) cin>>x;
   int p = *max_element(vec.begin(),vec.end());
   cout<<p<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0); cin>>t;
    while (++tcase, t--) solve();
}