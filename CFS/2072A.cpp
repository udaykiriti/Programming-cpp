#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define ln "\n"
#define stop_sync ios::sync_with_stdio(false)
#define untie_ios cin.tie(nullptr)
#define GG return 0;

void solve() {
    int n, k, p; cin >> n >> k >> p;
    if (k < (-n * p) || k > (n * p)) {
        cout<<(-1);
    } else {
        int ans = abs(k);
        cout<<((ans / p) + (ans % p ? 1 : 0));
    }
}

int main() {
    stop_sync; untie_ios;
    int t; cin>>t;
    while(t--) solve();
    GG;
}