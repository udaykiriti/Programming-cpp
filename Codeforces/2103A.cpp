/******************************
 *    author:  uday           *
 *    created: 28 10:28:44    *
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
   int n,x;
   cin >> n;
   vector<bool> vec(101,false);
   int ToT(0);
   for(int i=0;i<n;i++){
    cin>>x;
    if(!vec[x]){
        ToT++;
        vec[x] = true;
    }
   }
   cout<< ToT << '\n';
}

int main(){
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0); cin>>t;
    while (++tcase, t--) solve();
}