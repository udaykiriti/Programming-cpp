/******************************
 *    author:  -----          *
 *    created: 27 19:35:36    *
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
   ll n,k;
   cin >> n>>k;
   if(n>=k){
    cout << (k-1)/2 << endl;
   }
   else{
    if(2*n-1 < k){
        cout<<"0"<<endl;
    }else{
        cout<<n-k/2<<endl;
    }
   }
}

int main(){
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0); //cin>>t;
    while (++tcase, t--) solve();
}