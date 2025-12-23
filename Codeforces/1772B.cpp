/******************************
 *    author:  uday           *
 *    created: 17 08:15:44    *
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
   int a,b,c,d; cin>>a>>b>>c>>d;
   if((b>a and d>c and c>a and d>b)||(a>c and b>d and d>c and b>a)
   ||(c>d and a>b and a>c and b>d)||(d>b and c>a and c>d and a>b)){
    cout<<"YES"<<endl;
   }
   else{
    cout<<"NO"<<endl;
   }  
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0);
    cin >> t;
    while (++tcase, t--) solve();
}