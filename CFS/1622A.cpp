/******************************
 *    author:  uday           *
 *    created: 26 12:14:29    *
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
    int l1, l2, l3;
    cin >> l1 >> l2 >> l3;

    int sum = l1 + l2 + l3;
    int maxLen = max({l1, l2, l3});

    if (maxLen == (sum - maxLen)) {
        cout << "YES" << endl;
        return;
    }

    if (l1 == l2)
        cout << ((l3 % 2 == 0) ? "YES" : "NO") << endl;
    else if (l2 == l3)
        cout << ((l1 % 2 == 0) ? "YES" : "NO") << endl;
    else if (l1 == l3)
        cout << ((l2 % 2 == 0) ? "YES" : "NO") << endl;
    else
        cout << "NO" << endl;
}

int main(){
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0); cin>>t;
    while (++tcase, t--) solve();
}