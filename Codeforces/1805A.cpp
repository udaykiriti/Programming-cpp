#include <bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;

void solve() {
    ll n; cin >> n;

    ll arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    ll res = 0;
    for (int i = 0; i < n; i++)
        res = (arr[i] ^ res);

    if (res == 0)
        cout << 0 << endl;
    else if (n & 1)
        cout << res << endl;
    else
        cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll t(1); cin >> t;
    while (t--) solve();
}
