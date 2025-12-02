/*
g++ -std=c++17 -Wall -Wextra -O2 -DLOCAL prac.cpp  -o prac 
./prac <in.txt> out.txt
*/
#undef _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define int_64 long long

void solve(){
  //soLuSHoNN hErE.........
  int_64 n,ans(0);
  cin >> n;
  for(int_64 i =5;i <= n;i*=5){
    ans += n/i;
  }
  cout << ans;
}

int main(){
     /*
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
     */
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0); //cin>>t;
    while (++tcase, t--) solve();
    return 0;
}