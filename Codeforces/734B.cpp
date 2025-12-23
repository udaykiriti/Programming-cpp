/******************************
 *    author:  uday           *
 *    created: 27 19:39:14    *
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
   ll k2,k3,k5,k6;
   cin >> k2 >> k3 >> k5 >> k6;
   ll a = min(k2,k5);
   ll b = min(a,k6);
   ll x = b * 256;
   ll d = k2-b;
   if(d > 0){
        ll c = min(d,k3);
        ll y = c*32;
        cout << x+y << endl;
   }
   else{
    cout<<x<<endl;
   }
}

int main(){
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0); //cin>>t;
    while (++tcase, t--) solve();
}