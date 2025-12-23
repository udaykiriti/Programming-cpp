/******************************
 *    author:  uday           *
 *    created: 18 11:50:39    *
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
   ll n; cin>>n;
   string str; cin>>str;
   map<ll,ll> m;
   ll sum(0),res(0);
   m[1]=1;
   for(int i =0;i<n;i++){
    sum+= str[i]-'0';
    if(m.find(sum-i) != m.end())
        res+=m[sum-i];
    m[sum-i]++;
   }
   cout<<res<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0); cin>>t;
    while (++tcase, t--) solve();
}