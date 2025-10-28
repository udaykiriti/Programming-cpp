/******************************
 *    author:  -----          *
 *    created: 28 10:27:01    *
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
   int n,k;
   cin>>n>>k;
   unordered_set<int> s;
   int w(0);
   for(int i=0;i<n;i++){
    int x;
    cin>>x;
    if(x==k) w++;
    else s.insert(x);
   }
   int c = 0;
   for(int i=0;i<k;i++){
    if(!s.count(i)) ++c;
   }
   cout <<  (c > w ? c :w) << '\n';
}

int main(){
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0); cin>>t;
    while (++tcase, t--) solve();
}