/**
 *    author:  uday
 *    created: 15 13:38:43
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

#define ll long long

void solve(){
    int n,b; cin>>n;
    ll res(0);
    vector<ll> vec;
    for(ll i=1;i<=n;i++){
        cin>>b;
        if(abs(b-i)!=0)
            res=__gcd(res,abs(b-i));
    } cout<< res <<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0);
    cin >> t;
    while (++tcase, t--) solve();
}