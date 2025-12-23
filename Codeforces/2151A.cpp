/******************************
 *    author:  uday           *
 *    created: 28 10:14:32    *
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
    long n, m;
    cin >> n >> m;
    vector<long> vec(m);
    for (long i = 0; i < m; i++) {
        cin >> vec[i];
    }

    long res = n - vec.back() + 1;
    for (long p = 1; p < m; p++) {
        if (vec[p] == 1) {
            res = 1;
            break;
        }
    }

    cout << res << "\n";

}

int main(){
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0); cin>>t;
    while (++tcase, t--) solve();
}