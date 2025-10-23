/******************************
 *    author:  uday           *
 *    created: 22 17:11:32    *
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
    long n; cin>>n;
    long z(0), neg(0);
    for(long p = 0; p < n; p++){
        long x; cin>>x;
        z += (!x);
        neg += (x < 0);
    }
    cout<<(z + 2 * (neg % 2))<<endl;
}

int main(){
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0); cin>>t;
    while (++tcase, t--) solve();
}