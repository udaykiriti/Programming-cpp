/******************************
 *    author:  uday           *
 *    created: 24 20:26:33    *
 ******************************/
/*
g++ -std=c++17 new.cpp -o new
 ./new
g++ -std=c++17 -Wall -Wextra -O2 s.cpp -o file-name 
./file-name
*/
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
   int s; cin>>s;
   cout << (s-1)/2 << endl;
}

int main(){
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0); cin>>t;
    while (++tcase, t--) solve();
}