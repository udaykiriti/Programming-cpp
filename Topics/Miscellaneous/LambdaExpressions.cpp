
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
   /*
   int x; //loCal VarIable

   auto c1 = [x](int y){return x * y > 55;}; // copy of the closure produced by the lambda
   auto c2 = c1;
   auto c3 = c2;
   vector<int> numbers = {1, 2, 3, 4, 5};
   for_each(numbers.begin(),numbers.end(),[](int n){
    cout << n * 2 << " ";
   });
   cout << endl;
   */
   int f = 3;
   auto mul = [f](int n){
    return n*fl=;
   };
   cout << mul(5) << '\n';
   return ;
}

int main(){
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0); //cin>>t;
    while (++tcase, t--) solve();
}