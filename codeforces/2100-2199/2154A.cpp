/******************************
 *    author:  -----          *
 *    created: 19 21:35:27    *
 ******************************/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i,a,b) for(int i=a;i<b;i++)

void solve() {
    int n, k, res(0), lt(-1e9);
    cin >> n >> k;
    string str; cin >> str;
    FOR (p ,0, n) {
        if (str[p] == '1') {
            if (p - k + 1 > lt) ++res;
            lt = p;
        }
    }
    cout << res << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1),tcase(0); cin>>t;
    while(++tcase,t--) solve();
    return 0;
}