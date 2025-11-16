
// g++ -std=c++17 new.cpp -o new
// ./new
//g++ -std=c++17 -Wall -Wextra -O2 s.cpp -o file-name 
//./file-name
#undef _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

void solve(){
   //soLuSHoNN hErE.........
   vector<int> vec(3);
   for(int i = 0 ;i < 3 ; i++) cin >> vec[i];
   sort(vec.begin(),vec.end());
   cout << (vec[2] - vec[0] >= 10 ? "check again" : "final " + to_string(vec[1]));
}

int main(){
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0); //cin>>t;
    while (++tcase, t--) solve();
}