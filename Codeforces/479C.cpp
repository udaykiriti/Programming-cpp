/******************************
 *    author:  uday           *
 *    created: 21 11:01:05    *
 ******************************/

// g++ -std=c++17 new.cpp -o new
// ./new
#undef _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define vi vector<int>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define vpii vector<pair<int, int> >

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

void solve() {
    //Solution here.....
    int n; cin >> n;

    vpii date(n);

    FOR(i, 0, n) {
        cin >> date[i].first >> date[i].second;
    }

    sort(date.begin(), date.end());

    int currDate = -1;

    FOR(i, 0, n) {
        currDate = (date[i].second >= currDate) ? date[i].second : date[i].first;
    }

    cout << currDate;
}

int main(){
//freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0); //cin>>t;
    while (++tcase, t--) solve();
}