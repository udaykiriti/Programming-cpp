/******************************
 *    author:  uday           *
 *    created: 27 00:35:57    *
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
    int a, b;
    cin >> a >> b;

    string s;
    cin >> s;

    int n = s.size();
    int i = 0;

    while (i < n / 2) {
        if (s[i] != '?' && s[n - i - 1] != '?') {
            if (s[i] != s[n - i - 1]) {
                cout << -1 << endl;
                return;
            }
        } else if (s[i] != '?') {
            s[n - i - 1] = s[i];
        } else if (s[n - i - 1] != '?') {
            s[i] = s[n - i - 1];
        }
        ++i;
        debug(s);
    }
    debug(s);
    int zeroCnt = count(s.begin(), s.end(), '0');
    int oneCnt = count(s.begin(), s.end(), '1');
    debug(zeroCnt,oneCnt);

    a -= zeroCnt;
    b -= oneCnt;
    debug(zeroCnt,oneCnt,a,b);
    if (a < 0 || b < 0) {
        cout << -1 << endl;
        return;
    }

    i = 0;
    while (i < n / 2) {
    if (s[i] == '?') {
        if (a > 1) {
            s[i] = s[n - i - 1] = '0';
            a -= 2;
        } else if (b > 1) {
            s[i] = s[n - i - 1] = '1';
            b -= 2;
        } else {
            cout << -1 << endl;
            return;
        }
    }
    ++i;
}

    debug(s);

    if (n % 2 == 1 && s[n/2] == '?') {
        if (a > 0) {
            s[n / 2] = '0';
            --a;
        } else if (b > 0) {
            s[n / 2] = '1';
            --b;
        }
        debug(a,b);
    }
    if (a != 0 || b != 0) {
        cout << -1 << endl;
        return;
    }
    cout << s << endl;
}

int main(){
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1), tcase(0); cin>>t;
    while (++tcase, t--) solve();
}