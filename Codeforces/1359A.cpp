/******************************
 *    author:  uday           *
 *    created: 24 16:41:45    *
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
   int n,m,k; cin>>n>>m>>k;
   int cpl = n/k;
   int x = min(m,cpl);
   int rem = m-x;
   int y = (rem+(k-2))/(k-1);
   cout << x-y << endl;
}

int main(){
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0); cin>>t;
    while (++tcase, t--) solve();
}