/******************************
 *    author:  uday           *
 *    created: 22 17:03:43    *
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
    long n; cin >> n;

    int min10 = INT_MAX;
    int min01 = INT_MAX;
    int min11 = INT_MAX;

    for (int i = 0; i < n; ++i) {
        int cost; string skill;
        cin >> cost >> skill;

        if (skill == "10") {
            min10 = min(min10, cost);
        } else if (skill == "01") {
            min01 = min(min01, cost);
        } else if (skill == "11") {
            min11 = min(min11, cost);
        }
    }

    int combined = (min10 != INT_MAX && min01 != INT_MAX) ? (min10 + min01) : INT_MAX;
    int result = min(min11, combined);

    cout << (result == INT_MAX ? -1 : result) << '\n';
}

int main(){
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0); cin>>t;
    while (++tcase, t--) solve();
}