/**
 *    author:  uday
 *    created: 15 16:24:04
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
    string s; cin>>s;
    int p(0),m(0);
    for(int i=0;i<n;i++){
        if(s[i]=='+') p++;
        else m++;
    }
    cout<< abs(p-m) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0);
    cin >> t;
    while (++tcase, t--) solve();
}