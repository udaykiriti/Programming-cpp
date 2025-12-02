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

struct Mex {
    int mex = 0;
    set<int> elements;

    void add(int x) {
        if ( x < mex ) return;
        if ( elements.find(x) != elements.end() ) return;

        elements.insert(x);
        if ( x != mex ) return;

        while (*elements.begin() == mex) {
            elements.erase(elements.begin());
            mex++;
        }
    }
    
};

Mex mexes[100][100];

void solve(){
  //soLuSHoNN hErE.........
  int n;
  cin >> n;
 // vector<vector<int>> mex(n,vector<int>(n));
 int mex[n][n];
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ; j++){
      int mex = mexes[i][j].mex;
      cout << mex << ' ';
      for(int k = 0 ; k < n ; k++){
        mexes[i][k].add(mex);
        mexes[k][j].add(mex);
      }
    }
    cout << '\n';
  }
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
