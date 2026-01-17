#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        ll a, b; cin >> a >> b;
        cout << (a == 0 ? 1 : a + 2 * b + 1) << '\n';
    }
    return 0;
}
