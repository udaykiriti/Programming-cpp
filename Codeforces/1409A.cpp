#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORk(i, a, b, k) for (int i = (a); i <= (b); i += (k))
#define RFOR(i, a, b) for (int i = (a); i >= (b); i--)
#define RFORK(i, a, b, k) for (int i = (a); i >= (b); i -= (k))

void solve() {
    int a, b; cin >> a >> b;
    int diff = abs(a - b);
    int moves = diff / 10 + (diff % 10 != 0);
    cout << moves << endl;
}

int main() {
    FastIO();
    int t ; cin >> t;
    while (t--) solve();
    return 0;
}
