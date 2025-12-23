/******************************
 *    author:  uday           *
 *    created: 16 13:31:25    *
 ******************************/

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
   //solution here.........
   int n,a,b; cin>>n>>a>>b;
   if(n==a and a==b) cout<<"YES"<<endl;
   else{
    if(n-(a+b) >= 2) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
   }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0);
    cin >> t;
    while (++tcase, t--) solve();
}