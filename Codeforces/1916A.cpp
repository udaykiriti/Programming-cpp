#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
using vii = vector<lli>;
#define endl '\n'
#define debug(x) cout << x <<endl

void solve() {
    lli n, k; cin >> n >> k;
    vii b(n);
    lli ml = 1ll;
    
    for(int i = 0; i < n; ++i) {
        cin >> b[i];
        ml *= b[i];
    }
    
    if (2023 % ml != 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << 2023 / ml << ' ';
        for(int i = 0; i < k - 1; ++i) {
            cout << 1 << ' ';
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
