/******************************
 *    author:  uday           *
 *    created: 26 10:04:40    *
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

int h,d,cnt;
ll cost;

bool check(int mid, int n) {
    int round = n % (mid + 1);
    int x = n / (mid + 1);

    cost = 1LL * round * (x + 1) * (x + 2) / 2
            + 1LL * (mid + 1 - round) * (x + 1) * x / 2;

    return cost <= (ll)h + mid - 1;
}

void solve() {
    cin >> h >> d;
    int l = 1, r = d;
    int ans = 0;

    if (h == 1) {
        h = 2;
    }
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid, d)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << d + ans << endl;
}


int main(){
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0); cin>>t;
    while (++tcase, t--) solve();
}
