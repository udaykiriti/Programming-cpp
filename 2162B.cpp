#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define vi vector<int>

bool ispal(const string &str) {
    int l = 0, r = str.size() - 1;
    while (l < r) {
        if (str[l] != str[r]) return false;
        ++l; --r;
    }
    return true;
}

void solve() {
    int n; string str;
    cin >> n >> str;
    int limit = 1 << n;

    FOR(m,0,limit) {
        string p = "", an = "";
        vi vec;

        FOR(i, 0, n) {
            if (m & (1 << i)) {
                p.pb(str[i]);
                vec.pb(i + 1);  
            } else {
                an.pb(str[i]);
            }
        }

        bool ok(true);
        FOR (i ,1,(int)p.size()) {
            if (p[i] < p[i - 1]) {
                ok = false;
                break;
            }
        }

        if (!ok) continue;
        if (!ispal(an)) continue;

        cout << vec.size() << endl;
        if (!vec.empty()) {
            FOR (i,0, vec.size()) {
                if (i > 0) cout << ' ';
                cout << vec[i];
            }
            cout << endl;
        } else {
            cout << endl;
        }
        return;
    }
    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t(1),tcase(0); cin >> t;
    while (++tcase,t--) solve();
    return 0;
}
