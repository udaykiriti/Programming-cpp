#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)

void solve() {
    int p; cin >> p; 
    vector<int> q(p);
    FOR(i, 0, p) cin >> q[i];       

    int r (0);
    vector<int> s(p + 1, 0);

    for (auto x : q) {
        if (!s[x]) {
            s[x] = 1;
            r++;
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();
}
