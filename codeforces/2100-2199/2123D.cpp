#include <bits/stdc++.h>
using namespace std;
using ll=long long; 
#define endl "\n"

void solve() {
    int n; ll k; cin >> n >> k;
    string s; cin >> s;
    int ones = 0;
    for (char c : s) 
        if (c == '1') 
            ones++;

    if (ones <= k) {
        cout << "Alice" << endl;
        return;
    }
    bool has_k_zeros = false;
    int zero_run = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            zero_run++;
        } else {
            zero_run = 0;
        }
        if (zero_run >= k) {
            has_k_zeros = true;
            break;
        }
    }

    if (has_k_zeros || (2 * k <= n)) 
        cout << "Bob" << endl;
    else 
        cout << "Alice" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}