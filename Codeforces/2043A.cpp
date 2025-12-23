#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef vector<int> vi;
using ll=long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        ll n, res = 1; cin >> n;
        while (n >= 4) n /= 4, res *= 2;
        cout << res << '\n';
    }
}