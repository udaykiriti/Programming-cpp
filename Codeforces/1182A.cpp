#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll n; cin >> n;
    if (n % 2 == 1)  cout << 0 << "\n";
    else cout << fixed << setprecision(0) << pow(2, n / 2) << "\n";
    return 0;
}
